// this aboutta get complicated

module alu(
    input wire CLK,

    input wire [2:0] aindex,
    input wire [2:0] bindex,
    input wire [2:0] yindex,
    input wire [1:0] op, // don't forget we need logic!

    output reg overflow = 0
  );

  reg [15:0] r0 = 16'b1;
  reg [15:0] r1 = 16'b1;
  reg [15:0] r2 = 16'b1;
  reg [15:0] r3 = 16'b1;
  reg [15:0] r4 = 16'b1;
  reg [15:0] r5 = 16'b1;
  reg [15:0] r6 = 16'b1;
  reg [15:0] r7 = 16'b1;

  wire [16:0] addsub; // wire with overflow bit
  wire [16:0] mult; // the overflow bit works just like addition

  reg [15:0] a = 16'b0;
  reg [15:0] b = 16'b0;

  always @(*) begin
    case (aindex)
      3'd0: a = r0;
      3'd1: a = r1;
      3'd2: a = r2;
      3'd3: a = r3;
      3'd4: a = r4;
      3'd5: a = r5;
      3'd6: a = r6;
      3'd7: a = r7;
    endcase
  end

  always @(*) begin
    case (bindex)
      3'd0: b = r0;
      3'd1: b = r1;
      3'd2: b = r2;
      3'd3: b = r3;
      3'd4: b = r4;
      3'd5: b = r5;
      3'd6: b = r6;
      3'd7: b = r7;
    endcase
  end

  assign addsub = op[0] ? a - b : a + b;
  assign mult = a*b;

  always @(posedge CLK) begin
    if (~op[1]) begin
      case (yindex)
        3'd0: r0 <= addsub[15:0];
        3'd1: r1 <= addsub[15:0];
        3'd2: r2 <= addsub[15:0];
        3'd3: r3 <= addsub[15:0];
        3'd4: r4 <= addsub[15:0];
        3'd5: r5 <= addsub[15:0];
        3'd6: r6 <= addsub[15:0];
        3'd7: r7 <= addsub[15:0];
      endcase
      overflow <= addsub[16];
    end else begin
      case (yindex)
        3'd0: r0 <= mult[15:0];
        3'd1: r1 <= mult[15:0];
        3'd2: r2 <= mult[15:0];
        3'd3: r3 <= mult[15:0];
        3'd4: r4 <= mult[15:0];
        3'd5: r5 <= mult[15:0];
        3'd6: r6 <= mult[15:0];
        3'd7: r7 <= mult[15:0];
      endcase
      overflow <= mult[16];
    end
  end

endmodule
