
module ram(
    input wire CLK,

    input wire [15:0] address,
    input wire [15:0] dataIn,
    input wire write,

    output reg [15:0] dataOut,

    output wire CE, OE, WR, UB, LB,

    output wire A0, A1, A2,  A3,  A4,  A5,  A6,  A7,
    output wire A8, A9, A10, A11, A12, A13, A14, A15,

    inout wire D0, D1, D2,  D3,  D4,  D5,  D6,  D7,
    inout wire D8, D9, D10, D11, D12, D13, D14, D15
  );

  always @(posedge CLK) begin
    dataOut <= {D15, D14, D13, D12, D11, D10, D9,  D8,
                D7,  D6,  D5,  D4,  D3,  D2,  D1,  D0};
  end

  // How to handle address? should there be a register?
  // or should we have a separate ram address bus that
  // drives it directly? if so, how to handle indirect
  // addressing?

  // addressing should include 8-bit and 16-bit mode,
  // where 8-bit converts addresses and data to appear
  // as a natively 8-bit device (? -- nah, bit shifts are cheap)

  // This ^ should definitely be done for ROM to
  // anything other than the control module
  // (of course, the assembler will need to take this
  // into account)

  assign CE = 1'b1;
  assign OE = write ? 1'b1 : 1'b0;
  assign WR = write ? ~CLK : 1'b1;
  assign UB = WR;
  assign LB = WR;

  assign D0 = write ? data[0] : 1'bz;
  assign D1 = write ? data[1] : 1'bz;
  assign D2 = write ? data[2] : 1'bz;
  assign D3 = write ? data[3] : 1'bz;
  assign D4 = write ? data[4] : 1'bz;
  assign D5 = write ? data[5] : 1'bz;
  assign D6 = write ? data[6] : 1'bz;
  assign D7 = write ? data[7] : 1'bz;

  assign D8 = write ? data[8] : 1'bz;
  assign D9 = write ? data[9] : 1'bz;
  assign D10 = write ? data[10] : 1'bz;
  assign D11 = write ? data[11] : 1'bz;
  assign D12 = write ? data[12] : 1'bz;
  assign D13 = write ? data[13] : 1'bz;
  assign D14 = write ? data[14] : 1'bz;
  assign D15 = write ? data[15] : 1'bz;

  assign A0 = address[0];
  assign A1 = address[1];
  assign A2 = address[2];
  assign A3 = address[3];
  assign A4 = address[4];
  assign A5 = address[5];
  assign A6 = address[6];
  assign A7 = address[7];

  assign A8 =  address[8];
  assign A9 =  address[9];
  assign A10 = address[10];
  assign A11 = address[11];
  assign A12 = address[12];
  assign A13 = address[13];
  assign A14 = address[14];
  assign A15 = address[15];


endmodule
