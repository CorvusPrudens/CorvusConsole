// this aboutta get complicated

module alu(
    input wire CLK,

    input wire readBus,
    input wire  [15:0] din,
    output wire [15:0] dout,

    input wire [2:0] operandIndex1,
    input wire [2:0] operandIndex2,
    input wire [2:0] resultsIndex,
    input wire [5:0] operation,
    input wire [3:0] params,

    output reg overflow = 0
  );

  // verilator lint_off MULTIDRIVEN
  reg [15:0] a = 16'h2;
  reg [15:0] b = 16'h0;
  reg [15:0] c = 16'h0;
  reg [15:0] d = 16'h0;
  reg [15:0] e = 16'h0;
  reg [15:0] f = 16'h0;
  reg [15:0] g = 16'h0;
  reg [15:0] h = 16'h0;
  // verilator lint_on MULTIDRIVEN

  wire [16:0] addsub; // wire with overflow bit
  wire [16:0] mult;   // the overflow bit works just like addition
  wire [15:0] log;    // overflow not possible with bitwise logic
  reg [15:0] lshift;  // overflow unreliable
  reg [15:0] rshift;  // overflow unreliable

  reg [15:0] operand1 = 16'b0;
  reg [15:0] operand2 = 16'b0;

  wire [15:0] combOperand2 = readBus ? din : operand2;

  always @(*) begin
    case (operandIndex1)
      3'd0: operand1 = a;
      3'd1: operand1 = b;
      3'd2: operand1 = c;
      3'd3: operand1 = d;
      3'd4: operand1 = e;
      3'd5: operand1 = f;
      3'd6: operand1 = g;
      3'd7: operand1 = h;
    endcase
  end

  always @(*) begin
    case (operandIndex2)
      3'd0: operand2 = a;
      3'd1: operand2 = b;
      3'd2: operand2 = c;
      3'd3: operand2 = d;
      3'd4: operand2 = e;
      3'd5: operand2 = f;
      3'd6: operand2 = g;
      3'd7: operand2 = h;
    endcase
  end

  // left shift
  always @(*) begin
    case (params)
      4'h0: lshift = operand1;
      4'h1: lshift = {operand1[14:0], 1'b0};
      4'h2: lshift = {operand1[13:0], 2'b0};
      4'h3: lshift = {operand1[12:0], 3'b0};
      4'h4: lshift = {operand1[11:0], 4'b0};
      4'h5: lshift = {operand1[10:0], 5'b0};
      4'h6: lshift = {operand1[9:0], 6'b0};
      4'h7: lshift = {operand1[8:0], 7'b0};
      4'h8: lshift = {operand1[7:0], 8'b0};
      4'h9: lshift = {operand1[6:0], 9'b0};
      4'hA: lshift = {operand1[5:0], 10'b0};
      4'hB: lshift = {operand1[4:0], 11'b0};
      4'hC: lshift = {operand1[3:0], 12'b0};
      4'hD: lshift = {operand1[2:0], 13'b0};
      4'hE: lshift = {operand1[1:0], 14'b0};
      4'hF: lshift = {operand1[0], 15'b0};
    endcase
  end

  always @(*) begin
    case (params)
      4'h0: rshift = operand1;
      4'h1: rshift = {1'b0, operand1[15:1]};
      4'h2: rshift = {2'b0, operand1[15:2]};
      4'h3: rshift = {3'b0, operand1[15:3]};
      4'h4: rshift = {4'b0, operand1[15:4]};
      4'h5: rshift = {5'b0, operand1[15:5]};
      4'h6: rshift = {6'b0, operand1[15:6]};
      4'h7: rshift = {7'b0, operand1[15:7]};
      4'h8: rshift = {8'b0, operand1[15:8]};
      4'h9: rshift = {9'b0, operand1[15:9]};
      4'hA: rshift = {10'b0, operand1[15:10]};
      4'hB: rshift = {11'b0, operand1[15:11]};
      4'hC: rshift = {12'b0, operand1[15:12]};
      4'hD: rshift = {13'b0, operand1[15:13]};
      4'hE: rshift = {14'b0, operand1[15:14]};
      4'hF: rshift = {15'b0, operand1[15]};
    endcase
  end

  assign dout = operand1;
  // 0 = AND, 1 = OR, 2 = XOR, 3 = NOT
  assign log = params[1] & params[0] ? ~operand1 : params[1] ?
               operand1 ^ combOperand2 : params[0] ? operand1 | combOperand2 : operand1 & combOperand2;
  // assign log = operation[0] ? operand1 | combOperand2 : operation[1] ? operand1 ^ combOperand2 : operand1 & combOperand2;
  assign addsub = params[0] ? operand1 - combOperand2 : operand1 + combOperand2;
  assign mult = operand1*combOperand2;

  always @(posedge CLK) begin
    if (operation[5]) begin
      if (operation[0]) begin
        case (resultsIndex)
          3'd0: a <= addsub[15:0];
          3'd1: b <= addsub[15:0];
          3'd2: c <= addsub[15:0];
          3'd3: d <= addsub[15:0];
          3'd4: e <= addsub[15:0];
          3'd5: f <= addsub[15:0];
          3'd6: g <= addsub[15:0];
          3'd7: h <= addsub[15:0];
        endcase
        overflow <= overflow | addsub[16];
      end else if (operation[1]) begin
        case (resultsIndex)
          3'd0: a <= mult[15:0];
          3'd1: b <= mult[15:0];
          3'd2: c <= mult[15:0];
          3'd3: d <= mult[15:0];
          3'd4: e <= mult[15:0];
          3'd5: f <= mult[15:0];
          3'd6: g <= mult[15:0];
          3'd7: h <= mult[15:0];
        endcase
        overflow <= overflow | mult[16];
      end else if (operation[2]) begin
        case (resultsIndex)
          3'd0: a <= log;
          3'd1: b <= log;
          3'd2: c <= log;
          3'd3: d <= log;
          3'd4: e <= log;
          3'd5: f <= log;
          3'd6: g <= log;
          3'd7: h <= log;
        endcase
      end else if (operation[3]) begin
        case (resultsIndex)
          3'd0: a <= lshift;
          3'd1: b <= lshift;
          3'd2: c <= lshift;
          3'd3: d <= lshift;
          3'd4: e <= lshift;
          3'd5: f <= lshift;
          3'd6: g <= lshift;
          3'd7: h <= lshift;
        endcase
      end else if (operation[4]) begin
        case (resultsIndex)
          3'd0: a <= rshift;
          3'd1: b <= rshift;
          3'd2: c <= rshift;
          3'd3: d <= rshift;
          3'd4: e <= rshift;
          3'd5: f <= rshift;
          3'd6: g <= rshift;
          3'd7: h <= rshift;
        endcase
      end else if (readBus) begin
        case (resultsIndex)
          3'd0: a <= din;
          3'd1: b <= din;
          3'd2: c <= din;
          3'd3: d <= din;
          3'd4: e <= din;
          3'd5: f <= din;
          3'd6: g <= din;
          3'd7: h <= din;
        endcase
      end
    end
  end

endmodule
