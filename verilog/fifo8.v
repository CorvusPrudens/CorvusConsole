
module fifo8(
    input wire CLK,
    input wire [7:0] dataIn,
    input wire write,
    input wire read,

    output reg [7:0] dataOut,
    output wire full, empty
  );

  reg [7:0] buffer [255:0];
  reg [7:0] idx0;
  reg [7:0] idxn;

  // kinda dumb but works in a pinch
  reg [7:0] idx0prev;
  reg [7:0] idxnprev;

  always @(posedge CLK) begin
    if (write) begin
      buffer[idxnprev] <= dataIn;
      idxn <= idxn + 1'b1;
    end
    if (read) begin
      dataOut <= buffer[idx0prev];
      idx0 <= idx0 + 1'b1;
    end
  end

  always @(negedge CLK) begin
    if (idx0prev != idx0) begin
      idx0prev <= idx0prev + 1'b1;
    end
    if (idxnprev != idxn) begin
      idxnprev <= idxnprev + 1'b1;
    end
  end

  assign full = idx0 - idxn == 8'd1;
  assign empty = idx0 == idxn;

endmodule
