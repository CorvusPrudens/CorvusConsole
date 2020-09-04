// `include "fifo16.v"
`include "framebuffer.v"

module gpu(
    input wire CLK,
    // output reg [7:0] red,
    // output reg [7:0] green,
    // output reg [7:0] blue,
    //
    // input wire [7:0] address,

    input wire write,
    // input wire read,

    input wire [15:0] address,
    input wire [15:0] dataIn,
    output wire [15:0] dataOut,
    input wire [15:0] BUFFER_DATA_IN,
    output wire [15:0] BUFFER_DATA_OUT,
    output wire [15:0] ADDRESS_PINS,
    output wire B_CE, B_OE, B_WR, B_UB, B_LB

  );

  framebuffer BUFFER(
      .CLK(CLK),
      .write(write),
      .dataIn(dataIn),
      .dataOut(dataOut),
      .ADDRESS_PINS(ADDRESS_PINS),
      .DATA_OUT_PINS(BUFFER_DATA_OUT),
      .DATA_IN_PINS(BUFFER_DATA_IN),
      .CE(B_CE), .OE(B_OE), .WR(B_WR), .UB(B_UB), .LB(B_LB)
    );

  // we'll figure out queuing later

  // wire busToBufferWrite;
  // wire [7:0] busToBufferData;
  // wire inputEmpty;
  // wire inputFull;
  //
  //
  // fifo8 INFIFO(
  //     .CLK(CLK),
  //     .dataIn(dataIn),
  //     .write(write),
  //     .read(sendRead),
  //     .dataOut(uartin),
  //     .full(TXfull),
  //     .empty(TXempty)
  //   );
endmodule
