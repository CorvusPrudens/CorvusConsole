//verilator lint_off UNUSED
//verilator lint_off UNDRIVEN

`timescale 1ns/100ps
`default_nettype none

// `include "uart.v"
`include "alu.v"
`include "ram.v"
`include "prom.v"
`include "drom.v"
`include "control.v"
`include "uartwrapper.v"
`include "gpu.v"

module top(
    input wire CLK,

    input wire RX,
    output wire TX,

    // output wire GPIO0,
    // output wire GPIO1,
    // output wire GPIO2,
    output wire GPIO3,
    output wire GPIO9,
    output wire GPIO11,

    output wire CE, OE, WR, UB, LB,

    output wire A0, A1, A2,  A3,  A4,  A5,  A6,  A7,
    output wire A8, A9, A10, A11, A12, A13, A14, A15,

    // inout wire D0, D1, D2,  D3,  D4,  D5,  D6,  D7,
    // inout wire D8, D9, D10, D11, D12, D13, D14, D15
    //sim hack:
    output wire D0, D1, D2,  D3,  D4,  D5,  D6,  D7,
    output wire D8, D9, D10, D11, D12, D13, D14, D15,

    input wire D0_in, D1_in, D2_in,  D3_in,  D4_in,  D5_in,  D6_in,  D7_in,
    input wire D8_in, D9_in, D10_in, D11_in, D12_in, D13_in, D14_in, D15_in

    input wire [15:0] BUFFER_DATA_IN,
    output wire [15:0] BUFFER_DATA_OUT,
    output wire [15:0] BUFFER_ADDRESS,
    output wire B_CE, B_OE, B_WR, B_UB, B_LB
  );

  // Control
  wire [3:0] busState;

  wire [2:0] aluOperand1;
  wire [2:0] aluOperand2;
  wire [2:0] aluResults;
  wire [6:0] aluOperation;
  wire [3:0] aluParams;
  wire aluReadBus;

  wire ramWrite;
  wire gpuWrite;

  wire [15:0] ramAddress;
  wire [15:0] progRomAddress;
  wire [15:0] dataRomAddress;
  wire [15:0] gpuAddress;
  wire [15:0] ctrlOut;
  wire [31:0] controlWord;

  control CONTROL(
      .CLK(CLK),
      .operand1(aluOperand1),
      .operand2(aluOperand2),
      .results(aluResults),
      .aluOperation(aluOperation),
      .aluParams(aluParams),
      .busState(busState),
      .aluReadBus(aluReadBus),
      .aluStatus(aluStatus),
      .ramWrite(ramWrite),
      .gpuWrite(gpuWrite),
      .freg(ALU.f),
      .greg(ALU.g),
      .hreg(ALU.h),
      .ramAdd(ramAddress),
      .progRomAdd(progRomAddress),
      .dataRomAdd(dataRomAddress),
      .gpuAdd(gpuAddress),
      .dout(ctrlOut),
      .controlWord(controlWord)
    );

  // bus
  wire [15:0] aluOut; // these are all the modules
  wire [15:0] ramOut; // i'll need to design
  wire [15:0] romOut; // this is our data rom
  wire [15:0] gpuOut;
  wire [15:0] apuOut;
  wire [15:0] clkOut;
  reg [15:0] bus = 16'h00;

  always @(*) begin
    case (busState)
      4'h0: bus = 16'h00;
      4'h1: bus = aluOut;
      4'h2: bus = ramOut;
      4'h3: bus = romOut;
      4'h4: bus = gpuOut;
      4'h5: bus = apuOut;
      4'h6: bus = ctrlOut;
      4'h7: bus = clkOut;
      default: bus = 16'h00;
    endcase
  end

  wire MEMstatus;
  wire MEMuart;
  wire MEMaddrstack;
  wire MEMuserstack;
  wire MEMgpio;
  wire MEMgpiodir;
  wire MEMwrite;
  reg [15:0] MEMbus = 16'b0;

  wire [15:0] MEMout;

  wire [15:0] uartOut;
  wire [15:0] statusOut;
  wire [15:0] addrstackOut;
  wire [15:0] userstackOut;
  wire [15:0] gpioOut;
  wire [15:0] gpiodirOut;
  wire [6:0] MEMstate = {
    MEMwrite,
    MEMgpiodir, MEMgpio,
    MEMuart, MEMuserstack,
    MEMaddrstack, MEMstatus
  };

  always @(*) begin
    case (MEMstate)
      7'b0000001: MEMbus = statusOut;
      7'b0000010: MEMbus = addrstackOut;
      7'b0000100: MEMbus = userstackOut;
      7'b0001000: MEMbus = uartOut;
      7'b0010000: MEMbus = gpioOut;
      7'b0100000: MEMbus = gpiodirOut;
      // 7'b1000000: MEMbus = MEMout;
      default: MEMbus = MEMout;
    endcase
  end

  // program ROM
  prom PROM(
      .CLK(CLK),
      .address(progRomAddress),
      .data(controlWord)
    );

  drom DROM(
  	.CLK(CLK),
  	.address(dataRomAddress),
  	.data(romOut)
  );


  // ALU
  wire overflow;
  wire [5:0] aluStatus;

  alu ALU(
      // .CLK(testClock),
      .CLK(CLK),
      .readBus(aluReadBus),
      .din(bus),
      .dout(aluOut),
      .operandIndex1(aluOperand1),
      .operandIndex2(aluOperand2),
      .resultsIndex(aluResults),
      .operation(aluOperation),
      .params(aluParams),
      .status(aluStatus)
    );

  // RAM
  ram RAM(
      // .CLK(testClock),
      .CLK(CLK),
      .address(ramAddress),
      .dataIn(bus),
      .write(ramWrite),
      .dataOut(ramOut),

      .CE(CE), .OE(OE), .WR(WR), .UB(UB), .LB(LB),

      .A0(A0), .A1(A1), .A2(A2), .A3(A3),
      .A4(A4), .A5(A5), .A6(A6), .A7(A7),
      .A8(A8), .A9(A9), .A10(A10), .A11(A11),
      .A12(A12), .A13(A13), .A14(A14), .A15(A15),

      .D0(D0), .D1(D1), .D2(D2), .D3(D3),
      .D4(D4), .D5(D5), .D6(D6), .D7(D7),
      .D8(D8), .D9(D9), .D10(D10), .D11(D11),
      .D12(D12), .D13(D13), .D14(D14), .D15(D15),

      //simulation hack
      .D0_in(D0_in), .D1_in(D1_in), .D2_in(D2_in), .D3_in(D3_in),
      .D4_in(D4_in), .D5_in(D5_in), .D6_in(D6_in), .D7_in(D7_in),
      .D8_in(D8_in), .D9_in(D9_in), .D10_in(D10_in), .D11_in(D11_in),
      .D12_in(D12_in), .D13_in(D13_in), .D14_in(D14_in), .D15_in(D15_in),

      .memIn(MEMbus),
      .memOut(MEMout),

      .status(MEMstatus),
      .uart(MEMuart),
      .addrstack(MEMaddrstack),
      .userstack(MEMuserstack),
      .gpio(MEMgpio),
      .gpiodir(MEMgpiodir),
      .memwrite(MEMwrite)
    );

    wire MEMstatus;
    wire MEMuart;
    wire MEMaddrstack;
    wire MEMuserstack;
    wire MEMgpio;
    wire MEMgpiodir;

  uartwrapper UART(
      .CLK(CLK),
      .dataIn(MEMbus[7:0]),
      .write(MEMwrite & MEMuart),
      .read(MEMuart),
      .dataOut(uartOut),
      .RX(RX),
      .TX(TX)
    );

  gpu GPU(
      .CLK(CLK),
      .write(gpuWrite),
      .address(gpuAddress),
      .dataIn(bus),
      .dataOut(gpuOut),
      .BUFFER_DATA_IN(BUFFER_DATA_IN),
      .BUFFER_DATA_OUT(BUFFER_DATA_OUT),
      .ADDRESS_PINS(BUFFER_ADDRESS),
      .B_CE, .B_OE, .B_WR, .B_UB, .B_LB
    );


  reg [3:0] testState = 0;
  reg [24:0] clkdiv = 0;

  always @(posedge CLK) begin
    clkdiv <= clkdiv + 1'b1;
   end

  assign GPIO9 = 1'b1;
  assign GPIO11 = 1'b0;

  assign GPIO3 = clkdiv[23];

endmodule
