
module registers(
    input wire CLK,

    input wire [15:0] a,
    input wire [15:0] b,

    input wire [2:0] aindex,
    input wire [2:0] bindex,
    input wire [2:0] yindex
  );

  reg [15:0] r0 = 16'b0;
  reg [15:0] r1 = 16'b0;
  reg [15:0] r2 = 16'b0;
  reg [15:0] r3 = 16'b0;
  reg [15:0] r4 = 16'b0;
  reg [15:0] r5 = 16'b0;
  reg [15:0] r6 = 16'b0;
  reg [15:0] r7 = 16'b0;

  always @(*) begin
    case (aindex)



    endcase


  end


endmodule
