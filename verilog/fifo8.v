
module fifo8(
    input wire CLK,
    input wire [7:0] dataIn,
    input wire write,
    input wire read,

    output reg [7:0] dataOut,
    output wire full, empty
  );

  reg [7:0] buffer [255:0];
  reg idx0 [7:0];
  reg idxn [7:0];

  always @(posedge CLK) begin
    if (write) begin
      buffer[idxn] = dataIn;
      idxn = idxn + 1'b1;
    end
    if (read) begin
      dataOut = buffer[idx0];
      idx0 = idx0 + 1'b1;
    end
  end

  assign full = idx0 - idxn == 8'd1;
  assign empty = idx0 == idxn;

endmodule
