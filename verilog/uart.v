//parameter ClkFrequency = 12000000
//parameter Baud = 3000000
// 8 data bits, 1 stop bit, no parity

module uart(
    input wire CLK,
    input wire RX,
    input wire [7:0] TXbuffer,
    input wire TXstart,

    output wire TX,
    output reg [7:0] RXbuffer = 0,
    output reg RXready = 0,
    output wire TXbusy
  );

  parameter CLOCK_DIVISOR = 2; // 2 ^ CLOCK_DIVISOR

  // TRANSMITTER

  reg [CLOCK_DIVISOR:0] baudAcc = 0;
  wire baudTick = baudAcc[CLOCK_DIVISOR];

  reg [3:0] TXstate = 0;
  wire TXready = (TXstate==0);
  assign TXbusy = ~TXready;

  reg [7:0] TXshift = 0;

  always @(negedge CLK) begin

    if(TXready & TXstart) TXshift <= TXbuffer;
    else if(TXstate[3] & baudTick) TXshift <= (TXshift >> 1);

    if (TXstate == 4'b0000) baudAcc <= 0;
    else baudAcc <= baudAcc[CLOCK_DIVISOR - 1:0] + 1'b1;

    case(TXstate)
      4'b0000: if(TXstart)  TXstate <= 4'b0100;
      4'b0100: if(baudTick) TXstate <= 4'b1000; // start bit
      4'b1000: if(baudTick) TXstate <= 4'b1001; // bit 0
      4'b1001: if(baudTick) TXstate <= 4'b1010; // bit 1
      4'b1010: if(baudTick) TXstate <= 4'b1011; // bit 2
      4'b1011: if(baudTick) TXstate <= 4'b1100; // bit 3
      4'b1100: if(baudTick) TXstate <= 4'b1101; // bit 4
      4'b1101: if(baudTick) TXstate <= 4'b1110; // bit 5
      4'b1110: if(baudTick) TXstate <= 4'b1111; // bit 6
      4'b1111: if(baudTick) TXstate <= 4'b0001; // bit 7
      4'b0001: if(baudTick) TXstate <= 4'b0000; // stop bit
      default: if(baudTick) TXstate <= 4'b0000;
    endcase
  end

  assign TX = (TXstate < 4) | (TXstate[3] & TXshift[0]);

  // RECIEVER

  // Oversampling x 4 (i.e. every clock cycle)
  // Surprisingly reliable

  reg [3:0] RXstate = 0;
  reg [CLOCK_DIVISOR:0] gap = 0;

  wire nextBit = gap[CLOCK_DIVISOR];

  always @(negedge CLK) begin

    case (RXstate)
      4'b0000: if (~RX) RXstate <= 4'b1000;     // start bit found
      4'b1000: if (nextBit) RXstate <= 4'b1001; // bit 0
      4'b1001: if (nextBit) RXstate <= 4'b1010; // bit 1
      4'b1010: if (nextBit) RXstate <= 4'b1011; // bit 2
      4'b1011: if (nextBit) RXstate <= 4'b1100; // bit 3
      4'b1100: if (nextBit) RXstate <= 4'b1101; // bit 4
      4'b1101: if (nextBit) RXstate <= 4'b1110; // bit 5
      4'b1110: if (nextBit) RXstate <= 4'b1111; // bit 6
      4'b1111: if (nextBit) RXstate <= 4'b0001; // bit 7
      4'b0001: if (nextBit) RXstate <= 4'b0000; // stop bit
      default: RXstate <= 4'b0000;
    endcase

    if (RXstate == 4'b0000) begin
      gap <= 0;
    end else gap <= gap[CLOCK_DIVISOR - 1:0] + 1'b1;

    if (nextBit && RXstate[3]) RXbuffer <= {RX, RXbuffer[7:1]};
    RXready <= (nextBit && RXstate == 4'b0001);
  end

endmodule
