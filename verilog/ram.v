
module ram(
    input wire CLK,

    input wire [15:0] address,
    input wire [15:0] dataIn,
    input wire write,

    output wire [15:0] dataOut,

    output wire CE, OE, WR, UB, LB,

    output wire A0, A1, A2,  A3,  A4,  A5,  A6,  A7,
    output wire A8, A9, A10, A11, A12, A13, A14, A15,

    // inout wire D0, D1, D2,  D3,  D4,  D5,  D6,  D7,
    // inout wire D8, D9, D10, D11, D12, D13, D14, D15
    //sim hack:
    output wire D0, D1, D2,  D3,  D4,  D5,  D6,  D7,
    output wire D8, D9, D10, D11, D12, D13, D14, D15,

    input wire D0_in, D1_in, D2_in,  D3_in,  D4_in,  D5_in,  D6_in,  D7_in,
    input wire D8_in, D9_in, D10_in, D11_in, D12_in, D13_in, D14_in, D15_in
  );

  reg writeToggle = 1'b0;
  reg writePulse = 1'b0;

  always @(posedge CLK) begin

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
  assign OE = (write & ~CLK);
  //assign WR = writePulse ? ~CLK : 1'b1;
  assign WR = ~(write & ~CLK);
  assign UB = WR;
  assign LB = WR;

  assign D0 = write ? dataIn[0] : 1'bz;
  assign D1 = write ? dataIn[1] : 1'bz;
  assign D2 = write ? dataIn[2] : 1'bz;
  assign D3 = write ? dataIn[3] : 1'bz;
  assign D4 = write ? dataIn[4] : 1'bz;
  assign D5 = write ? dataIn[5] : 1'bz;
  assign D6 = write ? dataIn[6] : 1'bz;
  assign D7 = write ? dataIn[7] : 1'bz;

  assign D8 = write ? dataIn[8] : 1'bz;
  assign D9 = write ? dataIn[9] : 1'bz;
  assign D10 = write ? dataIn[10] : 1'bz;
  assign D11 = write ? dataIn[11] : 1'bz;
  assign D12 = write ? dataIn[12] : 1'bz;
  assign D13 = write ? dataIn[13] : 1'bz;
  assign D14 = write ? dataIn[14] : 1'bz;
  assign D15 = write ? dataIn[15] : 1'bz;

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

  assign dataOut = {D15_in, D14_in, D13_in, D12_in, D11_in, D10_in, D9_in,  D8_in,
              D7_in,  D6_in,  D5_in,  D4_in,  D3_in,  D2_in,  D1_in,  D0_in};


endmodule
