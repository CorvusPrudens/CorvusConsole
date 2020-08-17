//verilator lint_off UNUSED

`timescale 1ns/100ps
`default_nettype none

`include "uart.v"
`include "alu.v"

module top(
    input wire CLK,

    input wire RX,
    output wire TX,

    // output wire GPIO0,
    // output wire GPIO1,
    // output wire GPIO2,
    output wire GPIO3,
    output wire GPIO9,
    output wire GPIO11
  );

  // UART communication
  wire [7:0] RXbuffer;
  reg [7:0] TXbuffer = 0;
  reg TXstart = 0;
  wire RXready;
  wire TXbusy;

  uart FTDI(
      .CLK(CLK),
      .RX(RX),
      .TXbuffer(TXbuffer),
      .TXstart(TXstart),
      .TX(TX),
      .RXbuffer(RXbuffer),
      .RXready(RXready),
      .TXbusy(TXbusy)
    );


  /* The typical bus setup will look like this:
  reg [3:0] busState = 4'h0;

  reg [15:0] bus = 16'h00;
  wire [15:0] instanceOut;

  mod instance(
    .busIn(bus),
    .busOut(instanceOut)
  )

  always @(*) begin
    case (busState)
      4'h0: bus = instanceOut;
      4'h1: bus = instanceOut;
      4'h2: bus = instanceOut;
      4'h3: bus = instanceOut;
      etc...
    endcase
  end
  */

  // bus
  // any gpio and such should be memory mapped
  wire [15:0] aluOut; // these are all the modules
  wire [15:0] ramOut; // i'll need to design
  wire [15:0] romOut;
  wire [15:0] gpuOut;
  wire [15:0] apuOut;
  wire [15:0] ctrlOut;
  wire [15:0] clkOut;

  reg [3:0] busState = 4'h8;
  reg [15:0] bus = 16'h00;

  always @(*) begin
    case (busState)
      4'h0: bus = 16'h00;
      4'h1: bus = aluOut;
      4'h2: bus = ramOut;
      4'h3: bus = romOut;
      4'h4: bus = gpuOut;
      4'h5: bus = apuOut;
      4'h6: bus = ctrlOut;
      4'h7: bus = clkOut;
      4'h8: bus = RXbuffer; // for debug! (?)
      default: bus = 16'h00;
    endcase
  end



  // ALU
  reg aluRead = 1'b0;
  reg [15:0] din;
  wire [15:0] dout;
  reg [2:0] a = 3'b000;
  reg [2:0] b = 3'b001;
  reg [2:0] y = 0;
  reg [5:0] operation = 6'h0;
  reg [3:0] params = 4'h0;
  //wire [15:0] res;
  wire overflow;

  alu ALU(
      .CLK(CLK),
      .readBus(aluRead),
      .din(bus),
      .dout(ramOut),
      .operandIndex1(a),
      .operandIndex2(b),
      .resultsIndex(y),
      .operation(operation),
      .params(params),
      .overflow(overflow)
    );

  reg [3:0] testState = 0;
  reg [24:0] clkdiv = 0;

  always @(posedge CLK) begin

    clkdiv <= clkdiv + 1'b1;
    // testState <= testState + 1'b1;
    //
    // if (clkdiv[3:0] == 4'd15) begin
    //   params <= params + 1'b1;
    //   a <= a + 1'b1;
    //   b <= b + 1'b1;
    //   y <= y + 1'b1;
    //   TXstart <= 1'b1;
    //   operation <= operation + 1'b1;
    //   case (clkdiv[7:4]) // forcing icecube to synthesize
    //     4'd0: TXbuffer <= ALU.r0[7:0];
    //     4'd1: TXbuffer <= ALU.r1[7:0];
    //     4'd2: TXbuffer <= ALU.r2[7:0];
    //     4'd3: TXbuffer <= ALU.r3[7:0];
    //     4'd4: TXbuffer <= ALU.r4[7:0];
    //     4'd5: TXbuffer <= ALU.r5[7:0];
    //     4'd6: TXbuffer <= ALU.r6[7:0];
    //     4'd7: TXbuffer <= ALU.r7[7:0];
    //     4'd8: TXbuffer <= ALU.r0[15:8];
    //     4'd9: TXbuffer <= ALU.r1[15:8];
    //     4'd10: TXbuffer <= ALU.r2[15:8];
    //     4'd11: TXbuffer <= ALU.r3[15:8];
    //     4'd12: TXbuffer <= ALU.r4[15:8];
    //     4'd13: TXbuffer <= ALU.r5[15:8];
    //     4'd14: TXbuffer <= ALU.r6[15:8];
    //     4'd15: TXbuffer <= ALU.r7[15:8];
    //   endcase
    //   // a <= 0;
    // end else TXstart <= 1'b0;

    case (testState)
      4'd0:
        begin
          TXstart <= 1'b0;
          if (RXready) begin
            operation <= RXbuffer[5:0];
            testState <= 4'd8;
          end
        end
      4'd8:
        begin
          if (RXready) begin
            params <= RXbuffer[3:0];
            testState <= 4'd9;
          end
        end
      4'd9:
        begin
          if (RXready) begin
            a <= RXbuffer[2:0];
            testState <= 4'd10;
          end
        end
      4'd10:
        begin
          if (RXready) begin
            b <= RXbuffer[2:0];
            testState <= 4'd11;
          end
        end
      4'd11:
        begin
          if (RXready) begin
            y <= RXbuffer[2:0];
            testState <= 4'd1;
          end
        end
      4'd1:
        begin
          if (RXready) begin
            ALU.a[7:0] <= RXbuffer;
            testState <= 4'd2;
          end
        end
      4'd2:
        begin
          if (RXready) begin
            ALU.r0[15:8] <= RXbuffer;
            testState <= 4'd3;
          end
        end
      4'd3:
        begin
          if (RXready) begin
            ALU.r1[7:0] <= RXbuffer;
            testState <= 4'd4;
          end
        end
      4'd4:
        begin
          if (RXready) begin
            ALU.r1[15:8] <= RXbuffer;
            testState <= 4'd5;
            operation[5] <= 1'b1;
          end
        end
      4'd5:
        begin
          if (~TXbusy) begin
            operation[5] <= 1'b0;
            TXbuffer <= ALU.r0[7:0];
            TXstart <= 1'b1;
            testState <= 4'd6;
          end
        end
      4'd6:
        begin
          TXstart <= 1'b0;
          if (~TXbusy) begin
            TXbuffer <= ALU.r0[15:8];
            TXstart <= 1'b1;
            testState <= 4'd7;
          end
        end
      4'd7:
        begin
          TXstart <= 1'b0;
          if (~TXbusy) begin
            TXbuffer <= {7'd0, overflow};
            TXstart <= 1'b1;
            testState <= 4'd0;
          end
        end
      default:
        begin
          TXstart <= 1'b0;
          testState <= 4'd0;
        end
    endcase
   end

  assign GPIO9 = 1'b1;
  assign GPIO11 = 1'b0;

  // assign GPIO0 = res[0];
  // assign GPIO1 = res[1];
  // assign GPIO2 = res[2];
  assign GPIO3 = clkdiv[23];

endmodule
