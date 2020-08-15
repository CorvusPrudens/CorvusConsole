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

  // ALU
  reg [2:0] a = 0;
  reg [2:0] b = 3'b001;
  reg [2:0] y = 0;
  reg [1:0] op = 2'b0;
  //wire [15:0] res;
  wire overflow;

  alu ALU(
      .CLK(CLK),
      .aindex(a),
      .bindex(b),
      .yindex(y),
      .op(op),
      .overflow(overflow)
    );

  reg [3:0] testState = 0;
  reg [24:0] clkdiv = 0;

  always @(posedge CLK) begin

    clkdiv <= clkdiv + 1'b1;
    // testState <= testState + 1'b1;
    //
    if (clkdiv[3:0] == 4'd15) begin
      a <= a + 1'b1;
      y <= y + 1'b1;
      // a <= 0;
    end

  //   case (testState)
  //     4'd0:
  //       begin
  //         TXstart <= 1'b0;
  //         if (RXready) begin
  //           op <= RXbuffer[1:0];
  //           testState <= 4'd1;
  //         end
  //       end
  //     4'd1:
  //       begin
  //         if (RXready) begin
  //           a[7:0] <= RXbuffer;
  //           testState <= 4'd2;
  //         end
  //       end
  //     4'd2:
  //       begin
  //         if (RXready) begin
  //           a[15:8] <= RXbuffer;
  //           testState <= 4'd3;
  //         end
  //       end
  //     4'd3:
  //       begin
  //         if (RXready) begin
  //           b[7:0] <= RXbuffer;
  //           testState <= 4'd4;
  //         end
  //       end
  //     4'd4:
  //       begin
  //         if (RXready) begin
  //           b[15:8] <= RXbuffer;
  //           testState <= 4'd5;
  //         end
  //       end
  //     4'd5:
  //       begin
  //         if (~TXbusy) begin
  //           TXbuffer <= res[7:0];
  //           TXstart <= 1'b1;
  //           testState <= 4'd6;
  //         end
  //       end
  //     4'd6:
  //       begin
  //         TXstart <= 1'b0;
  //         if (~TXbusy) begin
  //           TXbuffer <= res[15:8];
  //           TXstart <= 1'b1;
  //           testState <= 4'd7;
  //         end
  //       end
  //     4'd7:
  //       begin
  //         TXstart <= 1'b0;
  //         if (~TXbusy) begin
  //           TXbuffer <= {7'd0, overflow};
  //           TXstart <= 1'b1;
  //           testState <= 4'd0;
  //         end
  //       end
  //     default:
  //       begin
  //         TXstart <= 1'b0;
  //         testState <= 4'd0;
  //       end
  //   endcase
   end

  assign GPIO9 = 1'b1;
  assign GPIO11 = 1'b0;

  // assign GPIO0 = res[0];
  // assign GPIO1 = res[1];
  // assign GPIO2 = res[2];
  assign GPIO3 = clkdiv[23];

endmodule
