// While ram/rom accesses will appear the same to the programmer
// (differentiated by the type 'const'), the addressing and bus
// access will have to be different here

module control(
    input wire CLK,

    output reg [2:0] operand1 = 0,
    output reg [2:0] operand2 = 0,
    output reg [2:0] results = 0,
    output reg [5:0] aluOperation = 6'b0,
    output reg [3:0] aluParams = 4'b0,

    output reg [3:0] busState = 0,

    output reg aluReadBus = 1'b0,
    output reg ramWrite = 1'b0,
    input wire [15:0] greg,
    output wire [15:0] hreg,
    output wire [15:0] ramAdd,
    output wire [15:0] romAdd,
    output wire [15:0] dout
  );

  reg increment = 1'b0;
  reg ramAddMode = 1'b0;
  reg [15:0] programCounter = 16'b0;
  wire [31:0] controlWord = 32'b00000000_00000100_000_000_000_00_01000;

  wire [5:0] opcode = controlWord[5:0];
  wire [2:0] operand1Wire = controlWord[9:7];
  wire [2:0] operand2Wire = controlWord[12:10];
  wire [2:0] resultsWire = controlWord[15:13];
  wire [15:0] word2Wire = controlWord[31:16];
  assign dout = word2Wire;

  // The ram address is either the second part of
  // the instruction word or the g register
  assign ramAdd = ramAddMode ? greg : word2Wire;

  always @(posedge CLK) if (increment) programCounter <= programCounter + 1'b1;

  always @(negedge CLK) begin
    case (opcode[5:1])
      5'h00: // NOP
        begin
          busState <= 4'h0;
          increment <= 1'b1;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[5] <= 1'b0;
          increment <= 1'b1;
        end
      5'h01: // LDR
        begin
          busState <= 4'h2;
          ramWrite <= 1'b0;
          results <= resultsWire;
          aluOperation[5] <= 1'b0;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
          ramAddMode <= 1'b0;
        end
      5'h02: // STR
        begin
          busState <= 4'h1;
          ramWrite <= 1'b1;
          operand1 <= operand1Wire;
          aluOperation[5] <= 1'b0;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
          ramAddMode <= 1'b0;
        end
      5'h03: // ADD
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 6'b100001;
          aluParams[0] <= 1'b0;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
        end
      5'h04: // SUB
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 6'b100001;
          aluParams[0] <= 1'b1;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
        end
      5'h05: // MUL
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 6'b100010;
          aluParams[0] <= 1'b0;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
        end
      5'h08: // LDI
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          results <= resultsWire;
          aluOperation <= 6'b100000;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h09: // ADI
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b100001;
          aluParams[0] <= 1'b0;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h0A: // SBI
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b100001;
          aluParams[0] <= 1'b1;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h0B: // MLI
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b100010;
          aluParams[0] <= 1'b0;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h0E: // AND
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 6'b100100;
          aluParams <= 4'b0000;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
        end
      5'h0F: // OR
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 6'b100100;
          aluParams <= 4'b0001;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
        end
      5'h10: // XOR
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 6'b100100;
          aluParams <= 4'b0010;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
        end
      5'h11: // NOT
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b100100;
          aluParams <= 4'b0011;
          increment <= 1'b1;
          aluReadBus <= 1'b0;
        end
      5'h12: // ANI
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b100100;
          aluParams <= 4'b0000;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h13: // ORI
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b100100;
          aluParams <= 4'b0001;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h14: // XRI
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b100100;
          aluParams <= 4'b0010;
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h15: // LSL
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b101000;
          aluParams <= word2Wire[3:0];
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end
      5'h16: // LSR
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 6'b110000;
          aluParams <= word2Wire[3:0];
          increment <= 1'b1;
          aluReadBus <= 1'b1;
        end

      default:
        begin
          busState <= 4'h0;
          increment <= 1'b1;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          increment <= 1'b1;
        end
    endcase
  end




endmodule
