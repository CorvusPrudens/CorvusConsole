// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+425,"CLK", false,-1);
        vcdp->declBit(c+433,"RX", false,-1);
        vcdp->declBit(c+441,"TX", false,-1);
        vcdp->declBit(c+449,"GPIO3", false,-1);
        vcdp->declBit(c+457,"GPIO9", false,-1);
        vcdp->declBit(c+465,"GPIO11", false,-1);
        vcdp->declBit(c+473,"CE", false,-1);
        vcdp->declBit(c+481,"OE", false,-1);
        vcdp->declBit(c+489,"WR", false,-1);
        vcdp->declBit(c+497,"UB", false,-1);
        vcdp->declBit(c+505,"LB", false,-1);
        vcdp->declBit(c+513,"A0", false,-1);
        vcdp->declBit(c+521,"A1", false,-1);
        vcdp->declBit(c+529,"A2", false,-1);
        vcdp->declBit(c+537,"A3", false,-1);
        vcdp->declBit(c+545,"A4", false,-1);
        vcdp->declBit(c+553,"A5", false,-1);
        vcdp->declBit(c+561,"A6", false,-1);
        vcdp->declBit(c+569,"A7", false,-1);
        vcdp->declBit(c+577,"A8", false,-1);
        vcdp->declBit(c+585,"A9", false,-1);
        vcdp->declBit(c+593,"A10", false,-1);
        vcdp->declBit(c+601,"A11", false,-1);
        vcdp->declBit(c+609,"A12", false,-1);
        vcdp->declBit(c+617,"A13", false,-1);
        vcdp->declBit(c+625,"A14", false,-1);
        vcdp->declBit(c+633,"A15", false,-1);
        vcdp->declBit(c+641,"D0", false,-1);
        vcdp->declBit(c+649,"D1", false,-1);
        vcdp->declBit(c+657,"D2", false,-1);
        vcdp->declBit(c+665,"D3", false,-1);
        vcdp->declBit(c+673,"D4", false,-1);
        vcdp->declBit(c+681,"D5", false,-1);
        vcdp->declBit(c+689,"D6", false,-1);
        vcdp->declBit(c+697,"D7", false,-1);
        vcdp->declBit(c+705,"D8", false,-1);
        vcdp->declBit(c+713,"D9", false,-1);
        vcdp->declBit(c+721,"D10", false,-1);
        vcdp->declBit(c+729,"D11", false,-1);
        vcdp->declBit(c+737,"D12", false,-1);
        vcdp->declBit(c+745,"D13", false,-1);
        vcdp->declBit(c+753,"D14", false,-1);
        vcdp->declBit(c+761,"D15", false,-1);
        vcdp->declBit(c+769,"D0_in", false,-1);
        vcdp->declBit(c+777,"D1_in", false,-1);
        vcdp->declBit(c+785,"D2_in", false,-1);
        vcdp->declBit(c+793,"D3_in", false,-1);
        vcdp->declBit(c+801,"D4_in", false,-1);
        vcdp->declBit(c+809,"D5_in", false,-1);
        vcdp->declBit(c+817,"D6_in", false,-1);
        vcdp->declBit(c+825,"D7_in", false,-1);
        vcdp->declBit(c+833,"D8_in", false,-1);
        vcdp->declBit(c+841,"D9_in", false,-1);
        vcdp->declBit(c+849,"D10_in", false,-1);
        vcdp->declBit(c+857,"D11_in", false,-1);
        vcdp->declBit(c+865,"D12_in", false,-1);
        vcdp->declBit(c+873,"D13_in", false,-1);
        vcdp->declBit(c+881,"D14_in", false,-1);
        vcdp->declBit(c+889,"D15_in", false,-1);
        vcdp->declBit(c+425,"top CLK", false,-1);
        vcdp->declBit(c+433,"top RX", false,-1);
        vcdp->declBit(c+441,"top TX", false,-1);
        vcdp->declBit(c+449,"top GPIO3", false,-1);
        vcdp->declBit(c+457,"top GPIO9", false,-1);
        vcdp->declBit(c+465,"top GPIO11", false,-1);
        vcdp->declBit(c+473,"top CE", false,-1);
        vcdp->declBit(c+481,"top OE", false,-1);
        vcdp->declBit(c+489,"top WR", false,-1);
        vcdp->declBit(c+497,"top UB", false,-1);
        vcdp->declBit(c+505,"top LB", false,-1);
        vcdp->declBit(c+513,"top A0", false,-1);
        vcdp->declBit(c+521,"top A1", false,-1);
        vcdp->declBit(c+529,"top A2", false,-1);
        vcdp->declBit(c+537,"top A3", false,-1);
        vcdp->declBit(c+545,"top A4", false,-1);
        vcdp->declBit(c+553,"top A5", false,-1);
        vcdp->declBit(c+561,"top A6", false,-1);
        vcdp->declBit(c+569,"top A7", false,-1);
        vcdp->declBit(c+577,"top A8", false,-1);
        vcdp->declBit(c+585,"top A9", false,-1);
        vcdp->declBit(c+593,"top A10", false,-1);
        vcdp->declBit(c+601,"top A11", false,-1);
        vcdp->declBit(c+609,"top A12", false,-1);
        vcdp->declBit(c+617,"top A13", false,-1);
        vcdp->declBit(c+625,"top A14", false,-1);
        vcdp->declBit(c+633,"top A15", false,-1);
        vcdp->declBit(c+641,"top D0", false,-1);
        vcdp->declBit(c+649,"top D1", false,-1);
        vcdp->declBit(c+657,"top D2", false,-1);
        vcdp->declBit(c+665,"top D3", false,-1);
        vcdp->declBit(c+673,"top D4", false,-1);
        vcdp->declBit(c+681,"top D5", false,-1);
        vcdp->declBit(c+689,"top D6", false,-1);
        vcdp->declBit(c+697,"top D7", false,-1);
        vcdp->declBit(c+705,"top D8", false,-1);
        vcdp->declBit(c+713,"top D9", false,-1);
        vcdp->declBit(c+721,"top D10", false,-1);
        vcdp->declBit(c+729,"top D11", false,-1);
        vcdp->declBit(c+737,"top D12", false,-1);
        vcdp->declBit(c+745,"top D13", false,-1);
        vcdp->declBit(c+753,"top D14", false,-1);
        vcdp->declBit(c+761,"top D15", false,-1);
        vcdp->declBit(c+769,"top D0_in", false,-1);
        vcdp->declBit(c+777,"top D1_in", false,-1);
        vcdp->declBit(c+785,"top D2_in", false,-1);
        vcdp->declBit(c+793,"top D3_in", false,-1);
        vcdp->declBit(c+801,"top D4_in", false,-1);
        vcdp->declBit(c+809,"top D5_in", false,-1);
        vcdp->declBit(c+817,"top D6_in", false,-1);
        vcdp->declBit(c+825,"top D7_in", false,-1);
        vcdp->declBit(c+833,"top D8_in", false,-1);
        vcdp->declBit(c+841,"top D9_in", false,-1);
        vcdp->declBit(c+849,"top D10_in", false,-1);
        vcdp->declBit(c+857,"top D11_in", false,-1);
        vcdp->declBit(c+865,"top D12_in", false,-1);
        vcdp->declBit(c+873,"top D13_in", false,-1);
        vcdp->declBit(c+881,"top D14_in", false,-1);
        vcdp->declBit(c+889,"top D15_in", false,-1);
        vcdp->declBus(c+41,"top RXbuffer", false,-1, 7,0);
        vcdp->declBus(c+1,"top TXbuffer", false,-1, 7,0);
        vcdp->declBit(c+9,"top TXstart", false,-1);
        vcdp->declBit(c+49,"top RXready", false,-1);
        vcdp->declBit(c+57,"top TXbusy", false,-1);
        vcdp->declBus(c+905,"top testWord", false,-1, 31,0);
        vcdp->declBit(c+17,"top testClock", false,-1);
        vcdp->declBus(c+129,"top busState", false,-1, 3,0);
        vcdp->declBus(c+137,"top aluOperand1", false,-1, 2,0);
        vcdp->declBus(c+145,"top aluOperand2", false,-1, 2,0);
        vcdp->declBus(c+153,"top aluResults", false,-1, 2,0);
        vcdp->declBus(c+161,"top aluOperation", false,-1, 5,0);
        vcdp->declBus(c+169,"top aluParams", false,-1, 3,0);
        vcdp->declBit(c+177,"top aluReadBus", false,-1);
        vcdp->declBit(c+185,"top ramWrite", false,-1);
        vcdp->declBus(c+209,"top greg", false,-1, 15,0);
        vcdp->declBus(c+913,"top hreg", false,-1, 15,0);
        vcdp->declBus(c+385,"top ramAddress", false,-1, 15,0);
        vcdp->declBus(c+217,"top romAddress", false,-1, 15,0);
        vcdp->declBus(c+225,"top ctrlOut", false,-1, 15,0);
        vcdp->declBus(c+233,"top controlWord", false,-1, 31,0);
        vcdp->declBus(c+393,"top aluOut", false,-1, 15,0);
        vcdp->declBus(c+897,"top ramOut", false,-1, 15,0);
        vcdp->declBus(c+921,"top romOut", false,-1, 15,0);
        vcdp->declBus(c+929,"top gpuOut", false,-1, 15,0);
        vcdp->declBus(c+937,"top apuOut", false,-1, 15,0);
        vcdp->declBus(c+945,"top clkOut", false,-1, 15,0);
        vcdp->declBus(c+345,"top bus", false,-1, 15,0);
        vcdp->declBus(c+953,"top din", false,-1, 15,0);
        vcdp->declBus(c+961,"top dout", false,-1, 15,0);
        vcdp->declBus(c+969,"top a", false,-1, 2,0);
        vcdp->declBus(c+977,"top b", false,-1, 2,0);
        vcdp->declBus(c+969,"top y", false,-1, 2,0);
        vcdp->declBus(c+985,"top operation", false,-1, 5,0);
        vcdp->declBus(c+993,"top params", false,-1, 3,0);
        vcdp->declBit(c+241,"top overflow", false,-1);
        vcdp->declBus(c+25,"top testState", false,-1, 3,0);
        vcdp->declBus(c+33,"top clkdiv", false,-1, 24,0);
        vcdp->declBit(c+425,"top FTDI CLK", false,-1);
        vcdp->declBit(c+433,"top FTDI RX", false,-1);
        vcdp->declBus(c+1,"top FTDI TXbuffer", false,-1, 7,0);
        vcdp->declBit(c+9,"top FTDI TXstart", false,-1);
        vcdp->declBit(c+441,"top FTDI TX", false,-1);
        vcdp->declBus(c+41,"top FTDI RXbuffer", false,-1, 7,0);
        vcdp->declBit(c+49,"top FTDI RXready", false,-1);
        vcdp->declBit(c+57,"top FTDI TXbusy", false,-1);
        vcdp->declBus(c+1001,"top FTDI CLOCK_DIVISOR", false,-1, 31,0);
        vcdp->declBus(c+65,"top FTDI baudAcc", false,-1, 2,0);
        vcdp->declBit(c+73,"top FTDI baudTick", false,-1);
        vcdp->declBus(c+81,"top FTDI TXstate", false,-1, 3,0);
        vcdp->declBit(c+89,"top FTDI TXready", false,-1);
        vcdp->declBus(c+97,"top FTDI TXshift", false,-1, 7,0);
        vcdp->declBus(c+105,"top FTDI RXstate", false,-1, 3,0);
        vcdp->declBus(c+113,"top FTDI gap", false,-1, 2,0);
        vcdp->declBit(c+121,"top FTDI nextBit", false,-1);
        vcdp->declBit(c+17,"top CONTROL CLK", false,-1);
        vcdp->declBus(c+137,"top CONTROL operand1", false,-1, 2,0);
        vcdp->declBus(c+145,"top CONTROL operand2", false,-1, 2,0);
        vcdp->declBus(c+153,"top CONTROL results", false,-1, 2,0);
        vcdp->declBus(c+161,"top CONTROL aluOperation", false,-1, 5,0);
        vcdp->declBus(c+169,"top CONTROL aluParams", false,-1, 3,0);
        vcdp->declBus(c+129,"top CONTROL busState", false,-1, 3,0);
        vcdp->declBit(c+177,"top CONTROL aluReadBus", false,-1);
        vcdp->declBit(c+185,"top CONTROL ramWrite", false,-1);
        vcdp->declBus(c+209,"top CONTROL greg", false,-1, 15,0);
        vcdp->declBus(c+913,"top CONTROL hreg", false,-1, 15,0);
        vcdp->declBus(c+385,"top CONTROL ramAdd", false,-1, 15,0);
        vcdp->declBus(c+217,"top CONTROL romAdd", false,-1, 15,0);
        vcdp->declBus(c+225,"top CONTROL dout", false,-1, 15,0);
        vcdp->declBus(c+233,"top CONTROL controlWord", false,-1, 31,0);
        vcdp->declBus(c+1009,"top CONTROL flags", false,-1, 4,0);
        vcdp->declBus(c+193,"top CONTROL increment", false,-1, 1,0);
        vcdp->declBit(c+201,"top CONTROL ramAddMode", false,-1);
        vcdp->declBus(c+217,"top CONTROL programCounter", false,-1, 15,0);
        vcdp->declBus(c+249,"top CONTROL opvar", false,-1, 1,0);
        vcdp->declBus(c+257,"top CONTROL opcode", false,-1, 4,0);
        vcdp->declBus(c+265,"top CONTROL operand1Wire", false,-1, 2,0);
        vcdp->declBus(c+273,"top CONTROL operand2Wire", false,-1, 2,0);
        vcdp->declBus(c+281,"top CONTROL resultsWire", false,-1, 2,0);
        vcdp->declBus(c+225,"top CONTROL word2Wire", false,-1, 15,0);
        vcdp->declBit(c+425,"top ROM CLK", false,-1);
        vcdp->declBus(c+217,"top ROM address", false,-1, 15,0);
        vcdp->declBus(c+233,"top ROM data", false,-1, 31,0);
        vcdp->declBit(c+425,"top ROM ROMDATA CLK", false,-1);
        vcdp->declBus(c+217,"top ROM ROMDATA address", false,-1, 15,0);
        vcdp->declBus(c+233,"top ROM ROMDATA data", false,-1, 31,0);
        vcdp->declBus(c+233,"top ROM ROMDATA dintern", false,-1, 31,0);
        vcdp->declBit(c+17,"top ALU CLK", false,-1);
        vcdp->declBit(c+177,"top ALU readBus", false,-1);
        vcdp->declBus(c+345,"top ALU din", false,-1, 15,0);
        vcdp->declBus(c+393,"top ALU dout", false,-1, 15,0);
        vcdp->declBus(c+137,"top ALU operandIndex1", false,-1, 2,0);
        vcdp->declBus(c+145,"top ALU operandIndex2", false,-1, 2,0);
        vcdp->declBus(c+153,"top ALU resultsIndex", false,-1, 2,0);
        vcdp->declBus(c+161,"top ALU operation", false,-1, 5,0);
        vcdp->declBus(c+169,"top ALU params", false,-1, 3,0);
        vcdp->declBit(c+241,"top ALU overflow", false,-1);
        vcdp->declBus(c+289,"top ALU a", false,-1, 15,0);
        vcdp->declBus(c+297,"top ALU b", false,-1, 15,0);
        vcdp->declBus(c+305,"top ALU c", false,-1, 15,0);
        vcdp->declBus(c+313,"top ALU d", false,-1, 15,0);
        vcdp->declBus(c+321,"top ALU e", false,-1, 15,0);
        vcdp->declBus(c+329,"top ALU f", false,-1, 15,0);
        vcdp->declBus(c+209,"top ALU g", false,-1, 15,0);
        vcdp->declBus(c+337,"top ALU h", false,-1, 15,0);
        vcdp->declBus(c+353,"top ALU addsub", false,-1, 16,0);
        vcdp->declBus(c+361,"top ALU mult", false,-1, 16,0);
        vcdp->declBus(c+369,"top ALU log", false,-1, 15,0);
        vcdp->declBus(c+401,"top ALU lshift", false,-1, 15,0);
        vcdp->declBus(c+409,"top ALU rshift", false,-1, 15,0);
        vcdp->declBus(c+393,"top ALU operand1", false,-1, 15,0);
        vcdp->declBus(c+417,"top ALU operand2", false,-1, 15,0);
        vcdp->declBus(c+377,"top ALU combOperand2", false,-1, 15,0);
        vcdp->declBit(c+17,"top RAM CLK", false,-1);
        vcdp->declBus(c+385,"top RAM address", false,-1, 15,0);
        vcdp->declBus(c+345,"top RAM dataIn", false,-1, 15,0);
        vcdp->declBit(c+185,"top RAM write", false,-1);
        vcdp->declBus(c+897,"top RAM dataOut", false,-1, 15,0);
        vcdp->declBit(c+473,"top RAM CE", false,-1);
        vcdp->declBit(c+481,"top RAM OE", false,-1);
        vcdp->declBit(c+489,"top RAM WR", false,-1);
        vcdp->declBit(c+497,"top RAM UB", false,-1);
        vcdp->declBit(c+505,"top RAM LB", false,-1);
        vcdp->declBit(c+513,"top RAM A0", false,-1);
        vcdp->declBit(c+521,"top RAM A1", false,-1);
        vcdp->declBit(c+529,"top RAM A2", false,-1);
        vcdp->declBit(c+537,"top RAM A3", false,-1);
        vcdp->declBit(c+545,"top RAM A4", false,-1);
        vcdp->declBit(c+553,"top RAM A5", false,-1);
        vcdp->declBit(c+561,"top RAM A6", false,-1);
        vcdp->declBit(c+569,"top RAM A7", false,-1);
        vcdp->declBit(c+577,"top RAM A8", false,-1);
        vcdp->declBit(c+585,"top RAM A9", false,-1);
        vcdp->declBit(c+593,"top RAM A10", false,-1);
        vcdp->declBit(c+601,"top RAM A11", false,-1);
        vcdp->declBit(c+609,"top RAM A12", false,-1);
        vcdp->declBit(c+617,"top RAM A13", false,-1);
        vcdp->declBit(c+625,"top RAM A14", false,-1);
        vcdp->declBit(c+633,"top RAM A15", false,-1);
        vcdp->declBit(c+641,"top RAM D0", false,-1);
        vcdp->declBit(c+649,"top RAM D1", false,-1);
        vcdp->declBit(c+657,"top RAM D2", false,-1);
        vcdp->declBit(c+665,"top RAM D3", false,-1);
        vcdp->declBit(c+673,"top RAM D4", false,-1);
        vcdp->declBit(c+681,"top RAM D5", false,-1);
        vcdp->declBit(c+689,"top RAM D6", false,-1);
        vcdp->declBit(c+697,"top RAM D7", false,-1);
        vcdp->declBit(c+705,"top RAM D8", false,-1);
        vcdp->declBit(c+713,"top RAM D9", false,-1);
        vcdp->declBit(c+721,"top RAM D10", false,-1);
        vcdp->declBit(c+729,"top RAM D11", false,-1);
        vcdp->declBit(c+737,"top RAM D12", false,-1);
        vcdp->declBit(c+745,"top RAM D13", false,-1);
        vcdp->declBit(c+753,"top RAM D14", false,-1);
        vcdp->declBit(c+761,"top RAM D15", false,-1);
        vcdp->declBit(c+769,"top RAM D0_in", false,-1);
        vcdp->declBit(c+777,"top RAM D1_in", false,-1);
        vcdp->declBit(c+785,"top RAM D2_in", false,-1);
        vcdp->declBit(c+793,"top RAM D3_in", false,-1);
        vcdp->declBit(c+801,"top RAM D4_in", false,-1);
        vcdp->declBit(c+809,"top RAM D5_in", false,-1);
        vcdp->declBit(c+817,"top RAM D6_in", false,-1);
        vcdp->declBit(c+825,"top RAM D7_in", false,-1);
        vcdp->declBit(c+833,"top RAM D8_in", false,-1);
        vcdp->declBit(c+841,"top RAM D9_in", false,-1);
        vcdp->declBit(c+849,"top RAM D10_in", false,-1);
        vcdp->declBit(c+857,"top RAM D11_in", false,-1);
        vcdp->declBit(c+865,"top RAM D12_in", false,-1);
        vcdp->declBit(c+873,"top RAM D13_in", false,-1);
        vcdp->declBit(c+881,"top RAM D14_in", false,-1);
        vcdp->declBit(c+889,"top RAM D15_in", false,-1);
        vcdp->declBit(c+1017,"top RAM writeToggle", false,-1);
        vcdp->declBit(c+1017,"top RAM writePulse", false,-1);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->top__DOT__TXbuffer),8);
        vcdp->fullBit(c+9,(vlTOPp->top__DOT__TXstart));
        vcdp->fullBit(c+17,(vlTOPp->top__DOT__testClock));
        vcdp->fullBus(c+25,(vlTOPp->top__DOT__testState),4);
        vcdp->fullBus(c+33,(vlTOPp->top__DOT__clkdiv),25);
        vcdp->fullBus(c+41,(vlTOPp->top__DOT__RXbuffer),8);
        vcdp->fullBit(c+49,(vlTOPp->top__DOT__RXready));
        vcdp->fullBit(c+57,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        vcdp->fullBus(c+65,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
        vcdp->fullBit(c+73,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                   >> 2U))));
        vcdp->fullBus(c+81,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
        vcdp->fullBit(c+89,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        vcdp->fullBus(c+97,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
        vcdp->fullBus(c+105,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
        vcdp->fullBus(c+113,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
        vcdp->fullBit(c+121,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                    >> 2U))));
        vcdp->fullBus(c+129,(vlTOPp->top__DOT__busState),4);
        vcdp->fullBus(c+137,(vlTOPp->top__DOT__aluOperand1),3);
        vcdp->fullBus(c+145,(vlTOPp->top__DOT__aluOperand2),3);
        vcdp->fullBus(c+153,(vlTOPp->top__DOT__aluResults),3);
        vcdp->fullBus(c+161,(vlTOPp->top__DOT__aluOperation),6);
        vcdp->fullBus(c+169,(vlTOPp->top__DOT__aluParams),4);
        vcdp->fullBit(c+177,(vlTOPp->top__DOT__aluReadBus));
        vcdp->fullBit(c+185,(vlTOPp->top__DOT__ramWrite));
        vcdp->fullBus(c+193,(vlTOPp->top__DOT__CONTROL__DOT__increment),2);
        vcdp->fullBit(c+201,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
        vcdp->fullBus(c+209,(vlTOPp->top__DOT__ALU__DOT__g),16);
        vcdp->fullBus(c+217,(vlTOPp->top__DOT__CONTROL__DOT__programCounter),16);
        vcdp->fullBus(c+225,((0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                         >> 0x10U))),16);
        vcdp->fullBus(c+233,(vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern),32);
        vcdp->fullBit(c+241,(vlTOPp->top__DOT__overflow));
        vcdp->fullBus(c+249,((3U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)),2);
        vcdp->fullBus(c+257,((0x1fU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                       >> 2U))),5);
        vcdp->fullBus(c+265,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                    >> 7U))),3);
        vcdp->fullBus(c+273,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                    >> 0xaU))),3);
        vcdp->fullBus(c+281,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                    >> 0xdU))),3);
        vcdp->fullBus(c+289,(vlTOPp->top__DOT__ALU__DOT__a),16);
        vcdp->fullBus(c+297,(vlTOPp->top__DOT__ALU__DOT__b),16);
        vcdp->fullBus(c+305,(vlTOPp->top__DOT__ALU__DOT__c),16);
        vcdp->fullBus(c+313,(vlTOPp->top__DOT__ALU__DOT__d),16);
        vcdp->fullBus(c+321,(vlTOPp->top__DOT__ALU__DOT__e),16);
        vcdp->fullBus(c+329,(vlTOPp->top__DOT__ALU__DOT__f),16);
        vcdp->fullBus(c+337,(vlTOPp->top__DOT__ALU__DOT__h),16);
        vcdp->fullBus(c+345,(vlTOPp->top__DOT__bus),16);
        vcdp->fullBus(c+353,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        vcdp->fullBus(c+361,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        vcdp->fullBus(c+369,(vlTOPp->top__DOT__ALU__DOT__log),16);
        vcdp->fullBus(c+377,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
        vcdp->fullBus(c+385,(vlTOPp->top__DOT__ramAddress),16);
        vcdp->fullBus(c+393,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
        vcdp->fullBus(c+401,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
        vcdp->fullBus(c+409,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
        vcdp->fullBus(c+417,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
        vcdp->fullBit(c+425,(vlTOPp->CLK));
        vcdp->fullBit(c+433,(vlTOPp->RX));
        vcdp->fullBit(c+441,(vlTOPp->TX));
        vcdp->fullBit(c+449,(vlTOPp->GPIO3));
        vcdp->fullBit(c+457,(vlTOPp->GPIO9));
        vcdp->fullBit(c+465,(vlTOPp->GPIO11));
        vcdp->fullBit(c+473,(vlTOPp->CE));
        vcdp->fullBit(c+481,(vlTOPp->OE));
        vcdp->fullBit(c+489,(vlTOPp->WR));
        vcdp->fullBit(c+497,(vlTOPp->UB));
        vcdp->fullBit(c+505,(vlTOPp->LB));
        vcdp->fullBit(c+513,(vlTOPp->A0));
        vcdp->fullBit(c+521,(vlTOPp->A1));
        vcdp->fullBit(c+529,(vlTOPp->A2));
        vcdp->fullBit(c+537,(vlTOPp->A3));
        vcdp->fullBit(c+545,(vlTOPp->A4));
        vcdp->fullBit(c+553,(vlTOPp->A5));
        vcdp->fullBit(c+561,(vlTOPp->A6));
        vcdp->fullBit(c+569,(vlTOPp->A7));
        vcdp->fullBit(c+577,(vlTOPp->A8));
        vcdp->fullBit(c+585,(vlTOPp->A9));
        vcdp->fullBit(c+593,(vlTOPp->A10));
        vcdp->fullBit(c+601,(vlTOPp->A11));
        vcdp->fullBit(c+609,(vlTOPp->A12));
        vcdp->fullBit(c+617,(vlTOPp->A13));
        vcdp->fullBit(c+625,(vlTOPp->A14));
        vcdp->fullBit(c+633,(vlTOPp->A15));
        vcdp->fullBit(c+641,(vlTOPp->D0));
        vcdp->fullBit(c+649,(vlTOPp->D1));
        vcdp->fullBit(c+657,(vlTOPp->D2));
        vcdp->fullBit(c+665,(vlTOPp->D3));
        vcdp->fullBit(c+673,(vlTOPp->D4));
        vcdp->fullBit(c+681,(vlTOPp->D5));
        vcdp->fullBit(c+689,(vlTOPp->D6));
        vcdp->fullBit(c+697,(vlTOPp->D7));
        vcdp->fullBit(c+705,(vlTOPp->D8));
        vcdp->fullBit(c+713,(vlTOPp->D9));
        vcdp->fullBit(c+721,(vlTOPp->D10));
        vcdp->fullBit(c+729,(vlTOPp->D11));
        vcdp->fullBit(c+737,(vlTOPp->D12));
        vcdp->fullBit(c+745,(vlTOPp->D13));
        vcdp->fullBit(c+753,(vlTOPp->D14));
        vcdp->fullBit(c+761,(vlTOPp->D15));
        vcdp->fullBit(c+769,(vlTOPp->D0_in));
        vcdp->fullBit(c+777,(vlTOPp->D1_in));
        vcdp->fullBit(c+785,(vlTOPp->D2_in));
        vcdp->fullBit(c+793,(vlTOPp->D3_in));
        vcdp->fullBit(c+801,(vlTOPp->D4_in));
        vcdp->fullBit(c+809,(vlTOPp->D5_in));
        vcdp->fullBit(c+817,(vlTOPp->D6_in));
        vcdp->fullBit(c+825,(vlTOPp->D7_in));
        vcdp->fullBit(c+833,(vlTOPp->D8_in));
        vcdp->fullBit(c+841,(vlTOPp->D9_in));
        vcdp->fullBit(c+849,(vlTOPp->D10_in));
        vcdp->fullBit(c+857,(vlTOPp->D11_in));
        vcdp->fullBit(c+865,(vlTOPp->D12_in));
        vcdp->fullBit(c+873,(vlTOPp->D13_in));
        vcdp->fullBit(c+881,(vlTOPp->D14_in));
        vcdp->fullBit(c+889,(vlTOPp->D15_in));
        vcdp->fullBus(c+897,((((IData)(vlTOPp->D15_in) 
                               << 0xfU) | (((IData)(vlTOPp->D14_in) 
                                            << 0xeU) 
                                           | (((IData)(vlTOPp->D13_in) 
                                               << 0xdU) 
                                              | (((IData)(vlTOPp->D12_in) 
                                                  << 0xcU) 
                                                 | (((IData)(vlTOPp->D11_in) 
                                                     << 0xbU) 
                                                    | (((IData)(vlTOPp->D10_in) 
                                                        << 0xaU) 
                                                       | (((IData)(vlTOPp->D9_in) 
                                                           << 9U) 
                                                          | (((IData)(vlTOPp->D8_in) 
                                                              << 8U) 
                                                             | (((IData)(vlTOPp->D7_in) 
                                                                 << 7U) 
                                                                | (((IData)(vlTOPp->D6_in) 
                                                                    << 6U) 
                                                                   | (((IData)(vlTOPp->D5_in) 
                                                                       << 5U) 
                                                                      | (((IData)(vlTOPp->D4_in) 
                                                                          << 4U) 
                                                                         | (((IData)(vlTOPp->D3_in) 
                                                                             << 3U) 
                                                                            | (((IData)(vlTOPp->D2_in) 
                                                                                << 2U) 
                                                                               | (((IData)(vlTOPp->D1_in) 
                                                                                << 1U) 
                                                                                | (IData)(vlTOPp->D0_in))))))))))))))))),16);
        vcdp->fullBus(c+905,(0U),32);
        vcdp->fullBus(c+913,(vlTOPp->top__DOT__hreg),16);
        vcdp->fullBus(c+921,(vlTOPp->top__DOT__romOut),16);
        vcdp->fullBus(c+929,(vlTOPp->top__DOT__gpuOut),16);
        vcdp->fullBus(c+937,(vlTOPp->top__DOT__apuOut),16);
        vcdp->fullBus(c+945,(vlTOPp->top__DOT__clkOut),16);
        vcdp->fullBus(c+953,(vlTOPp->top__DOT__din),16);
        vcdp->fullBus(c+961,(vlTOPp->top__DOT__dout),16);
        vcdp->fullBus(c+969,(0U),3);
        vcdp->fullBus(c+977,(1U),3);
        vcdp->fullBus(c+985,(0U),6);
        vcdp->fullBus(c+993,(0U),4);
        vcdp->fullBus(c+1001,(2U),32);
        vcdp->fullBus(c+1009,(0U),5);
        vcdp->fullBit(c+1017,(0U));
    }
}
