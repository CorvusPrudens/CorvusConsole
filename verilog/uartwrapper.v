`include "uart.v"
`include "fifo8.v"

module uartwrapper(
    input wire CLK,
    input wire [7:0] dataIn,
    input wire write,
    input wire read,

    output wire [15:0] dataOut,
    // output wire full, empty,

    input wire RX,
    output wire TX
  );

  reg [7:0] dataOutReg;
  assign dataOut = {{6{1'b0}}, empty, full, dataOutReg};

  wire uartread;
  wire uartdone;
  wire [7:0] uartin;
  wire [7:0] uartout;
  wire uartoutwrite;
  wire TXbusy;
  wire outfull;

  wire full;
  wire empty;

  fifo8 INFIFO(
      .CLK(CLK),
      .dataIn(dataIn),
      .write(write),
      .read(sendRead),
      .dataOut(uartin),
      .full(full),
      .empty(uartdone)
    );

  reg sendState = 1'b0;
  reg sendRead = 1'b0;
  reg TXstart = 1'b0;

  always @(posedge CLK) begin
    case (sendState)
      1'b0:
        begin
          TXstart <= 1'b0;
          if (~uartdone & ~TXbusy) begin
            sendRead <= 1'b1;
            sendState <= 1'b1;
          end
        end
      1'b1:
        begin
          sendRead <= 1'b0;
          TXstart <= 1'b1;
          sendState <= 1'b0;
        end
    endcase
  end


  uart UART(
      .CLK(CLK),
      .RX(RX),
      .TX(TX),
      .TXbuffer(uartin),
      .TXstart(TXstart),
      .RXbuffer(uartout),
      .RXready(uartoutwrite),
      .TXbusy(TXbusy)
    );

  // possible way to stop read?
  // flow control? otherwise if
  // this fills, we'll miss data
  fifo8 OUTFIFO(
      .CLK(CLK),
      .dataIn(uartout),
      .write(uartoutwrite),
      .read(read & ~empty),
      .dataOut(dataOutReg),
      .full(outfull),
      .empty(empty)
    );

endmodule
