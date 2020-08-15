// this aboutta get complicated

module alu(
    input wire CLK,

    input wire [2:0] aindex,
    input wire [2:0] bindex,
    input wire [2:0] yindex,
    input wire [5:0] op,
    input wire [3:0] params,

    output reg overflow = 0
  );

  // verilator lint_off MULTIDRIVEN
  reg [15:0] r0 = 16'h1;
  reg [15:0] r1 = 16'h2;
  reg [15:0] r2 = 16'h3;
  reg [15:0] r3 = 16'h4;
  reg [15:0] r4 = 16'h5;
  reg [15:0] r5 = 16'h6;
  reg [15:0] r6 = 16'h7;
  reg [15:0] r7 = 16'h8;
  // verilator lint_on MULTIDRIVEN

  wire [16:0] addsub; // wire with overflow bit
  wire [16:0] mult;   // the overflow bit works just like addition
  wire [15:0] log;    // overflow not possible with bitwise logic
  reg [15:0] lshift;  // overflow unreliable
  reg [15:0] rshift;  // overflow unreliable

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

  // left shift
  always @(*) begin
    case (params)
      4'h0: lshift = a;
      4'h1: lshift = {a[14:0], 1'b0};
      4'h2: lshift = {a[13:0], 2'b0};
      4'h3: lshift = {a[12:0], 3'b0};
      4'h4: lshift = {a[11:0], 4'b0};
      4'h5: lshift = {a[10:0], 5'b0};
      4'h6: lshift = {a[9:0], 6'b0};
      4'h7: lshift = {a[8:0], 7'b0};
      4'h8: lshift = {a[7:0], 8'b0};
      4'h9: lshift = {a[6:0], 9'b0};
      4'hA: lshift = {a[5:0], 10'b0};
      4'hB: lshift = {a[4:0], 11'b0};
      4'hC: lshift = {a[3:0], 12'b0};
      4'hD: lshift = {a[2:0], 13'b0};
      4'hE: lshift = {a[1:0], 14'b0};
      4'hF: lshift = {a[0], 15'b0};
    endcase
  end

  always @(*) begin
    case (params)
      4'h0: rshift = a;
      4'h1: rshift = {1'b0, a[15:1]};
      4'h2: rshift = {2'b0, a[15:2]};
      4'h3: rshift = {3'b0, a[15:3]};
      4'h4: rshift = {4'b0, a[15:4]};
      4'h5: rshift = {5'b0, a[15:5]};
      4'h6: rshift = {6'b0, a[15:6]};
      4'h7: rshift = {7'b0, a[15:7]};
      4'h8: rshift = {8'b0, a[15:8]};
      4'h9: rshift = {9'b0, a[15:9]};
      4'hA: rshift = {10'b0, a[15:10]};
      4'hB: rshift = {11'b0, a[15:11]};
      4'hC: rshift = {12'b0, a[15:12]};
      4'hD: rshift = {13'b0, a[15:13]};
      4'hE: rshift = {14'b0, a[15:14]};
      4'hF: rshift = {15'b0, a[15]};
    endcase
  end

  // 0 = AND, 1 = OR, 2 = XOR, 3 = NOT
  assign log = params[1] & params[0] ? ~a : params[1] ?
               a ^ b : params[0] ? a | b : a & b;
  // assign log = op[0] ? a | b : op[1] ? a ^ b : a & b;
  assign addsub = params[0] ? a - b : a + b;
  assign mult = a*b;

  always @(negedge CLK) begin
    if (op[5]) begin
      if (op[0]) begin
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
        overflow <= overflow | addsub[16];
      end else if (op[1]) begin
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
        overflow <= overflow | mult[16];
      end else if (op[2]) begin
        case (yindex)
          3'd0: r0 <= log;
          3'd1: r1 <= log;
          3'd2: r2 <= log;
          3'd3: r3 <= log;
          3'd4: r4 <= log;
          3'd5: r5 <= log;
          3'd6: r6 <= log;
          3'd7: r7 <= log;
        endcase
      end else if (op[3]) begin
        case (yindex)
          3'd0: r0 <= lshift;
          3'd1: r1 <= lshift;
          3'd2: r2 <= lshift;
          3'd3: r3 <= lshift;
          3'd4: r4 <= lshift;
          3'd5: r5 <= lshift;
          3'd6: r6 <= lshift;
          3'd7: r7 <= lshift;
        endcase
      end else if (op[4]) begin
        case (yindex)
          3'd0: r0 <= rshift;
          3'd1: r1 <= rshift;
          3'd2: r2 <= rshift;
          3'd3: r3 <= rshift;
          3'd4: r4 <= rshift;
          3'd5: r5 <= rshift;
          3'd6: r6 <= rshift;
          3'd7: r7 <= rshift;
        endcase
      end
    end
  end

endmodule
