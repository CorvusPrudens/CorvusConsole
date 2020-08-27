// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+80,"CLK", false,-1);
        tracep->declBit(c+81,"RX", false,-1);
        tracep->declBit(c+82,"TX", false,-1);
        tracep->declBit(c+83,"GPIO3", false,-1);
        tracep->declBit(c+84,"GPIO9", false,-1);
        tracep->declBit(c+85,"GPIO11", false,-1);
        tracep->declBit(c+86,"CE", false,-1);
        tracep->declBit(c+87,"OE", false,-1);
        tracep->declBit(c+88,"WR", false,-1);
        tracep->declBit(c+89,"UB", false,-1);
        tracep->declBit(c+90,"LB", false,-1);
        tracep->declBit(c+91,"A0", false,-1);
        tracep->declBit(c+92,"A1", false,-1);
        tracep->declBit(c+93,"A2", false,-1);
        tracep->declBit(c+94,"A3", false,-1);
        tracep->declBit(c+95,"A4", false,-1);
        tracep->declBit(c+96,"A5", false,-1);
        tracep->declBit(c+97,"A6", false,-1);
        tracep->declBit(c+98,"A7", false,-1);
        tracep->declBit(c+99,"A8", false,-1);
        tracep->declBit(c+100,"A9", false,-1);
        tracep->declBit(c+101,"A10", false,-1);
        tracep->declBit(c+102,"A11", false,-1);
        tracep->declBit(c+103,"A12", false,-1);
        tracep->declBit(c+104,"A13", false,-1);
        tracep->declBit(c+105,"A14", false,-1);
        tracep->declBit(c+106,"A15", false,-1);
        tracep->declBit(c+107,"D0", false,-1);
        tracep->declBit(c+108,"D1", false,-1);
        tracep->declBit(c+109,"D2", false,-1);
        tracep->declBit(c+110,"D3", false,-1);
        tracep->declBit(c+111,"D4", false,-1);
        tracep->declBit(c+112,"D5", false,-1);
        tracep->declBit(c+113,"D6", false,-1);
        tracep->declBit(c+114,"D7", false,-1);
        tracep->declBit(c+115,"D8", false,-1);
        tracep->declBit(c+116,"D9", false,-1);
        tracep->declBit(c+117,"D10", false,-1);
        tracep->declBit(c+118,"D11", false,-1);
        tracep->declBit(c+119,"D12", false,-1);
        tracep->declBit(c+120,"D13", false,-1);
        tracep->declBit(c+121,"D14", false,-1);
        tracep->declBit(c+122,"D15", false,-1);
        tracep->declBit(c+123,"D0_in", false,-1);
        tracep->declBit(c+124,"D1_in", false,-1);
        tracep->declBit(c+125,"D2_in", false,-1);
        tracep->declBit(c+126,"D3_in", false,-1);
        tracep->declBit(c+127,"D4_in", false,-1);
        tracep->declBit(c+128,"D5_in", false,-1);
        tracep->declBit(c+129,"D6_in", false,-1);
        tracep->declBit(c+130,"D7_in", false,-1);
        tracep->declBit(c+131,"D8_in", false,-1);
        tracep->declBit(c+132,"D9_in", false,-1);
        tracep->declBit(c+133,"D10_in", false,-1);
        tracep->declBit(c+134,"D11_in", false,-1);
        tracep->declBit(c+135,"D12_in", false,-1);
        tracep->declBit(c+136,"D13_in", false,-1);
        tracep->declBit(c+137,"D14_in", false,-1);
        tracep->declBit(c+138,"D15_in", false,-1);
        tracep->declBit(c+80,"top CLK", false,-1);
        tracep->declBit(c+81,"top RX", false,-1);
        tracep->declBit(c+82,"top TX", false,-1);
        tracep->declBit(c+83,"top GPIO3", false,-1);
        tracep->declBit(c+84,"top GPIO9", false,-1);
        tracep->declBit(c+85,"top GPIO11", false,-1);
        tracep->declBit(c+86,"top CE", false,-1);
        tracep->declBit(c+87,"top OE", false,-1);
        tracep->declBit(c+88,"top WR", false,-1);
        tracep->declBit(c+89,"top UB", false,-1);
        tracep->declBit(c+90,"top LB", false,-1);
        tracep->declBit(c+91,"top A0", false,-1);
        tracep->declBit(c+92,"top A1", false,-1);
        tracep->declBit(c+93,"top A2", false,-1);
        tracep->declBit(c+94,"top A3", false,-1);
        tracep->declBit(c+95,"top A4", false,-1);
        tracep->declBit(c+96,"top A5", false,-1);
        tracep->declBit(c+97,"top A6", false,-1);
        tracep->declBit(c+98,"top A7", false,-1);
        tracep->declBit(c+99,"top A8", false,-1);
        tracep->declBit(c+100,"top A9", false,-1);
        tracep->declBit(c+101,"top A10", false,-1);
        tracep->declBit(c+102,"top A11", false,-1);
        tracep->declBit(c+103,"top A12", false,-1);
        tracep->declBit(c+104,"top A13", false,-1);
        tracep->declBit(c+105,"top A14", false,-1);
        tracep->declBit(c+106,"top A15", false,-1);
        tracep->declBit(c+107,"top D0", false,-1);
        tracep->declBit(c+108,"top D1", false,-1);
        tracep->declBit(c+109,"top D2", false,-1);
        tracep->declBit(c+110,"top D3", false,-1);
        tracep->declBit(c+111,"top D4", false,-1);
        tracep->declBit(c+112,"top D5", false,-1);
        tracep->declBit(c+113,"top D6", false,-1);
        tracep->declBit(c+114,"top D7", false,-1);
        tracep->declBit(c+115,"top D8", false,-1);
        tracep->declBit(c+116,"top D9", false,-1);
        tracep->declBit(c+117,"top D10", false,-1);
        tracep->declBit(c+118,"top D11", false,-1);
        tracep->declBit(c+119,"top D12", false,-1);
        tracep->declBit(c+120,"top D13", false,-1);
        tracep->declBit(c+121,"top D14", false,-1);
        tracep->declBit(c+122,"top D15", false,-1);
        tracep->declBit(c+123,"top D0_in", false,-1);
        tracep->declBit(c+124,"top D1_in", false,-1);
        tracep->declBit(c+125,"top D2_in", false,-1);
        tracep->declBit(c+126,"top D3_in", false,-1);
        tracep->declBit(c+127,"top D4_in", false,-1);
        tracep->declBit(c+128,"top D5_in", false,-1);
        tracep->declBit(c+129,"top D6_in", false,-1);
        tracep->declBit(c+130,"top D7_in", false,-1);
        tracep->declBit(c+131,"top D8_in", false,-1);
        tracep->declBit(c+132,"top D9_in", false,-1);
        tracep->declBit(c+133,"top D10_in", false,-1);
        tracep->declBit(c+134,"top D11_in", false,-1);
        tracep->declBit(c+135,"top D12_in", false,-1);
        tracep->declBit(c+136,"top D13_in", false,-1);
        tracep->declBit(c+137,"top D14_in", false,-1);
        tracep->declBit(c+138,"top D15_in", false,-1);
        tracep->declBus(c+140,"top testWord", false,-1, 31,0);
        tracep->declBit(c+141,"top testClock", false,-1);
        tracep->declBus(c+1,"top busState", false,-1, 3,0);
        tracep->declBus(c+2,"top aluOperand1", false,-1, 2,0);
        tracep->declBus(c+3,"top aluOperand2", false,-1, 2,0);
        tracep->declBus(c+4,"top aluResults", false,-1, 2,0);
        tracep->declBus(c+5,"top aluOperation", false,-1, 5,0);
        tracep->declBus(c+6,"top aluParams", false,-1, 3,0);
        tracep->declBit(c+7,"top aluReadBus", false,-1);
        tracep->declBit(c+8,"top ramWrite", false,-1);
        tracep->declBus(c+36,"top greg", false,-1, 15,0);
        tracep->declBus(c+9,"top ramAddress", false,-1, 15,0);
        tracep->declBus(c+37,"top romAddress", false,-1, 15,0);
        tracep->declBus(c+38,"top ctrlOut", false,-1, 15,0);
        tracep->declBus(c+39,"top controlWord", false,-1, 31,0);
        tracep->declBus(c+75,"top aluOut", false,-1, 15,0);
        tracep->declBus(c+139,"top ramOut", false,-1, 15,0);
        tracep->declBus(c+142,"top romOut", false,-1, 15,0);
        tracep->declBus(c+143,"top gpuOut", false,-1, 15,0);
        tracep->declBus(c+144,"top apuOut", false,-1, 15,0);
        tracep->declBus(c+145,"top clkOut", false,-1, 15,0);
        tracep->declBus(c+68,"top bus", false,-1, 15,0);
        tracep->declBit(c+10,"top MEMstatus", false,-1);
        tracep->declBit(c+11,"top MEMuart", false,-1);
        tracep->declBit(c+12,"top MEMaddrstack", false,-1);
        tracep->declBit(c+13,"top MEMuserstack", false,-1);
        tracep->declBit(c+14,"top MEMgpio", false,-1);
        tracep->declBit(c+15,"top MEMgpiodir", false,-1);
        tracep->declBit(c+8,"top MEMwrite", false,-1);
        tracep->declBus(c+69,"top MEMbus", false,-1, 15,0);
        tracep->declBus(c+68,"top MEMout", false,-1, 15,0);
        tracep->declBus(c+40,"top uartOut", false,-1, 15,0);
        tracep->declBus(c+146,"top statusOut", false,-1, 15,0);
        tracep->declBus(c+147,"top addrstackOut", false,-1, 15,0);
        tracep->declBus(c+148,"top userstackOut", false,-1, 15,0);
        tracep->declBus(c+149,"top gpioOut", false,-1, 15,0);
        tracep->declBus(c+150,"top gpiodirOut", false,-1, 15,0);
        tracep->declBus(c+16,"top MEMstate", false,-1, 6,0);
        tracep->declBus(c+151,"top din", false,-1, 15,0);
        tracep->declBus(c+152,"top dout", false,-1, 15,0);
        tracep->declBus(c+153,"top a", false,-1, 2,0);
        tracep->declBus(c+154,"top b", false,-1, 2,0);
        tracep->declBus(c+153,"top y", false,-1, 2,0);
        tracep->declBus(c+155,"top operation", false,-1, 5,0);
        tracep->declBus(c+156,"top params", false,-1, 3,0);
        tracep->declBit(c+41,"top overflow", false,-1);
        tracep->declBus(c+156,"top testState", false,-1, 3,0);
        tracep->declBus(c+42,"top clkdiv", false,-1, 24,0);
        tracep->declBit(c+80,"top CONTROL CLK", false,-1);
        tracep->declBus(c+2,"top CONTROL operand1", false,-1, 2,0);
        tracep->declBus(c+3,"top CONTROL operand2", false,-1, 2,0);
        tracep->declBus(c+4,"top CONTROL results", false,-1, 2,0);
        tracep->declBus(c+5,"top CONTROL aluOperation", false,-1, 5,0);
        tracep->declBus(c+6,"top CONTROL aluParams", false,-1, 3,0);
        tracep->declBus(c+1,"top CONTROL busState", false,-1, 3,0);
        tracep->declBit(c+7,"top CONTROL aluReadBus", false,-1);
        tracep->declBit(c+8,"top CONTROL ramWrite", false,-1);
        tracep->declBus(c+43,"top CONTROL hreg", false,-1, 15,0);
        tracep->declBus(c+9,"top CONTROL ramAdd", false,-1, 15,0);
        tracep->declBus(c+37,"top CONTROL romAdd", false,-1, 15,0);
        tracep->declBus(c+38,"top CONTROL dout", false,-1, 15,0);
        tracep->declBus(c+39,"top CONTROL controlWord", false,-1, 31,0);
        tracep->declBus(c+157,"top CONTROL flags", false,-1, 4,0);
        tracep->declBus(c+17,"top CONTROL increment", false,-1, 1,0);
        tracep->declBit(c+18,"top CONTROL ramAddMode", false,-1);
        tracep->declBus(c+9,"top CONTROL ramAddReg", false,-1, 15,0);
        tracep->declBus(c+37,"top CONTROL programCounter", false,-1, 15,0);
        tracep->declBus(c+44,"top CONTROL opvar", false,-1, 1,0);
        tracep->declBus(c+45,"top CONTROL opcode", false,-1, 4,0);
        tracep->declBus(c+46,"top CONTROL operand1Wire", false,-1, 2,0);
        tracep->declBus(c+47,"top CONTROL operand2Wire", false,-1, 2,0);
        tracep->declBus(c+48,"top CONTROL resultsWire", false,-1, 2,0);
        tracep->declBus(c+38,"top CONTROL word2Wire", false,-1, 15,0);
        tracep->declBit(c+80,"top ROM CLK", false,-1);
        tracep->declBus(c+37,"top ROM address", false,-1, 15,0);
        tracep->declBus(c+39,"top ROM data", false,-1, 31,0);
        tracep->declBit(c+80,"top ROM ROMDATA CLK", false,-1);
        tracep->declBus(c+37,"top ROM ROMDATA address", false,-1, 15,0);
        tracep->declBus(c+39,"top ROM ROMDATA data", false,-1, 31,0);
        tracep->declBus(c+39,"top ROM ROMDATA dintern", false,-1, 31,0);
        tracep->declBit(c+80,"top ALU CLK", false,-1);
        tracep->declBit(c+7,"top ALU readBus", false,-1);
        tracep->declBus(c+68,"top ALU din", false,-1, 15,0);
        tracep->declBus(c+75,"top ALU dout", false,-1, 15,0);
        tracep->declBus(c+2,"top ALU operandIndex1", false,-1, 2,0);
        tracep->declBus(c+3,"top ALU operandIndex2", false,-1, 2,0);
        tracep->declBus(c+4,"top ALU resultsIndex", false,-1, 2,0);
        tracep->declBus(c+5,"top ALU operation", false,-1, 5,0);
        tracep->declBus(c+6,"top ALU params", false,-1, 3,0);
        tracep->declBit(c+41,"top ALU overflow", false,-1);
        tracep->declBus(c+49,"top ALU a", false,-1, 15,0);
        tracep->declBus(c+50,"top ALU b", false,-1, 15,0);
        tracep->declBus(c+51,"top ALU c", false,-1, 15,0);
        tracep->declBus(c+52,"top ALU d", false,-1, 15,0);
        tracep->declBus(c+53,"top ALU e", false,-1, 15,0);
        tracep->declBus(c+54,"top ALU f", false,-1, 15,0);
        tracep->declBus(c+36,"top ALU g", false,-1, 15,0);
        tracep->declBus(c+43,"top ALU h", false,-1, 15,0);
        tracep->declBus(c+70,"top ALU addsub", false,-1, 16,0);
        tracep->declBus(c+71,"top ALU mult", false,-1, 16,0);
        tracep->declBus(c+72,"top ALU log", false,-1, 15,0);
        tracep->declBus(c+76,"top ALU lshift", false,-1, 15,0);
        tracep->declBus(c+77,"top ALU rshift", false,-1, 15,0);
        tracep->declBus(c+75,"top ALU operand1", false,-1, 15,0);
        tracep->declBus(c+78,"top ALU operand2", false,-1, 15,0);
        tracep->declBus(c+73,"top ALU combOperand2", false,-1, 15,0);
        tracep->declBit(c+80,"top RAM CLK", false,-1);
        tracep->declBus(c+9,"top RAM address", false,-1, 15,0);
        tracep->declBus(c+68,"top RAM dataIn", false,-1, 15,0);
        tracep->declBit(c+8,"top RAM write", false,-1);
        tracep->declBus(c+139,"top RAM dataOut", false,-1, 15,0);
        tracep->declBus(c+69,"top RAM memIn", false,-1, 15,0);
        tracep->declBus(c+68,"top RAM memOut", false,-1, 15,0);
        tracep->declBit(c+86,"top RAM CE", false,-1);
        tracep->declBit(c+87,"top RAM OE", false,-1);
        tracep->declBit(c+88,"top RAM WR", false,-1);
        tracep->declBit(c+89,"top RAM UB", false,-1);
        tracep->declBit(c+90,"top RAM LB", false,-1);
        tracep->declBit(c+91,"top RAM A0", false,-1);
        tracep->declBit(c+92,"top RAM A1", false,-1);
        tracep->declBit(c+93,"top RAM A2", false,-1);
        tracep->declBit(c+94,"top RAM A3", false,-1);
        tracep->declBit(c+95,"top RAM A4", false,-1);
        tracep->declBit(c+96,"top RAM A5", false,-1);
        tracep->declBit(c+97,"top RAM A6", false,-1);
        tracep->declBit(c+98,"top RAM A7", false,-1);
        tracep->declBit(c+99,"top RAM A8", false,-1);
        tracep->declBit(c+100,"top RAM A9", false,-1);
        tracep->declBit(c+101,"top RAM A10", false,-1);
        tracep->declBit(c+102,"top RAM A11", false,-1);
        tracep->declBit(c+103,"top RAM A12", false,-1);
        tracep->declBit(c+104,"top RAM A13", false,-1);
        tracep->declBit(c+105,"top RAM A14", false,-1);
        tracep->declBit(c+106,"top RAM A15", false,-1);
        tracep->declBit(c+107,"top RAM D0", false,-1);
        tracep->declBit(c+108,"top RAM D1", false,-1);
        tracep->declBit(c+109,"top RAM D2", false,-1);
        tracep->declBit(c+110,"top RAM D3", false,-1);
        tracep->declBit(c+111,"top RAM D4", false,-1);
        tracep->declBit(c+112,"top RAM D5", false,-1);
        tracep->declBit(c+113,"top RAM D6", false,-1);
        tracep->declBit(c+114,"top RAM D7", false,-1);
        tracep->declBit(c+115,"top RAM D8", false,-1);
        tracep->declBit(c+116,"top RAM D9", false,-1);
        tracep->declBit(c+117,"top RAM D10", false,-1);
        tracep->declBit(c+118,"top RAM D11", false,-1);
        tracep->declBit(c+119,"top RAM D12", false,-1);
        tracep->declBit(c+120,"top RAM D13", false,-1);
        tracep->declBit(c+121,"top RAM D14", false,-1);
        tracep->declBit(c+122,"top RAM D15", false,-1);
        tracep->declBit(c+123,"top RAM D0_in", false,-1);
        tracep->declBit(c+124,"top RAM D1_in", false,-1);
        tracep->declBit(c+125,"top RAM D2_in", false,-1);
        tracep->declBit(c+126,"top RAM D3_in", false,-1);
        tracep->declBit(c+127,"top RAM D4_in", false,-1);
        tracep->declBit(c+128,"top RAM D5_in", false,-1);
        tracep->declBit(c+129,"top RAM D6_in", false,-1);
        tracep->declBit(c+130,"top RAM D7_in", false,-1);
        tracep->declBit(c+131,"top RAM D8_in", false,-1);
        tracep->declBit(c+132,"top RAM D9_in", false,-1);
        tracep->declBit(c+133,"top RAM D10_in", false,-1);
        tracep->declBit(c+134,"top RAM D11_in", false,-1);
        tracep->declBit(c+135,"top RAM D12_in", false,-1);
        tracep->declBit(c+136,"top RAM D13_in", false,-1);
        tracep->declBit(c+137,"top RAM D14_in", false,-1);
        tracep->declBit(c+138,"top RAM D15_in", false,-1);
        tracep->declBit(c+10,"top RAM status", false,-1);
        tracep->declBit(c+11,"top RAM uart", false,-1);
        tracep->declBit(c+12,"top RAM addrstack", false,-1);
        tracep->declBit(c+13,"top RAM userstack", false,-1);
        tracep->declBit(c+14,"top RAM gpio", false,-1);
        tracep->declBit(c+15,"top RAM gpiodir", false,-1);
        tracep->declBit(c+8,"top RAM memwrite", false,-1);
        tracep->declBit(c+158,"top RAM writeToggle", false,-1);
        tracep->declBit(c+158,"top RAM writePulse", false,-1);
        tracep->declBit(c+19,"top RAM memmap", false,-1);
        tracep->declBit(c+80,"top UART CLK", false,-1);
        tracep->declBus(c+74,"top UART dataIn", false,-1, 7,0);
        tracep->declBit(c+20,"top UART write", false,-1);
        tracep->declBit(c+11,"top UART read", false,-1);
        tracep->declBus(c+40,"top UART dataOut", false,-1, 15,0);
        tracep->declBit(c+81,"top UART RX", false,-1);
        tracep->declBit(c+82,"top UART TX", false,-1);
        tracep->declBus(c+55,"top UART dataOutReg", false,-1, 7,0);
        tracep->declBit(c+159,"top UART uartread", false,-1);
        tracep->declBit(c+56,"top UART uartdone", false,-1);
        tracep->declBus(c+57,"top UART uartin", false,-1, 7,0);
        tracep->declBus(c+21,"top UART uartout", false,-1, 7,0);
        tracep->declBit(c+22,"top UART uartoutwrite", false,-1);
        tracep->declBit(c+23,"top UART TXbusy", false,-1);
        tracep->declBit(c+58,"top UART outfull", false,-1);
        tracep->declBit(c+59,"top UART full", false,-1);
        tracep->declBit(c+60,"top UART empty", false,-1);
        tracep->declBit(c+61,"top UART sendState", false,-1);
        tracep->declBit(c+62,"top UART sendRead", false,-1);
        tracep->declBit(c+63,"top UART TXstart", false,-1);
        tracep->declBit(c+80,"top UART INFIFO CLK", false,-1);
        tracep->declBus(c+74,"top UART INFIFO dataIn", false,-1, 7,0);
        tracep->declBit(c+20,"top UART INFIFO write", false,-1);
        tracep->declBit(c+62,"top UART INFIFO read", false,-1);
        tracep->declBus(c+57,"top UART INFIFO dataOut", false,-1, 7,0);
        tracep->declBit(c+59,"top UART INFIFO full", false,-1);
        tracep->declBit(c+56,"top UART INFIFO empty", false,-1);
        tracep->declBus(c+64,"top UART INFIFO idx0", false,-1, 7,0);
        tracep->declBus(c+65,"top UART INFIFO idxn", false,-1, 7,0);
        tracep->declBus(c+24,"top UART INFIFO idx0prev", false,-1, 7,0);
        tracep->declBus(c+25,"top UART INFIFO idxnprev", false,-1, 7,0);
        tracep->declBit(c+80,"top UART UART CLK", false,-1);
        tracep->declBit(c+81,"top UART UART RX", false,-1);
        tracep->declBus(c+57,"top UART UART TXbuffer", false,-1, 7,0);
        tracep->declBit(c+63,"top UART UART TXstart", false,-1);
        tracep->declBit(c+82,"top UART UART TX", false,-1);
        tracep->declBus(c+21,"top UART UART RXbuffer", false,-1, 7,0);
        tracep->declBit(c+22,"top UART UART RXready", false,-1);
        tracep->declBit(c+23,"top UART UART TXbusy", false,-1);
        tracep->declBus(c+160,"top UART UART CLOCK_DIVISOR", false,-1, 31,0);
        tracep->declBus(c+26,"top UART UART baudAcc", false,-1, 2,0);
        tracep->declBit(c+27,"top UART UART baudTick", false,-1);
        tracep->declBus(c+28,"top UART UART TXstate", false,-1, 3,0);
        tracep->declBit(c+29,"top UART UART TXready", false,-1);
        tracep->declBus(c+30,"top UART UART TXshift", false,-1, 7,0);
        tracep->declBus(c+31,"top UART UART RXstate", false,-1, 3,0);
        tracep->declBus(c+32,"top UART UART gap", false,-1, 2,0);
        tracep->declBit(c+33,"top UART UART nextBit", false,-1);
        tracep->declBit(c+80,"top UART OUTFIFO CLK", false,-1);
        tracep->declBus(c+21,"top UART OUTFIFO dataIn", false,-1, 7,0);
        tracep->declBit(c+22,"top UART OUTFIFO write", false,-1);
        tracep->declBit(c+79,"top UART OUTFIFO read", false,-1);
        tracep->declBus(c+55,"top UART OUTFIFO dataOut", false,-1, 7,0);
        tracep->declBit(c+58,"top UART OUTFIFO full", false,-1);
        tracep->declBit(c+60,"top UART OUTFIFO empty", false,-1);
        tracep->declBus(c+66,"top UART OUTFIFO idx0", false,-1, 7,0);
        tracep->declBus(c+67,"top UART OUTFIFO idxn", false,-1, 7,0);
        tracep->declBus(c+34,"top UART OUTFIFO idx0prev", false,-1, 7,0);
        tracep->declBus(c+35,"top UART OUTFIFO idxnprev", false,-1, 7,0);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->top__DOT__busState),4);
        tracep->fullCData(oldp+2,(vlTOPp->top__DOT__aluOperand1),3);
        tracep->fullCData(oldp+3,(vlTOPp->top__DOT__aluOperand2),3);
        tracep->fullCData(oldp+4,(vlTOPp->top__DOT__aluResults),3);
        tracep->fullCData(oldp+5,(vlTOPp->top__DOT__aluOperation),6);
        tracep->fullCData(oldp+6,(vlTOPp->top__DOT__aluParams),4);
        tracep->fullBit(oldp+7,(vlTOPp->top__DOT__aluReadBus));
        tracep->fullBit(oldp+8,(vlTOPp->top__DOT__ramWrite));
        tracep->fullSData(oldp+9,(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg),16);
        tracep->fullBit(oldp+10,((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
        tracep->fullBit(oldp+11,((3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
        tracep->fullBit(oldp+12,((1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
        tracep->fullBit(oldp+13,((2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
        tracep->fullBit(oldp+14,((4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
        tracep->fullBit(oldp+15,((5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
        tracep->fullCData(oldp+16,(vlTOPp->top__DOT__MEMstate),7);
        tracep->fullCData(oldp+17,(vlTOPp->top__DOT__CONTROL__DOT__increment),2);
        tracep->fullBit(oldp+18,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
        tracep->fullBit(oldp+19,(((((((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                      | (1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                     | (2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                    | (3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                   | (4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                  | (5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)))));
        tracep->fullBit(oldp+20,(vlTOPp->top__DOT____Vcellinp__UART__write));
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__UART__DOT__uartout),8);
        tracep->fullBit(oldp+22,(vlTOPp->top__DOT__UART__DOT__uartoutwrite));
        tracep->fullBit(oldp+23,((0U != (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))));
        tracep->fullCData(oldp+24,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0prev),8);
        tracep->fullCData(oldp+25,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxnprev),8);
        tracep->fullCData(oldp+26,(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc),3);
        tracep->fullBit(oldp+27,((1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc) 
                                        >> 2U))));
        tracep->fullCData(oldp+28,(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate),4);
        tracep->fullBit(oldp+29,((0U == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))));
        tracep->fullCData(oldp+30,(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift),8);
        tracep->fullCData(oldp+31,(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate),4);
        tracep->fullCData(oldp+32,(vlTOPp->top__DOT__UART__DOT__UART__DOT__gap),3);
        tracep->fullBit(oldp+33,((1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__gap) 
                                        >> 2U))));
        tracep->fullCData(oldp+34,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0prev),8);
        tracep->fullCData(oldp+35,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxnprev),8);
        tracep->fullSData(oldp+36,(vlTOPp->top__DOT__ALU__DOT__g),16);
        tracep->fullSData(oldp+37,(vlTOPp->top__DOT__CONTROL__DOT__programCounter),16);
        tracep->fullSData(oldp+38,((0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                               >> 0x10U))),16);
        tracep->fullIData(oldp+39,(vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern),32);
        tracep->fullSData(oldp+40,((((IData)(vlTOPp->top__DOT__UART__DOT__empty) 
                                     << 9U) | (((1U 
                                                 == 
                                                 (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                                     - (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn)))) 
                                                << 8U) 
                                               | (IData)(vlTOPp->top__DOT__UART__DOT__dataOutReg)))),16);
        tracep->fullBit(oldp+41,(vlTOPp->top__DOT__overflow));
        tracep->fullIData(oldp+42,(vlTOPp->top__DOT__clkdiv),25);
        tracep->fullSData(oldp+43,(vlTOPp->top__DOT__ALU__DOT__h),16);
        tracep->fullCData(oldp+44,((3U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)),2);
        tracep->fullCData(oldp+45,((0x1fU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                             >> 2U))),5);
        tracep->fullCData(oldp+46,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                          >> 7U))),3);
        tracep->fullCData(oldp+47,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                          >> 0xaU))),3);
        tracep->fullCData(oldp+48,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                          >> 0xdU))),3);
        tracep->fullSData(oldp+49,(vlTOPp->top__DOT__ALU__DOT__a),16);
        tracep->fullSData(oldp+50,(vlTOPp->top__DOT__ALU__DOT__b),16);
        tracep->fullSData(oldp+51,(vlTOPp->top__DOT__ALU__DOT__c),16);
        tracep->fullSData(oldp+52,(vlTOPp->top__DOT__ALU__DOT__d),16);
        tracep->fullSData(oldp+53,(vlTOPp->top__DOT__ALU__DOT__e),16);
        tracep->fullSData(oldp+54,(vlTOPp->top__DOT__ALU__DOT__f),16);
        tracep->fullCData(oldp+55,(vlTOPp->top__DOT__UART__DOT__dataOutReg),8);
        tracep->fullBit(oldp+56,(((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                  == (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn))));
        tracep->fullCData(oldp+57,(vlTOPp->top__DOT__UART__DOT__uartin),8);
        tracep->fullBit(oldp+58,((1U == (0xffU & ((IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0) 
                                                  - (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn))))));
        tracep->fullBit(oldp+59,((1U == (0xffU & ((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                                  - (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn))))));
        tracep->fullBit(oldp+60,(vlTOPp->top__DOT__UART__DOT__empty));
        tracep->fullBit(oldp+61,(vlTOPp->top__DOT__UART__DOT__sendState));
        tracep->fullBit(oldp+62,(vlTOPp->top__DOT__UART__DOT__sendRead));
        tracep->fullBit(oldp+63,(vlTOPp->top__DOT__UART__DOT__TXstart));
        tracep->fullCData(oldp+64,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0),8);
        tracep->fullCData(oldp+65,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn),8);
        tracep->fullCData(oldp+66,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0),8);
        tracep->fullCData(oldp+67,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn),8);
        tracep->fullSData(oldp+68,(vlTOPp->top__DOT__bus),16);
        tracep->fullSData(oldp+69,(vlTOPp->top__DOT__MEMbus),16);
        tracep->fullIData(oldp+70,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        tracep->fullIData(oldp+71,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        tracep->fullSData(oldp+72,(vlTOPp->top__DOT__ALU__DOT__log),16);
        tracep->fullSData(oldp+73,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
        tracep->fullCData(oldp+74,((0xffU & (IData)(vlTOPp->top__DOT__MEMbus))),8);
        tracep->fullSData(oldp+75,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
        tracep->fullSData(oldp+76,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
        tracep->fullSData(oldp+77,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
        tracep->fullSData(oldp+78,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
        tracep->fullBit(oldp+79,(vlTOPp->top__DOT__UART__DOT____Vcellinp__OUTFIFO__read));
        tracep->fullBit(oldp+80,(vlTOPp->CLK));
        tracep->fullBit(oldp+81,(vlTOPp->RX));
        tracep->fullBit(oldp+82,(vlTOPp->TX));
        tracep->fullBit(oldp+83,(vlTOPp->GPIO3));
        tracep->fullBit(oldp+84,(vlTOPp->GPIO9));
        tracep->fullBit(oldp+85,(vlTOPp->GPIO11));
        tracep->fullBit(oldp+86,(vlTOPp->CE));
        tracep->fullBit(oldp+87,(vlTOPp->OE));
        tracep->fullBit(oldp+88,(vlTOPp->WR));
        tracep->fullBit(oldp+89,(vlTOPp->UB));
        tracep->fullBit(oldp+90,(vlTOPp->LB));
        tracep->fullBit(oldp+91,(vlTOPp->A0));
        tracep->fullBit(oldp+92,(vlTOPp->A1));
        tracep->fullBit(oldp+93,(vlTOPp->A2));
        tracep->fullBit(oldp+94,(vlTOPp->A3));
        tracep->fullBit(oldp+95,(vlTOPp->A4));
        tracep->fullBit(oldp+96,(vlTOPp->A5));
        tracep->fullBit(oldp+97,(vlTOPp->A6));
        tracep->fullBit(oldp+98,(vlTOPp->A7));
        tracep->fullBit(oldp+99,(vlTOPp->A8));
        tracep->fullBit(oldp+100,(vlTOPp->A9));
        tracep->fullBit(oldp+101,(vlTOPp->A10));
        tracep->fullBit(oldp+102,(vlTOPp->A11));
        tracep->fullBit(oldp+103,(vlTOPp->A12));
        tracep->fullBit(oldp+104,(vlTOPp->A13));
        tracep->fullBit(oldp+105,(vlTOPp->A14));
        tracep->fullBit(oldp+106,(vlTOPp->A15));
        tracep->fullBit(oldp+107,(vlTOPp->D0));
        tracep->fullBit(oldp+108,(vlTOPp->D1));
        tracep->fullBit(oldp+109,(vlTOPp->D2));
        tracep->fullBit(oldp+110,(vlTOPp->D3));
        tracep->fullBit(oldp+111,(vlTOPp->D4));
        tracep->fullBit(oldp+112,(vlTOPp->D5));
        tracep->fullBit(oldp+113,(vlTOPp->D6));
        tracep->fullBit(oldp+114,(vlTOPp->D7));
        tracep->fullBit(oldp+115,(vlTOPp->D8));
        tracep->fullBit(oldp+116,(vlTOPp->D9));
        tracep->fullBit(oldp+117,(vlTOPp->D10));
        tracep->fullBit(oldp+118,(vlTOPp->D11));
        tracep->fullBit(oldp+119,(vlTOPp->D12));
        tracep->fullBit(oldp+120,(vlTOPp->D13));
        tracep->fullBit(oldp+121,(vlTOPp->D14));
        tracep->fullBit(oldp+122,(vlTOPp->D15));
        tracep->fullBit(oldp+123,(vlTOPp->D0_in));
        tracep->fullBit(oldp+124,(vlTOPp->D1_in));
        tracep->fullBit(oldp+125,(vlTOPp->D2_in));
        tracep->fullBit(oldp+126,(vlTOPp->D3_in));
        tracep->fullBit(oldp+127,(vlTOPp->D4_in));
        tracep->fullBit(oldp+128,(vlTOPp->D5_in));
        tracep->fullBit(oldp+129,(vlTOPp->D6_in));
        tracep->fullBit(oldp+130,(vlTOPp->D7_in));
        tracep->fullBit(oldp+131,(vlTOPp->D8_in));
        tracep->fullBit(oldp+132,(vlTOPp->D9_in));
        tracep->fullBit(oldp+133,(vlTOPp->D10_in));
        tracep->fullBit(oldp+134,(vlTOPp->D11_in));
        tracep->fullBit(oldp+135,(vlTOPp->D12_in));
        tracep->fullBit(oldp+136,(vlTOPp->D13_in));
        tracep->fullBit(oldp+137,(vlTOPp->D14_in));
        tracep->fullBit(oldp+138,(vlTOPp->D15_in));
        tracep->fullSData(oldp+139,((((IData)(vlTOPp->D15_in) 
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
        tracep->fullIData(oldp+140,(0U),32);
        tracep->fullBit(oldp+141,(1U));
        tracep->fullSData(oldp+142,(vlTOPp->top__DOT__romOut),16);
        tracep->fullSData(oldp+143,(vlTOPp->top__DOT__gpuOut),16);
        tracep->fullSData(oldp+144,(vlTOPp->top__DOT__apuOut),16);
        tracep->fullSData(oldp+145,(vlTOPp->top__DOT__clkOut),16);
        tracep->fullSData(oldp+146,(vlTOPp->top__DOT__statusOut),16);
        tracep->fullSData(oldp+147,(vlTOPp->top__DOT__addrstackOut),16);
        tracep->fullSData(oldp+148,(vlTOPp->top__DOT__userstackOut),16);
        tracep->fullSData(oldp+149,(vlTOPp->top__DOT__gpioOut),16);
        tracep->fullSData(oldp+150,(vlTOPp->top__DOT__gpiodirOut),16);
        tracep->fullSData(oldp+151,(vlTOPp->top__DOT__din),16);
        tracep->fullSData(oldp+152,(vlTOPp->top__DOT__dout),16);
        tracep->fullCData(oldp+153,(0U),3);
        tracep->fullCData(oldp+154,(1U),3);
        tracep->fullCData(oldp+155,(0U),6);
        tracep->fullCData(oldp+156,(0U),4);
        tracep->fullCData(oldp+157,(0U),5);
        tracep->fullBit(oldp+158,(0U));
        tracep->fullBit(oldp+159,(vlTOPp->top__DOT__UART__DOT__uartread));
        tracep->fullIData(oldp+160,(2U),32);
    }
}
