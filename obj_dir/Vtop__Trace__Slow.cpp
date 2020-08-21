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
        tracep->declBit(c+51,"CLK", false,-1);
        tracep->declBit(c+52,"RX", false,-1);
        tracep->declBit(c+53,"TX", false,-1);
        tracep->declBit(c+54,"GPIO3", false,-1);
        tracep->declBit(c+55,"GPIO9", false,-1);
        tracep->declBit(c+56,"GPIO11", false,-1);
        tracep->declBit(c+57,"CE", false,-1);
        tracep->declBit(c+58,"OE", false,-1);
        tracep->declBit(c+59,"WR", false,-1);
        tracep->declBit(c+60,"UB", false,-1);
        tracep->declBit(c+61,"LB", false,-1);
        tracep->declBit(c+62,"A0", false,-1);
        tracep->declBit(c+63,"A1", false,-1);
        tracep->declBit(c+64,"A2", false,-1);
        tracep->declBit(c+65,"A3", false,-1);
        tracep->declBit(c+66,"A4", false,-1);
        tracep->declBit(c+67,"A5", false,-1);
        tracep->declBit(c+68,"A6", false,-1);
        tracep->declBit(c+69,"A7", false,-1);
        tracep->declBit(c+70,"A8", false,-1);
        tracep->declBit(c+71,"A9", false,-1);
        tracep->declBit(c+72,"A10", false,-1);
        tracep->declBit(c+73,"A11", false,-1);
        tracep->declBit(c+74,"A12", false,-1);
        tracep->declBit(c+75,"A13", false,-1);
        tracep->declBit(c+76,"A14", false,-1);
        tracep->declBit(c+77,"A15", false,-1);
        tracep->declBit(c+78,"D0", false,-1);
        tracep->declBit(c+79,"D1", false,-1);
        tracep->declBit(c+80,"D2", false,-1);
        tracep->declBit(c+81,"D3", false,-1);
        tracep->declBit(c+82,"D4", false,-1);
        tracep->declBit(c+83,"D5", false,-1);
        tracep->declBit(c+84,"D6", false,-1);
        tracep->declBit(c+85,"D7", false,-1);
        tracep->declBit(c+86,"D8", false,-1);
        tracep->declBit(c+87,"D9", false,-1);
        tracep->declBit(c+88,"D10", false,-1);
        tracep->declBit(c+89,"D11", false,-1);
        tracep->declBit(c+90,"D12", false,-1);
        tracep->declBit(c+91,"D13", false,-1);
        tracep->declBit(c+92,"D14", false,-1);
        tracep->declBit(c+93,"D15", false,-1);
        tracep->declBit(c+94,"D0_in", false,-1);
        tracep->declBit(c+95,"D1_in", false,-1);
        tracep->declBit(c+96,"D2_in", false,-1);
        tracep->declBit(c+97,"D3_in", false,-1);
        tracep->declBit(c+98,"D4_in", false,-1);
        tracep->declBit(c+99,"D5_in", false,-1);
        tracep->declBit(c+100,"D6_in", false,-1);
        tracep->declBit(c+101,"D7_in", false,-1);
        tracep->declBit(c+102,"D8_in", false,-1);
        tracep->declBit(c+103,"D9_in", false,-1);
        tracep->declBit(c+104,"D10_in", false,-1);
        tracep->declBit(c+105,"D11_in", false,-1);
        tracep->declBit(c+106,"D12_in", false,-1);
        tracep->declBit(c+107,"D13_in", false,-1);
        tracep->declBit(c+108,"D14_in", false,-1);
        tracep->declBit(c+109,"D15_in", false,-1);
        tracep->declBit(c+51,"top CLK", false,-1);
        tracep->declBit(c+52,"top RX", false,-1);
        tracep->declBit(c+53,"top TX", false,-1);
        tracep->declBit(c+54,"top GPIO3", false,-1);
        tracep->declBit(c+55,"top GPIO9", false,-1);
        tracep->declBit(c+56,"top GPIO11", false,-1);
        tracep->declBit(c+57,"top CE", false,-1);
        tracep->declBit(c+58,"top OE", false,-1);
        tracep->declBit(c+59,"top WR", false,-1);
        tracep->declBit(c+60,"top UB", false,-1);
        tracep->declBit(c+61,"top LB", false,-1);
        tracep->declBit(c+62,"top A0", false,-1);
        tracep->declBit(c+63,"top A1", false,-1);
        tracep->declBit(c+64,"top A2", false,-1);
        tracep->declBit(c+65,"top A3", false,-1);
        tracep->declBit(c+66,"top A4", false,-1);
        tracep->declBit(c+67,"top A5", false,-1);
        tracep->declBit(c+68,"top A6", false,-1);
        tracep->declBit(c+69,"top A7", false,-1);
        tracep->declBit(c+70,"top A8", false,-1);
        tracep->declBit(c+71,"top A9", false,-1);
        tracep->declBit(c+72,"top A10", false,-1);
        tracep->declBit(c+73,"top A11", false,-1);
        tracep->declBit(c+74,"top A12", false,-1);
        tracep->declBit(c+75,"top A13", false,-1);
        tracep->declBit(c+76,"top A14", false,-1);
        tracep->declBit(c+77,"top A15", false,-1);
        tracep->declBit(c+78,"top D0", false,-1);
        tracep->declBit(c+79,"top D1", false,-1);
        tracep->declBit(c+80,"top D2", false,-1);
        tracep->declBit(c+81,"top D3", false,-1);
        tracep->declBit(c+82,"top D4", false,-1);
        tracep->declBit(c+83,"top D5", false,-1);
        tracep->declBit(c+84,"top D6", false,-1);
        tracep->declBit(c+85,"top D7", false,-1);
        tracep->declBit(c+86,"top D8", false,-1);
        tracep->declBit(c+87,"top D9", false,-1);
        tracep->declBit(c+88,"top D10", false,-1);
        tracep->declBit(c+89,"top D11", false,-1);
        tracep->declBit(c+90,"top D12", false,-1);
        tracep->declBit(c+91,"top D13", false,-1);
        tracep->declBit(c+92,"top D14", false,-1);
        tracep->declBit(c+93,"top D15", false,-1);
        tracep->declBit(c+94,"top D0_in", false,-1);
        tracep->declBit(c+95,"top D1_in", false,-1);
        tracep->declBit(c+96,"top D2_in", false,-1);
        tracep->declBit(c+97,"top D3_in", false,-1);
        tracep->declBit(c+98,"top D4_in", false,-1);
        tracep->declBit(c+99,"top D5_in", false,-1);
        tracep->declBit(c+100,"top D6_in", false,-1);
        tracep->declBit(c+101,"top D7_in", false,-1);
        tracep->declBit(c+102,"top D8_in", false,-1);
        tracep->declBit(c+103,"top D9_in", false,-1);
        tracep->declBit(c+104,"top D10_in", false,-1);
        tracep->declBit(c+105,"top D11_in", false,-1);
        tracep->declBit(c+106,"top D12_in", false,-1);
        tracep->declBit(c+107,"top D13_in", false,-1);
        tracep->declBit(c+108,"top D14_in", false,-1);
        tracep->declBit(c+109,"top D15_in", false,-1);
        tracep->declBus(c+1,"top RXbuffer", false,-1, 7,0);
        tracep->declBus(c+31,"top TXbuffer", false,-1, 7,0);
        tracep->declBit(c+32,"top TXstart", false,-1);
        tracep->declBit(c+2,"top RXready", false,-1);
        tracep->declBit(c+3,"top TXbusy", false,-1);
        tracep->declBus(c+33,"top testWord", false,-1, 31,0);
        tracep->declBit(c+34,"top testClock", false,-1);
        tracep->declBus(c+21,"top busState", false,-1, 3,0);
        tracep->declBus(c+22,"top aluOperand1", false,-1, 2,0);
        tracep->declBus(c+23,"top aluOperand2", false,-1, 2,0);
        tracep->declBus(c+24,"top aluResults", false,-1, 2,0);
        tracep->declBus(c+25,"top aluOperation", false,-1, 5,0);
        tracep->declBus(c+26,"top aluParams", false,-1, 3,0);
        tracep->declBit(c+27,"top aluReadBus", false,-1);
        tracep->declBit(c+28,"top ramWrite", false,-1);
        tracep->declBus(c+12,"top greg", false,-1, 15,0);
        tracep->declBus(c+114,"top hreg", false,-1, 15,0);
        tracep->declBus(c+110,"top ramAddress", false,-1, 15,0);
        tracep->declBus(c+115,"top romAddress", false,-1, 15,0);
        tracep->declBus(c+35,"top ctrlOut", false,-1, 15,0);
        tracep->declBus(c+42,"top aluOut", false,-1, 15,0);
        tracep->declBus(c+111,"top ramOut", false,-1, 15,0);
        tracep->declBus(c+116,"top romOut", false,-1, 15,0);
        tracep->declBus(c+117,"top gpuOut", false,-1, 15,0);
        tracep->declBus(c+118,"top apuOut", false,-1, 15,0);
        tracep->declBus(c+119,"top clkOut", false,-1, 15,0);
        tracep->declBus(c+46,"top bus", false,-1, 15,0);
        tracep->declBus(c+120,"top din", false,-1, 15,0);
        tracep->declBus(c+121,"top dout", false,-1, 15,0);
        tracep->declBus(c+122,"top a", false,-1, 2,0);
        tracep->declBus(c+123,"top b", false,-1, 2,0);
        tracep->declBus(c+122,"top y", false,-1, 2,0);
        tracep->declBus(c+124,"top operation", false,-1, 5,0);
        tracep->declBus(c+125,"top params", false,-1, 3,0);
        tracep->declBit(c+13,"top overflow", false,-1);
        tracep->declBus(c+36,"top testState", false,-1, 3,0);
        tracep->declBus(c+112,"top clkdiv", false,-1, 24,0);
        tracep->declBit(c+51,"top FTDI CLK", false,-1);
        tracep->declBit(c+52,"top FTDI RX", false,-1);
        tracep->declBus(c+31,"top FTDI TXbuffer", false,-1, 7,0);
        tracep->declBit(c+32,"top FTDI TXstart", false,-1);
        tracep->declBit(c+53,"top FTDI TX", false,-1);
        tracep->declBus(c+1,"top FTDI RXbuffer", false,-1, 7,0);
        tracep->declBit(c+2,"top FTDI RXready", false,-1);
        tracep->declBit(c+3,"top FTDI TXbusy", false,-1);
        tracep->declBus(c+126,"top FTDI CLOCK_DIVISOR", false,-1, 31,0);
        tracep->declBus(c+4,"top FTDI baudAcc", false,-1, 2,0);
        tracep->declBit(c+5,"top FTDI baudTick", false,-1);
        tracep->declBus(c+6,"top FTDI TXstate", false,-1, 3,0);
        tracep->declBit(c+7,"top FTDI TXready", false,-1);
        tracep->declBus(c+8,"top FTDI TXshift", false,-1, 7,0);
        tracep->declBus(c+9,"top FTDI RXstate", false,-1, 3,0);
        tracep->declBus(c+10,"top FTDI gap", false,-1, 2,0);
        tracep->declBit(c+11,"top FTDI nextBit", false,-1);
        tracep->declBit(c+34,"top CONTROL CLK", false,-1);
        tracep->declBus(c+22,"top CONTROL operand1", false,-1, 2,0);
        tracep->declBus(c+23,"top CONTROL operand2", false,-1, 2,0);
        tracep->declBus(c+24,"top CONTROL results", false,-1, 2,0);
        tracep->declBus(c+25,"top CONTROL aluOperation", false,-1, 5,0);
        tracep->declBus(c+26,"top CONTROL aluParams", false,-1, 3,0);
        tracep->declBus(c+21,"top CONTROL busState", false,-1, 3,0);
        tracep->declBit(c+27,"top CONTROL aluReadBus", false,-1);
        tracep->declBit(c+28,"top CONTROL ramWrite", false,-1);
        tracep->declBus(c+12,"top CONTROL greg", false,-1, 15,0);
        tracep->declBus(c+114,"top CONTROL hreg", false,-1, 15,0);
        tracep->declBus(c+110,"top CONTROL ramAdd", false,-1, 15,0);
        tracep->declBus(c+115,"top CONTROL romAdd", false,-1, 15,0);
        tracep->declBus(c+35,"top CONTROL dout", false,-1, 15,0);
        tracep->declBus(c+33,"top CONTROL testWord", false,-1, 31,0);
        tracep->declBus(c+127,"top CONTROL flags", false,-1, 4,0);
        tracep->declBit(c+29,"top CONTROL increment", false,-1);
        tracep->declBit(c+30,"top CONTROL ramAddMode", false,-1);
        tracep->declBus(c+14,"top CONTROL programCounter", false,-1, 15,0);
        tracep->declBus(c+33,"top CONTROL controlWord", false,-1, 31,0);
        tracep->declBus(c+37,"top CONTROL opvar", false,-1, 1,0);
        tracep->declBus(c+38,"top CONTROL opcode", false,-1, 4,0);
        tracep->declBus(c+39,"top CONTROL operand1Wire", false,-1, 2,0);
        tracep->declBus(c+40,"top CONTROL operand2Wire", false,-1, 2,0);
        tracep->declBus(c+41,"top CONTROL resultsWire", false,-1, 2,0);
        tracep->declBus(c+35,"top CONTROL word2Wire", false,-1, 15,0);
        tracep->declBit(c+34,"top ALU CLK", false,-1);
        tracep->declBit(c+27,"top ALU readBus", false,-1);
        tracep->declBus(c+46,"top ALU din", false,-1, 15,0);
        tracep->declBus(c+42,"top ALU dout", false,-1, 15,0);
        tracep->declBus(c+22,"top ALU operandIndex1", false,-1, 2,0);
        tracep->declBus(c+23,"top ALU operandIndex2", false,-1, 2,0);
        tracep->declBus(c+24,"top ALU resultsIndex", false,-1, 2,0);
        tracep->declBus(c+25,"top ALU operation", false,-1, 5,0);
        tracep->declBus(c+26,"top ALU params", false,-1, 3,0);
        tracep->declBit(c+13,"top ALU overflow", false,-1);
        tracep->declBus(c+113,"top ALU a", false,-1, 15,0);
        tracep->declBus(c+15,"top ALU b", false,-1, 15,0);
        tracep->declBus(c+16,"top ALU c", false,-1, 15,0);
        tracep->declBus(c+17,"top ALU d", false,-1, 15,0);
        tracep->declBus(c+18,"top ALU e", false,-1, 15,0);
        tracep->declBus(c+19,"top ALU f", false,-1, 15,0);
        tracep->declBus(c+12,"top ALU g", false,-1, 15,0);
        tracep->declBus(c+20,"top ALU h", false,-1, 15,0);
        tracep->declBus(c+47,"top ALU addsub", false,-1, 16,0);
        tracep->declBus(c+48,"top ALU mult", false,-1, 16,0);
        tracep->declBus(c+49,"top ALU log", false,-1, 15,0);
        tracep->declBus(c+43,"top ALU lshift", false,-1, 15,0);
        tracep->declBus(c+44,"top ALU rshift", false,-1, 15,0);
        tracep->declBus(c+42,"top ALU operand1", false,-1, 15,0);
        tracep->declBus(c+45,"top ALU operand2", false,-1, 15,0);
        tracep->declBus(c+50,"top ALU combOperand2", false,-1, 15,0);
        tracep->declBit(c+51,"top RAM CLK", false,-1);
        tracep->declBus(c+110,"top RAM address", false,-1, 15,0);
        tracep->declBus(c+46,"top RAM dataIn", false,-1, 15,0);
        tracep->declBit(c+28,"top RAM write", false,-1);
        tracep->declBus(c+111,"top RAM dataOut", false,-1, 15,0);
        tracep->declBit(c+57,"top RAM CE", false,-1);
        tracep->declBit(c+58,"top RAM OE", false,-1);
        tracep->declBit(c+59,"top RAM WR", false,-1);
        tracep->declBit(c+60,"top RAM UB", false,-1);
        tracep->declBit(c+61,"top RAM LB", false,-1);
        tracep->declBit(c+62,"top RAM A0", false,-1);
        tracep->declBit(c+63,"top RAM A1", false,-1);
        tracep->declBit(c+64,"top RAM A2", false,-1);
        tracep->declBit(c+65,"top RAM A3", false,-1);
        tracep->declBit(c+66,"top RAM A4", false,-1);
        tracep->declBit(c+67,"top RAM A5", false,-1);
        tracep->declBit(c+68,"top RAM A6", false,-1);
        tracep->declBit(c+69,"top RAM A7", false,-1);
        tracep->declBit(c+70,"top RAM A8", false,-1);
        tracep->declBit(c+71,"top RAM A9", false,-1);
        tracep->declBit(c+72,"top RAM A10", false,-1);
        tracep->declBit(c+73,"top RAM A11", false,-1);
        tracep->declBit(c+74,"top RAM A12", false,-1);
        tracep->declBit(c+75,"top RAM A13", false,-1);
        tracep->declBit(c+76,"top RAM A14", false,-1);
        tracep->declBit(c+77,"top RAM A15", false,-1);
        tracep->declBit(c+78,"top RAM D0", false,-1);
        tracep->declBit(c+79,"top RAM D1", false,-1);
        tracep->declBit(c+80,"top RAM D2", false,-1);
        tracep->declBit(c+81,"top RAM D3", false,-1);
        tracep->declBit(c+82,"top RAM D4", false,-1);
        tracep->declBit(c+83,"top RAM D5", false,-1);
        tracep->declBit(c+84,"top RAM D6", false,-1);
        tracep->declBit(c+85,"top RAM D7", false,-1);
        tracep->declBit(c+86,"top RAM D8", false,-1);
        tracep->declBit(c+87,"top RAM D9", false,-1);
        tracep->declBit(c+88,"top RAM D10", false,-1);
        tracep->declBit(c+89,"top RAM D11", false,-1);
        tracep->declBit(c+90,"top RAM D12", false,-1);
        tracep->declBit(c+91,"top RAM D13", false,-1);
        tracep->declBit(c+92,"top RAM D14", false,-1);
        tracep->declBit(c+93,"top RAM D15", false,-1);
        tracep->declBit(c+94,"top RAM D0_in", false,-1);
        tracep->declBit(c+95,"top RAM D1_in", false,-1);
        tracep->declBit(c+96,"top RAM D2_in", false,-1);
        tracep->declBit(c+97,"top RAM D3_in", false,-1);
        tracep->declBit(c+98,"top RAM D4_in", false,-1);
        tracep->declBit(c+99,"top RAM D5_in", false,-1);
        tracep->declBit(c+100,"top RAM D6_in", false,-1);
        tracep->declBit(c+101,"top RAM D7_in", false,-1);
        tracep->declBit(c+102,"top RAM D8_in", false,-1);
        tracep->declBit(c+103,"top RAM D9_in", false,-1);
        tracep->declBit(c+104,"top RAM D10_in", false,-1);
        tracep->declBit(c+105,"top RAM D11_in", false,-1);
        tracep->declBit(c+106,"top RAM D12_in", false,-1);
        tracep->declBit(c+107,"top RAM D13_in", false,-1);
        tracep->declBit(c+108,"top RAM D14_in", false,-1);
        tracep->declBit(c+109,"top RAM D15_in", false,-1);
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
        tracep->fullCData(oldp+1,(vlTOPp->top__DOT__RXbuffer),8);
        tracep->fullBit(oldp+2,(vlTOPp->top__DOT__RXready));
        tracep->fullBit(oldp+3,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+4,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
        tracep->fullBit(oldp+5,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                       >> 2U))));
        tracep->fullCData(oldp+6,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
        tracep->fullBit(oldp+7,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+8,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
        tracep->fullCData(oldp+9,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
        tracep->fullCData(oldp+10,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
        tracep->fullBit(oldp+11,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                        >> 2U))));
        tracep->fullSData(oldp+12,(vlTOPp->top__DOT__ALU__DOT__g),16);
        tracep->fullBit(oldp+13,(vlTOPp->top__DOT__overflow));
        tracep->fullSData(oldp+14,(vlTOPp->top__DOT__CONTROL__DOT__programCounter),16);
        tracep->fullSData(oldp+15,(vlTOPp->top__DOT__ALU__DOT__b),16);
        tracep->fullSData(oldp+16,(vlTOPp->top__DOT__ALU__DOT__c),16);
        tracep->fullSData(oldp+17,(vlTOPp->top__DOT__ALU__DOT__d),16);
        tracep->fullSData(oldp+18,(vlTOPp->top__DOT__ALU__DOT__e),16);
        tracep->fullSData(oldp+19,(vlTOPp->top__DOT__ALU__DOT__f),16);
        tracep->fullSData(oldp+20,(vlTOPp->top__DOT__ALU__DOT__h),16);
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__busState),4);
        tracep->fullCData(oldp+22,(vlTOPp->top__DOT__aluOperand1),3);
        tracep->fullCData(oldp+23,(vlTOPp->top__DOT__aluOperand2),3);
        tracep->fullCData(oldp+24,(vlTOPp->top__DOT__aluResults),3);
        tracep->fullCData(oldp+25,(vlTOPp->top__DOT__aluOperation),6);
        tracep->fullCData(oldp+26,(vlTOPp->top__DOT__aluParams),4);
        tracep->fullBit(oldp+27,(vlTOPp->top__DOT__aluReadBus));
        tracep->fullBit(oldp+28,(vlTOPp->top__DOT__ramWrite));
        tracep->fullBit(oldp+29,(vlTOPp->top__DOT__CONTROL__DOT__increment));
        tracep->fullBit(oldp+30,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
        tracep->fullCData(oldp+31,(vlTOPp->top__DOT__TXbuffer),8);
        tracep->fullBit(oldp+32,(vlTOPp->top__DOT__TXstart));
        tracep->fullIData(oldp+33,(vlTOPp->top__DOT__testWord),32);
        tracep->fullBit(oldp+34,(vlTOPp->top__DOT__testClock));
        tracep->fullSData(oldp+35,((0xffffU & (vlTOPp->top__DOT__testWord 
                                               >> 0x10U))),16);
        tracep->fullCData(oldp+36,(vlTOPp->top__DOT__testState),4);
        tracep->fullCData(oldp+37,((3U & vlTOPp->top__DOT__testWord)),2);
        tracep->fullCData(oldp+38,((0x1fU & (vlTOPp->top__DOT__testWord 
                                             >> 2U))),5);
        tracep->fullCData(oldp+39,((7U & (vlTOPp->top__DOT__testWord 
                                          >> 7U))),3);
        tracep->fullCData(oldp+40,((7U & (vlTOPp->top__DOT__testWord 
                                          >> 0xaU))),3);
        tracep->fullCData(oldp+41,((7U & (vlTOPp->top__DOT__testWord 
                                          >> 0xdU))),3);
        tracep->fullSData(oldp+42,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
        tracep->fullSData(oldp+43,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
        tracep->fullSData(oldp+44,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
        tracep->fullSData(oldp+45,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
        tracep->fullSData(oldp+46,(vlTOPp->top__DOT__bus),16);
        tracep->fullIData(oldp+47,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        tracep->fullIData(oldp+48,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        tracep->fullSData(oldp+49,(vlTOPp->top__DOT__ALU__DOT__log),16);
        tracep->fullSData(oldp+50,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
        tracep->fullBit(oldp+51,(vlTOPp->CLK));
        tracep->fullBit(oldp+52,(vlTOPp->RX));
        tracep->fullBit(oldp+53,(vlTOPp->TX));
        tracep->fullBit(oldp+54,(vlTOPp->GPIO3));
        tracep->fullBit(oldp+55,(vlTOPp->GPIO9));
        tracep->fullBit(oldp+56,(vlTOPp->GPIO11));
        tracep->fullBit(oldp+57,(vlTOPp->CE));
        tracep->fullBit(oldp+58,(vlTOPp->OE));
        tracep->fullBit(oldp+59,(vlTOPp->WR));
        tracep->fullBit(oldp+60,(vlTOPp->UB));
        tracep->fullBit(oldp+61,(vlTOPp->LB));
        tracep->fullBit(oldp+62,(vlTOPp->A0));
        tracep->fullBit(oldp+63,(vlTOPp->A1));
        tracep->fullBit(oldp+64,(vlTOPp->A2));
        tracep->fullBit(oldp+65,(vlTOPp->A3));
        tracep->fullBit(oldp+66,(vlTOPp->A4));
        tracep->fullBit(oldp+67,(vlTOPp->A5));
        tracep->fullBit(oldp+68,(vlTOPp->A6));
        tracep->fullBit(oldp+69,(vlTOPp->A7));
        tracep->fullBit(oldp+70,(vlTOPp->A8));
        tracep->fullBit(oldp+71,(vlTOPp->A9));
        tracep->fullBit(oldp+72,(vlTOPp->A10));
        tracep->fullBit(oldp+73,(vlTOPp->A11));
        tracep->fullBit(oldp+74,(vlTOPp->A12));
        tracep->fullBit(oldp+75,(vlTOPp->A13));
        tracep->fullBit(oldp+76,(vlTOPp->A14));
        tracep->fullBit(oldp+77,(vlTOPp->A15));
        tracep->fullBit(oldp+78,(vlTOPp->D0));
        tracep->fullBit(oldp+79,(vlTOPp->D1));
        tracep->fullBit(oldp+80,(vlTOPp->D2));
        tracep->fullBit(oldp+81,(vlTOPp->D3));
        tracep->fullBit(oldp+82,(vlTOPp->D4));
        tracep->fullBit(oldp+83,(vlTOPp->D5));
        tracep->fullBit(oldp+84,(vlTOPp->D6));
        tracep->fullBit(oldp+85,(vlTOPp->D7));
        tracep->fullBit(oldp+86,(vlTOPp->D8));
        tracep->fullBit(oldp+87,(vlTOPp->D9));
        tracep->fullBit(oldp+88,(vlTOPp->D10));
        tracep->fullBit(oldp+89,(vlTOPp->D11));
        tracep->fullBit(oldp+90,(vlTOPp->D12));
        tracep->fullBit(oldp+91,(vlTOPp->D13));
        tracep->fullBit(oldp+92,(vlTOPp->D14));
        tracep->fullBit(oldp+93,(vlTOPp->D15));
        tracep->fullBit(oldp+94,(vlTOPp->D0_in));
        tracep->fullBit(oldp+95,(vlTOPp->D1_in));
        tracep->fullBit(oldp+96,(vlTOPp->D2_in));
        tracep->fullBit(oldp+97,(vlTOPp->D3_in));
        tracep->fullBit(oldp+98,(vlTOPp->D4_in));
        tracep->fullBit(oldp+99,(vlTOPp->D5_in));
        tracep->fullBit(oldp+100,(vlTOPp->D6_in));
        tracep->fullBit(oldp+101,(vlTOPp->D7_in));
        tracep->fullBit(oldp+102,(vlTOPp->D8_in));
        tracep->fullBit(oldp+103,(vlTOPp->D9_in));
        tracep->fullBit(oldp+104,(vlTOPp->D10_in));
        tracep->fullBit(oldp+105,(vlTOPp->D11_in));
        tracep->fullBit(oldp+106,(vlTOPp->D12_in));
        tracep->fullBit(oldp+107,(vlTOPp->D13_in));
        tracep->fullBit(oldp+108,(vlTOPp->D14_in));
        tracep->fullBit(oldp+109,(vlTOPp->D15_in));
        tracep->fullSData(oldp+110,(vlTOPp->top__DOT__ramAddress),16);
        tracep->fullSData(oldp+111,(vlTOPp->top__DOT__ramOut),16);
        tracep->fullIData(oldp+112,(vlTOPp->top__DOT__clkdiv),25);
        tracep->fullSData(oldp+113,(vlTOPp->top__DOT__ALU__DOT__a),16);
        tracep->fullSData(oldp+114,(vlTOPp->top__DOT__hreg),16);
        tracep->fullSData(oldp+115,(vlTOPp->top__DOT__romAddress),16);
        tracep->fullSData(oldp+116,(vlTOPp->top__DOT__romOut),16);
        tracep->fullSData(oldp+117,(vlTOPp->top__DOT__gpuOut),16);
        tracep->fullSData(oldp+118,(vlTOPp->top__DOT__apuOut),16);
        tracep->fullSData(oldp+119,(vlTOPp->top__DOT__clkOut),16);
        tracep->fullSData(oldp+120,(vlTOPp->top__DOT__din),16);
        tracep->fullSData(oldp+121,(vlTOPp->top__DOT__dout),16);
        tracep->fullCData(oldp+122,(0U),3);
        tracep->fullCData(oldp+123,(1U),3);
        tracep->fullCData(oldp+124,(0U),6);
        tracep->fullCData(oldp+125,(0U),4);
        tracep->fullIData(oldp+126,(2U),32);
        tracep->fullCData(oldp+127,(0U),5);
    }
}
