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
        tracep->declBit(c+49,"CLK", false,-1);
        tracep->declBit(c+50,"RX", false,-1);
        tracep->declBit(c+51,"TX", false,-1);
        tracep->declBit(c+52,"GPIO3", false,-1);
        tracep->declBit(c+53,"GPIO9", false,-1);
        tracep->declBit(c+54,"GPIO11", false,-1);
        tracep->declBit(c+49,"top CLK", false,-1);
        tracep->declBit(c+50,"top RX", false,-1);
        tracep->declBit(c+51,"top TX", false,-1);
        tracep->declBit(c+52,"top GPIO3", false,-1);
        tracep->declBit(c+53,"top GPIO9", false,-1);
        tracep->declBit(c+54,"top GPIO11", false,-1);
        tracep->declBus(c+1,"top RXbuffer", false,-1, 7,0);
        tracep->declBus(c+30,"top TXbuffer", false,-1, 7,0);
        tracep->declBit(c+31,"top TXstart", false,-1);
        tracep->declBit(c+2,"top RXready", false,-1);
        tracep->declBit(c+3,"top TXbusy", false,-1);
        tracep->declBus(c+32,"top testWord", false,-1, 31,0);
        tracep->declBit(c+33,"top testClock", false,-1);
        tracep->declBus(c+21,"top busState", false,-1, 3,0);
        tracep->declBus(c+22,"top aluOperand1", false,-1, 2,0);
        tracep->declBus(c+23,"top aluOperand2", false,-1, 2,0);
        tracep->declBus(c+24,"top aluResults", false,-1, 2,0);
        tracep->declBus(c+25,"top aluOperation", false,-1, 5,0);
        tracep->declBus(c+26,"top aluParams", false,-1, 3,0);
        tracep->declBit(c+27,"top aluReadBus", false,-1);
        tracep->declBit(c+58,"top ramWrite", false,-1);
        tracep->declBus(c+12,"top greg", false,-1, 15,0);
        tracep->declBus(c+59,"top hreg", false,-1, 15,0);
        tracep->declBus(c+55,"top ramAddress", false,-1, 15,0);
        tracep->declBus(c+60,"top romAddress", false,-1, 15,0);
        tracep->declBus(c+34,"top ctrlOut", false,-1, 15,0);
        tracep->declBus(c+40,"top aluOut", false,-1, 15,0);
        tracep->declBus(c+61,"top ramOut", false,-1, 15,0);
        tracep->declBus(c+62,"top romOut", false,-1, 15,0);
        tracep->declBus(c+63,"top gpuOut", false,-1, 15,0);
        tracep->declBus(c+64,"top apuOut", false,-1, 15,0);
        tracep->declBus(c+65,"top clkOut", false,-1, 15,0);
        tracep->declBus(c+44,"top bus", false,-1, 15,0);
        tracep->declBus(c+66,"top din", false,-1, 15,0);
        tracep->declBus(c+67,"top dout", false,-1, 15,0);
        tracep->declBus(c+68,"top a", false,-1, 2,0);
        tracep->declBus(c+69,"top b", false,-1, 2,0);
        tracep->declBus(c+68,"top y", false,-1, 2,0);
        tracep->declBus(c+70,"top operation", false,-1, 5,0);
        tracep->declBus(c+71,"top params", false,-1, 3,0);
        tracep->declBit(c+13,"top overflow", false,-1);
        tracep->declBus(c+35,"top testState", false,-1, 3,0);
        tracep->declBus(c+56,"top clkdiv", false,-1, 24,0);
        tracep->declBit(c+49,"top FTDI CLK", false,-1);
        tracep->declBit(c+50,"top FTDI RX", false,-1);
        tracep->declBus(c+30,"top FTDI TXbuffer", false,-1, 7,0);
        tracep->declBit(c+31,"top FTDI TXstart", false,-1);
        tracep->declBit(c+51,"top FTDI TX", false,-1);
        tracep->declBus(c+1,"top FTDI RXbuffer", false,-1, 7,0);
        tracep->declBit(c+2,"top FTDI RXready", false,-1);
        tracep->declBit(c+3,"top FTDI TXbusy", false,-1);
        tracep->declBus(c+72,"top FTDI CLOCK_DIVISOR", false,-1, 31,0);
        tracep->declBus(c+4,"top FTDI baudAcc", false,-1, 2,0);
        tracep->declBit(c+5,"top FTDI baudTick", false,-1);
        tracep->declBus(c+6,"top FTDI TXstate", false,-1, 3,0);
        tracep->declBit(c+7,"top FTDI TXready", false,-1);
        tracep->declBus(c+8,"top FTDI TXshift", false,-1, 7,0);
        tracep->declBus(c+9,"top FTDI RXstate", false,-1, 3,0);
        tracep->declBus(c+10,"top FTDI gap", false,-1, 2,0);
        tracep->declBit(c+11,"top FTDI nextBit", false,-1);
        tracep->declBit(c+33,"top CONTROL CLK", false,-1);
        tracep->declBus(c+22,"top CONTROL operand1", false,-1, 2,0);
        tracep->declBus(c+23,"top CONTROL operand2", false,-1, 2,0);
        tracep->declBus(c+24,"top CONTROL results", false,-1, 2,0);
        tracep->declBus(c+25,"top CONTROL aluOperation", false,-1, 5,0);
        tracep->declBus(c+26,"top CONTROL aluParams", false,-1, 3,0);
        tracep->declBus(c+21,"top CONTROL busState", false,-1, 3,0);
        tracep->declBit(c+27,"top CONTROL aluReadBus", false,-1);
        tracep->declBit(c+58,"top CONTROL ramWrite", false,-1);
        tracep->declBus(c+12,"top CONTROL greg", false,-1, 15,0);
        tracep->declBus(c+59,"top CONTROL hreg", false,-1, 15,0);
        tracep->declBus(c+55,"top CONTROL ramAdd", false,-1, 15,0);
        tracep->declBus(c+60,"top CONTROL romAdd", false,-1, 15,0);
        tracep->declBus(c+34,"top CONTROL dout", false,-1, 15,0);
        tracep->declBus(c+32,"top CONTROL testWord", false,-1, 31,0);
        tracep->declBit(c+28,"top CONTROL increment", false,-1);
        tracep->declBit(c+29,"top CONTROL ramAddMode", false,-1);
        tracep->declBus(c+14,"top CONTROL programCounter", false,-1, 15,0);
        tracep->declBus(c+32,"top CONTROL controlWord", false,-1, 31,0);
        tracep->declBus(c+36,"top CONTROL opcode", false,-1, 5,0);
        tracep->declBus(c+37,"top CONTROL operand1Wire", false,-1, 2,0);
        tracep->declBus(c+38,"top CONTROL operand2Wire", false,-1, 2,0);
        tracep->declBus(c+39,"top CONTROL resultsWire", false,-1, 2,0);
        tracep->declBus(c+34,"top CONTROL word2Wire", false,-1, 15,0);
        tracep->declBit(c+33,"top ALU CLK", false,-1);
        tracep->declBit(c+27,"top ALU readBus", false,-1);
        tracep->declBus(c+44,"top ALU din", false,-1, 15,0);
        tracep->declBus(c+40,"top ALU dout", false,-1, 15,0);
        tracep->declBus(c+22,"top ALU operandIndex1", false,-1, 2,0);
        tracep->declBus(c+23,"top ALU operandIndex2", false,-1, 2,0);
        tracep->declBus(c+24,"top ALU resultsIndex", false,-1, 2,0);
        tracep->declBus(c+25,"top ALU operation", false,-1, 5,0);
        tracep->declBus(c+26,"top ALU params", false,-1, 3,0);
        tracep->declBit(c+13,"top ALU overflow", false,-1);
        tracep->declBus(c+57,"top ALU a", false,-1, 15,0);
        tracep->declBus(c+15,"top ALU b", false,-1, 15,0);
        tracep->declBus(c+16,"top ALU c", false,-1, 15,0);
        tracep->declBus(c+17,"top ALU d", false,-1, 15,0);
        tracep->declBus(c+18,"top ALU e", false,-1, 15,0);
        tracep->declBus(c+19,"top ALU f", false,-1, 15,0);
        tracep->declBus(c+12,"top ALU g", false,-1, 15,0);
        tracep->declBus(c+20,"top ALU h", false,-1, 15,0);
        tracep->declBus(c+45,"top ALU addsub", false,-1, 16,0);
        tracep->declBus(c+46,"top ALU mult", false,-1, 16,0);
        tracep->declBus(c+47,"top ALU log", false,-1, 15,0);
        tracep->declBus(c+41,"top ALU lshift", false,-1, 15,0);
        tracep->declBus(c+42,"top ALU rshift", false,-1, 15,0);
        tracep->declBus(c+40,"top ALU operand1", false,-1, 15,0);
        tracep->declBus(c+43,"top ALU operand2", false,-1, 15,0);
        tracep->declBus(c+48,"top ALU combOperand2", false,-1, 15,0);
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
        tracep->fullBit(oldp+28,(vlTOPp->top__DOT__CONTROL__DOT__increment));
        tracep->fullBit(oldp+29,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
        tracep->fullCData(oldp+30,(vlTOPp->top__DOT__TXbuffer),8);
        tracep->fullBit(oldp+31,(vlTOPp->top__DOT__TXstart));
        tracep->fullIData(oldp+32,(vlTOPp->top__DOT__testWord),32);
        tracep->fullBit(oldp+33,(vlTOPp->top__DOT__testClock));
        tracep->fullSData(oldp+34,((0xffffU & (vlTOPp->top__DOT__testWord 
                                               >> 0x10U))),16);
        tracep->fullCData(oldp+35,(vlTOPp->top__DOT__testState),4);
        tracep->fullCData(oldp+36,((0x3fU & vlTOPp->top__DOT__testWord)),6);
        tracep->fullCData(oldp+37,((7U & (vlTOPp->top__DOT__testWord 
                                          >> 7U))),3);
        tracep->fullCData(oldp+38,((7U & (vlTOPp->top__DOT__testWord 
                                          >> 0xaU))),3);
        tracep->fullCData(oldp+39,((7U & (vlTOPp->top__DOT__testWord 
                                          >> 0xdU))),3);
        tracep->fullSData(oldp+40,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
        tracep->fullSData(oldp+41,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
        tracep->fullSData(oldp+42,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
        tracep->fullSData(oldp+43,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
        tracep->fullSData(oldp+44,(vlTOPp->top__DOT__bus),16);
        tracep->fullIData(oldp+45,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        tracep->fullIData(oldp+46,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        tracep->fullSData(oldp+47,(vlTOPp->top__DOT__ALU__DOT__log),16);
        tracep->fullSData(oldp+48,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
        tracep->fullBit(oldp+49,(vlTOPp->CLK));
        tracep->fullBit(oldp+50,(vlTOPp->RX));
        tracep->fullBit(oldp+51,(vlTOPp->TX));
        tracep->fullBit(oldp+52,(vlTOPp->GPIO3));
        tracep->fullBit(oldp+53,(vlTOPp->GPIO9));
        tracep->fullBit(oldp+54,(vlTOPp->GPIO11));
        tracep->fullSData(oldp+55,((0xffffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode)
                                                ? (IData)(vlTOPp->top__DOT__ALU__DOT__g)
                                                : (vlTOPp->top__DOT__testWord 
                                                   >> 0x10U)))),16);
        tracep->fullIData(oldp+56,(vlTOPp->top__DOT__clkdiv),25);
        tracep->fullSData(oldp+57,(vlTOPp->top__DOT__ALU__DOT__a),16);
        tracep->fullBit(oldp+58,(0U));
        tracep->fullSData(oldp+59,(vlTOPp->top__DOT__hreg),16);
        tracep->fullSData(oldp+60,(vlTOPp->top__DOT__romAddress),16);
        tracep->fullSData(oldp+61,(vlTOPp->top__DOT__ramOut),16);
        tracep->fullSData(oldp+62,(vlTOPp->top__DOT__romOut),16);
        tracep->fullSData(oldp+63,(vlTOPp->top__DOT__gpuOut),16);
        tracep->fullSData(oldp+64,(vlTOPp->top__DOT__apuOut),16);
        tracep->fullSData(oldp+65,(vlTOPp->top__DOT__clkOut),16);
        tracep->fullSData(oldp+66,(vlTOPp->top__DOT__din),16);
        tracep->fullSData(oldp+67,(vlTOPp->top__DOT__dout),16);
        tracep->fullCData(oldp+68,(0U),3);
        tracep->fullCData(oldp+69,(1U),3);
        tracep->fullCData(oldp+70,(0U),6);
        tracep->fullCData(oldp+71,(0U),4);
        tracep->fullIData(oldp+72,(2U),32);
    }
}
