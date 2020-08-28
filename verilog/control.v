// While ram/rom accesses will appear the same to the programmer
// (differentiated by the type 'const'), the addressing and bus
// access will have to be different here

module control(
    input wire CLK,

    output reg [2:0] operand1 = 0,
    output reg [2:0] operand2 = 0,
    output reg [2:0] results = 0,
    output reg [6:0] aluOperation = 7'b0,
    output reg [3:0] aluParams = 4'b0,

    output reg [3:0] busState = 0,

    output reg aluReadBus = 1'b0,
    input wire [5:0] aluStatus,
    output reg ramWrite = 1'b0,
    input wire [15:0] hreg,
    output wire [15:0] ramAdd,
    output wire [15:0] romAdd,
    output reg [15:0] dout,

    input wire [31:0] controlWord
  );

  // {interrupt, display, compare, zero, carry}
  reg [4:0] flags = 5'b0;
  reg [2:0] increment = 3'b0;
  reg ramAddMode = 1'b0;
  reg [15:0] ramAddReg = 16'd1024;
  reg [15:0] programCounter = 16'b0;

  wire [1:0] opvar = controlWord[1:0];
  wire [4:0] opcode = controlWord[6:2];
  wire [2:0] operand1Wire = controlWord[9:7];
  wire [2:0] operand2Wire = controlWord[12:10];
  wire [2:0] resultsWire = controlWord[15:13];
  wire [15:0] word2Wire = controlWord[31:16];
  wire [5:0] conditions = controlWord[12:7];
  // assign dout = word2Wire;
  assign ramAdd = ramAddReg;

  //addrstack -- TODO must be replaced by proper BRAM
  reg [15:0] addrstack [255:0];
  // verilator lint_off MULTIDRIVEN
  reg [7:0] addrstackptr = 8'b0;
  // verilator lint_on MULTIDRIVEN

  always @(posedge CLK) begin
    if (increment[2]) begin
      case (increment[1:0])
        2'b00: programCounter <= programCounter + 1'b1;
        2'b01: programCounter <= dout;
        2'b10:
          begin
            programCounter <= dout;
            addrstackptr <= addrstackptr + 1'b1;
          end
        2'b11: programCounter <= addrstack[addrstackptr];
      endcase
    end
  end
  assign romAdd = programCounter;

  always @(negedge CLK) begin
    case (opcode)
      5'h00: // NOP
        begin
          busState <= 4'h0;
          increment <= 3'b100;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
        end
      5'h01: // LDR
        begin
          if (opvar[0]) begin // ROM TODO
            busState <= 4'h2;
          end else begin
            busState <= opvar[1] ? 4'h6 : 4'h2;
            ramWrite <= 1'b0;
            results <= resultsWire;
            aluOperation <= 7'b1000000;
            increment <= 3'b100;
            aluReadBus <= 1'b1;
            ramAddReg <= word2Wire;
            dout <= word2Wire;
          end
        end
      5'h02: // STR
        begin
          busState <= 4'h1;
          ramWrite <= 1'b1;
          operand1 <= operand1Wire;
          aluOperation <= 7'b0;
          increment <= 3'b100;
          aluReadBus <= 1'b0;
          ramAddMode <= 1'b0;
          ramAddReg <= word2Wire;
          dout <= word2Wire;
        end
      5'h03: // LPT
        begin
          if (opvar[0]) begin // ROM TODO
            busState <= 4'h2;
          end else begin
            busState <= 4'h2;
            ramWrite <= 1'b0;
            results <= resultsWire;
            aluOperation[6] <= 1'b0;
            increment <= 3'b100;
            aluReadBus <= 1'b1;
            ramAddMode <= 1'b1;
            ramAddReg <= hreg;
            dout <= word2Wire;
          end
        end
      5'h04: // SPT
        begin
          if (opvar[0]) begin // ROM TODO
            busState <= 4'h2;
          end else begin
            busState <= 4'h1;
            ramWrite <= 1'b1;
            operand1 <= operand1Wire;
            aluOperation[6] <= 1'b0;
            increment <= 3'b100;
            aluReadBus <= 1'b0;
            ramAddReg <= hreg;
            dout <= word2Wire;
          end
        end
      5'h05: // CMP TODO
        begin
          busState <= 4'h6;
          dout <= word2Wire;
          increment <= 3'b100;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          aluOperation <= 7'b1100000;
          aluReadBus <= opvar[1];
        end
      5'h06: // ADD
        begin
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 7'b1000001;
          aluParams[0] <= 1'b0;
          increment <= 3'b100;
          busState <= 4'h6; // just in case an immediate
          dout <= word2Wire;
          aluReadBus <= opvar[1]; // immediate if 1
        end
      5'h07: // SUB
        begin
          busState <= 4'h6;
          dout <= word2Wire;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 7'b1000001;
          aluParams[0] <= 1'b1;
          increment <= 3'b100;
          aluReadBus <= opvar[1]; // immediate if 1
        end
      5'h08: // MUL
        begin
          busState <= 4'h6;
          dout <= word2Wire;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 7'b1000010;
          aluParams[0] <= 1'b0;
          increment <= 3'b100;
          aluReadBus <= opvar[1]; // immediate if 1
        end
      5'h09: // DIV TODO
        begin
          busState <= 4'h0;
          increment <= 3'b100;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
        end
      5'h0A: // MOD TODO
        begin
          busState <= 4'h0;
          increment <= 3'b100;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
        end
      5'h0B: // AND
        begin
          busState <= 4'h6;
          dout <= word2Wire;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 7'b1000100;
          aluParams <= 4'b0000;
          increment <= 3'b100;
          aluReadBus <= opvar[1]; // immediate if 1
        end
      5'h0C: // OR
        begin
          busState <= 4'h6;
          dout <= word2Wire;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 7'b1000100;
          aluParams <= 4'b0001;
          increment <= 3'b100;
          aluReadBus <= opvar[1]; // immediate if 1
        end
      5'h0D: // XOR
        begin
          busState <= 4'h6;
          dout <= word2Wire;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          operand2 <= operand2Wire;
          results <= resultsWire;
          aluOperation <= 7'b1000100;
          aluParams <= 4'b0010;
          increment <= 3'b100;
          aluReadBus <= opvar[1]; // immediate if 1
        end
      5'h0E: // NOT
        begin
          busState <= 4'h6;
          dout <= word2Wire;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 7'b1000100;
          aluParams <= 4'b0011;
          increment <= 3'b100;
          aluReadBus <= 1'b0;
        end
      5'h0F: // LSL
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 7'b1001000;
          aluParams <= word2Wire[3:0];
          increment <= 3'b100;
          aluReadBus <= 1'b1;
        end
      5'h10: // LSR
        begin
          busState <= 4'h6;
          ramWrite <= 1'b0;
          operand1 <= operand1Wire;
          results <= resultsWire;
          aluOperation <= 7'b1010000;
          aluParams <= word2Wire[3:0];
          increment <= 3'b100;
          aluReadBus <= 1'b1;
        end
      5'h14: // JMP
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
          increment <= 3'b101;
          dout <= word2Wire;
        end
      5'h15: // JSR
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
          increment <= 3'b110;
          dout <= word2Wire;
          addrstack[addrstackptr] <= programCounter + 1'b1;
        end
      5'h16: // RTS
        begin
          busState <= 4'h0;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
          increment <= 3'b111;
          addrstackptr <= addrstackptr - 1'b1;
        end
      5'h17: // JOC
        begin
          if ((conditions & aluStatus) > 6'b0) begin
            increment <= 3'b101;
            dout <= word2Wire;
          end else begin
            increment <= 3'b100;
          end
          busState <= 4'h0;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
        end
      5'h18: // JSC
        begin
          if ((conditions & aluStatus) > 6'b0) begin
            increment <= 3'b110;
            dout <= word2Wire;
            addrstack[addrstackptr] <= programCounter + 1'b1;
          end else begin
            increment <= 3'b100;
          end
          busState <= 4'h0;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
        end
      5'h19: // RSC
        begin
          if ((conditions & aluStatus) > 6'b0) begin
            increment <= 3'b111;
            addrstackptr <= addrstackptr - 1'b1;
          end else begin
            increment <= 3'b100;
          end
          busState <= 4'h0;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
        end
      default:
        begin
          busState <= 4'h0;
          increment <= 3'b100;
          ramWrite <= 1'b0;
          aluReadBus <= 1'b0;
          aluOperation[6] <= 1'b0;
        end
    endcase
  end

endmodule
