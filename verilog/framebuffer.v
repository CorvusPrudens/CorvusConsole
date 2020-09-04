module framebuffer(
    input wire CLK,

    input wire [15:0] address,
    input wire [15:0] dataIn,
    input wire write,

    output wire [15:0] dataOut,

    output wire CE, OE, WR, UB, LB,

    output wire [15:0] ADDRESS_PINS,

    output wire [15:0] DATA_OUT_PINS,
    input wire [15:0] DATA_IN_PINS,

    // inout wire [15:0] DATA_PINS,
  );

  assign CE = 1'b1;
  assign OE = (write & ~CLK);
  assign WR = ~(write & ~CLK);
  assign UB = WR;
  assign LB = WR;

  assign dataOut = DATA_IN_PINS;
  assign ADDRESS_PINS = address;
  assign DATA_OUT_PINS = dataIn;
  // assign DATA_PINS = write ? dataIn : 1'bz;

endmodule
