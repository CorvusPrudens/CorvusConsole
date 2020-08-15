
module alu(
    input wire CLK,

    input wire [15:0] a, // bus architecture?
    input wire [15:0] b,
    input wire [1:0] op,


    output reg [15:0] res = 0,
    output reg overflow = 0
  );

  wire [16:0] addsub; // wire with overflow bit
  wire[16:0] mult; // the overflow bit works just like addition

  assign addsub = op[0] ? a - b : a + b;
  assign mult = a*b;

  always @(posedge CLK) begin
    if (~op[1]) begin
      res <= addsub[15:0];
      overflow <= addsub[16];
    end else begin
      res <= mult[15:0];
      overflow <= mult[16];
      // if (mult[31:16] > 0) overflow <= 1'b1;
      // else overflow <= 1'b0;
    end
  end

endmodule
