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
        tracep->declBit(c+45,"CLK", false,-1);
        tracep->declBit(c+46,"RX", false,-1);
        tracep->declBit(c+47,"TX", false,-1);
        tracep->declBit(c+48,"GPIO3", false,-1);
        tracep->declBit(c+49,"GPIO9", false,-1);
        tracep->declBit(c+50,"GPIO11", false,-1);
        tracep->declBit(c+45,"top CLK", false,-1);
        tracep->declBit(c+46,"top RX", false,-1);
        tracep->declBit(c+47,"top TX", false,-1);
        tracep->declBit(c+48,"top GPIO3", false,-1);
        tracep->declBit(c+49,"top GPIO9", false,-1);
        tracep->declBit(c+50,"top GPIO11", false,-1);
        tracep->declBus(c+7,"top RXbuffer", false,-1, 7,0);
        tracep->declBus(c+1,"top TXbuffer", false,-1, 7,0);
        tracep->declBit(c+2,"top TXstart", false,-1);
        tracep->declBit(c+8,"top RXready", false,-1);
        tracep->declBit(c+9,"top TXbusy", false,-1);
        tracep->declBus(c+3,"top testWord", false,-1, 31,0);
        tracep->declBit(c+4,"top testClock", false,-1);
        tracep->declBus(c+18,"top busState", false,-1, 3,0);
        tracep->declBus(c+19,"top aluOperand1", false,-1, 2,0);
        tracep->declBus(c+20,"top aluOperand2", false,-1, 2,0);
        tracep->declBus(c+21,"top aluResults", false,-1, 2,0);
        tracep->declBus(c+22,"top aluOperation", false,-1, 5,0);
        tracep->declBus(c+23,"top aluParams", false,-1, 3,0);
        tracep->declBit(c+24,"top aluReadBus", false,-1);
        tracep->declBit(c+51,"top ramWrite", false,-1);
        tracep->declBus(c+26,"top greg", false,-1, 15,0);
        tracep->declBus(c+52,"top hreg", false,-1, 15,0);
        tracep->declBus(c+53,"top ramAddress", false,-1, 15,0);
        tracep->declBus(c+54,"top romAddress", false,-1, 15,0);
        tracep->declBus(c+53,"top ctrlOut", false,-1, 15,0);
        tracep->declBus(c+36,"top aluOut", false,-1, 15,0);
        tracep->declBus(c+55,"top ramOut", false,-1, 15,0);
        tracep->declBus(c+56,"top romOut", false,-1, 15,0);
        tracep->declBus(c+57,"top gpuOut", false,-1, 15,0);
        tracep->declBus(c+58,"top apuOut", false,-1, 15,0);
        tracep->declBus(c+59,"top clkOut", false,-1, 15,0);
        tracep->declBus(c+40,"top bus", false,-1, 15,0);
        tracep->declBus(c+60,"top din", false,-1, 15,0);
        tracep->declBus(c+61,"top dout", false,-1, 15,0);
        tracep->declBus(c+62,"top a", false,-1, 2,0);
        tracep->declBus(c+63,"top b", false,-1, 2,0);
        tracep->declBus(c+62,"top y", false,-1, 2,0);
        tracep->declBus(c+64,"top operation", false,-1, 5,0);
        tracep->declBus(c+65,"top params", false,-1, 3,0);
        tracep->declBit(c+27,"top overflow", false,-1);
        tracep->declBus(c+5,"top testState", false,-1, 3,0);
        tracep->declBus(c+6,"top clkdiv", false,-1, 24,0);
        tracep->declBit(c+45,"top FTDI CLK", false,-1);
        tracep->declBit(c+46,"top FTDI RX", false,-1);
        tracep->declBus(c+1,"top FTDI TXbuffer", false,-1, 7,0);
        tracep->declBit(c+2,"top FTDI TXstart", false,-1);
        tracep->declBit(c+47,"top FTDI TX", false,-1);
        tracep->declBus(c+7,"top FTDI RXbuffer", false,-1, 7,0);
        tracep->declBit(c+8,"top FTDI RXready", false,-1);
        tracep->declBit(c+9,"top FTDI TXbusy", false,-1);
        tracep->declBus(c+66,"top FTDI CLOCK_DIVISOR", false,-1, 31,0);
        tracep->declBus(c+10,"top FTDI baudAcc", false,-1, 2,0);
        tracep->declBit(c+11,"top FTDI baudTick", false,-1);
        tracep->declBus(c+12,"top FTDI TXstate", false,-1, 3,0);
        tracep->declBit(c+13,"top FTDI TXready", false,-1);
        tracep->declBus(c+14,"top FTDI TXshift", false,-1, 7,0);
        tracep->declBus(c+15,"top FTDI RXstate", false,-1, 3,0);
        tracep->declBus(c+16,"top FTDI gap", false,-1, 2,0);
        tracep->declBit(c+17,"top FTDI nextBit", false,-1);
        tracep->declBit(c+4,"top CONTROL CLK", false,-1);
        tracep->declBus(c+19,"top CONTROL operand1", false,-1, 2,0);
        tracep->declBus(c+20,"top CONTROL operand2", false,-1, 2,0);
        tracep->declBus(c+21,"top CONTROL results", false,-1, 2,0);
        tracep->declBus(c+22,"top CONTROL aluOperation", false,-1, 5,0);
        tracep->declBus(c+23,"top CONTROL aluParams", false,-1, 3,0);
        tracep->declBus(c+18,"top CONTROL busState", false,-1, 3,0);
        tracep->declBit(c+24,"top CONTROL aluReadBus", false,-1);
        tracep->declBit(c+51,"top CONTROL ramWrite", false,-1);
        tracep->declBus(c+26,"top CONTROL greg", false,-1, 15,0);
        tracep->declBus(c+52,"top CONTROL hreg", false,-1, 15,0);
        tracep->declBus(c+53,"top CONTROL ramAdd", false,-1, 15,0);
        tracep->declBus(c+54,"top CONTROL romAdd", false,-1, 15,0);
        tracep->declBus(c+53,"top CONTROL dout", false,-1, 15,0);
        tracep->declBit(c+25,"top CONTROL increment", false,-1);
        tracep->declBit(c+51,"top CONTROL ramAddMode", false,-1);
        tracep->declBus(c+28,"top CONTROL programCounter", false,-1, 15,0);
        tracep->declBus(c+67,"top CONTROL controlWord", false,-1, 31,0);
        tracep->declBus(c+68,"top CONTROL opcode", false,-1, 5,0);
        tracep->declBus(c+62,"top CONTROL operand1Wire", false,-1, 2,0);
        tracep->declBus(c+62,"top CONTROL operand2Wire", false,-1, 2,0);
        tracep->declBus(c+62,"top CONTROL resultsWire", false,-1, 2,0);
        tracep->declBus(c+53,"top CONTROL word2Wire", false,-1, 15,0);
        tracep->declBit(c+4,"top ALU CLK", false,-1);
        tracep->declBit(c+24,"top ALU readBus", false,-1);
        tracep->declBus(c+40,"top ALU din", false,-1, 15,0);
        tracep->declBus(c+36,"top ALU dout", false,-1, 15,0);
        tracep->declBus(c+19,"top ALU operandIndex1", false,-1, 2,0);
        tracep->declBus(c+20,"top ALU operandIndex2", false,-1, 2,0);
        tracep->declBus(c+21,"top ALU resultsIndex", false,-1, 2,0);
        tracep->declBus(c+22,"top ALU operation", false,-1, 5,0);
        tracep->declBus(c+23,"top ALU params", false,-1, 3,0);
        tracep->declBit(c+27,"top ALU overflow", false,-1);
        tracep->declBus(c+29,"top ALU a", false,-1, 15,0);
        tracep->declBus(c+30,"top ALU b", false,-1, 15,0);
        tracep->declBus(c+31,"top ALU c", false,-1, 15,0);
        tracep->declBus(c+32,"top ALU d", false,-1, 15,0);
        tracep->declBus(c+33,"top ALU e", false,-1, 15,0);
        tracep->declBus(c+34,"top ALU f", false,-1, 15,0);
        tracep->declBus(c+26,"top ALU g", false,-1, 15,0);
        tracep->declBus(c+35,"top ALU h", false,-1, 15,0);
        tracep->declBus(c+41,"top ALU addsub", false,-1, 16,0);
        tracep->declBus(c+42,"top ALU mult", false,-1, 16,0);
        tracep->declBus(c+43,"top ALU log", false,-1, 15,0);
        tracep->declBus(c+37,"top ALU lshift", false,-1, 15,0);
        tracep->declBus(c+38,"top ALU rshift", false,-1, 15,0);
        tracep->declBus(c+36,"top ALU operand1", false,-1, 15,0);
        tracep->declBus(c+39,"top ALU operand2", false,-1, 15,0);
        tracep->declBus(c+44,"top ALU combOperand2", false,-1, 15,0);
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
        tracep->fullCData(oldp+1,(vlTOPp->top__DOT__TXbuffer),8);
        tracep->fullBit(oldp+2,(vlTOPp->top__DOT__TXstart));
        tracep->fullIData(oldp+3,(vlTOPp->top__DOT__testWord),32);
        tracep->fullBit(oldp+4,(vlTOPp->top__DOT__testClock));
        tracep->fullCData(oldp+5,(vlTOPp->top__DOT__testState),4);
        tracep->fullIData(oldp+6,(vlTOPp->top__DOT__clkdiv),25);
        tracep->fullCData(oldp+7,(vlTOPp->top__DOT__RXbuffer),8);
        tracep->fullBit(oldp+8,(vlTOPp->top__DOT__RXready));
        tracep->fullBit(oldp+9,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+10,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
        tracep->fullBit(oldp+11,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                        >> 2U))));
        tracep->fullCData(oldp+12,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
        tracep->fullBit(oldp+13,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+14,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
        tracep->fullCData(oldp+15,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
        tracep->fullCData(oldp+16,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
        tracep->fullBit(oldp+17,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                        >> 2U))));
        tracep->fullCData(oldp+18,(vlTOPp->top__DOT__busState),4);
        tracep->fullCData(oldp+19,(vlTOPp->top__DOT__aluOperand1),3);
        tracep->fullCData(oldp+20,(vlTOPp->top__DOT__aluOperand2),3);
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__aluResults),3);
        tracep->fullCData(oldp+22,(vlTOPp->top__DOT__aluOperation),6);
        tracep->fullCData(oldp+23,(vlTOPp->top__DOT__aluParams),4);
        tracep->fullBit(oldp+24,(vlTOPp->top__DOT__aluReadBus));
        tracep->fullBit(oldp+25,(vlTOPp->top__DOT__CONTROL__DOT__increment));
        tracep->fullSData(oldp+26,(vlTOPp->top__DOT__ALU__DOT__g),16);
        tracep->fullBit(oldp+27,(vlTOPp->top__DOT__overflow));
        tracep->fullSData(oldp+28,(vlTOPp->top__DOT__CONTROL__DOT__programCounter),16);
        tracep->fullSData(oldp+29,(vlTOPp->top__DOT__ALU__DOT__a),16);
        tracep->fullSData(oldp+30,(vlTOPp->top__DOT__ALU__DOT__b),16);
        tracep->fullSData(oldp+31,(vlTOPp->top__DOT__ALU__DOT__c),16);
        tracep->fullSData(oldp+32,(vlTOPp->top__DOT__ALU__DOT__d),16);
        tracep->fullSData(oldp+33,(vlTOPp->top__DOT__ALU__DOT__e),16);
        tracep->fullSData(oldp+34,(vlTOPp->top__DOT__ALU__DOT__f),16);
        tracep->fullSData(oldp+35,(vlTOPp->top__DOT__ALU__DOT__h),16);
        tracep->fullSData(oldp+36,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
        tracep->fullSData(oldp+37,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
        tracep->fullSData(oldp+38,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
        tracep->fullSData(oldp+39,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
        tracep->fullSData(oldp+40,(vlTOPp->top__DOT__bus),16);
        tracep->fullIData(oldp+41,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        tracep->fullIData(oldp+42,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        tracep->fullSData(oldp+43,(vlTOPp->top__DOT__ALU__DOT__log),16);
        tracep->fullSData(oldp+44,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
        tracep->fullBit(oldp+45,(vlTOPp->CLK));
        tracep->fullBit(oldp+46,(vlTOPp->RX));
        tracep->fullBit(oldp+47,(vlTOPp->TX));
        tracep->fullBit(oldp+48,(vlTOPp->GPIO3));
        tracep->fullBit(oldp+49,(vlTOPp->GPIO9));
        tracep->fullBit(oldp+50,(vlTOPp->GPIO11));
        tracep->fullBit(oldp+51,(0U));
        tracep->fullSData(oldp+52,(vlTOPp->top__DOT__hreg),16);
        tracep->fullSData(oldp+53,(4U),16);
        tracep->fullSData(oldp+54,(vlTOPp->top__DOT__romAddress),16);
        tracep->fullSData(oldp+55,(vlTOPp->top__DOT__ramOut),16);
        tracep->fullSData(oldp+56,(vlTOPp->top__DOT__romOut),16);
        tracep->fullSData(oldp+57,(vlTOPp->top__DOT__gpuOut),16);
        tracep->fullSData(oldp+58,(vlTOPp->top__DOT__apuOut),16);
        tracep->fullSData(oldp+59,(vlTOPp->top__DOT__clkOut),16);
        tracep->fullSData(oldp+60,(vlTOPp->top__DOT__din),16);
        tracep->fullSData(oldp+61,(vlTOPp->top__DOT__dout),16);
        tracep->fullCData(oldp+62,(0U),3);
        tracep->fullCData(oldp+63,(1U),3);
        tracep->fullCData(oldp+64,(0U),6);
        tracep->fullCData(oldp+65,(0U),4);
        tracep->fullIData(oldp+66,(2U),32);
        tracep->fullIData(oldp+67,(0x40008U),32);
        tracep->fullCData(oldp+68,(8U),6);
    }
}
