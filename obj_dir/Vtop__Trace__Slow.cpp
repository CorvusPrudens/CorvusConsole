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
        tracep->declBit(c+33,"CLK", false,-1);
        tracep->declBit(c+34,"RX", false,-1);
        tracep->declBit(c+35,"TX", false,-1);
        tracep->declBit(c+36,"GPIO3", false,-1);
        tracep->declBit(c+37,"GPIO9", false,-1);
        tracep->declBit(c+38,"GPIO11", false,-1);
        tracep->declBit(c+33,"top CLK", false,-1);
        tracep->declBit(c+34,"top RX", false,-1);
        tracep->declBit(c+35,"top TX", false,-1);
        tracep->declBit(c+36,"top GPIO3", false,-1);
        tracep->declBit(c+37,"top GPIO9", false,-1);
        tracep->declBit(c+38,"top GPIO11", false,-1);
        tracep->declBus(c+7,"top RXbuffer", false,-1, 7,0);
        tracep->declBus(c+19,"top TXbuffer", false,-1, 7,0);
        tracep->declBit(c+20,"top TXstart", false,-1);
        tracep->declBit(c+8,"top RXready", false,-1);
        tracep->declBit(c+9,"top TXbusy", false,-1);
        tracep->declBus(c+40,"top a", false,-1, 2,0);
        tracep->declBus(c+41,"top b", false,-1, 2,0);
        tracep->declBus(c+40,"top y", false,-1, 2,0);
        tracep->declBus(c+21,"top op", false,-1, 5,0);
        tracep->declBus(c+22,"top params", false,-1, 3,0);
        tracep->declBit(c+10,"top overflow", false,-1);
        tracep->declBus(c+23,"top testState", false,-1, 3,0);
        tracep->declBus(c+39,"top clkdiv", false,-1, 24,0);
        tracep->declBit(c+33,"top FTDI CLK", false,-1);
        tracep->declBit(c+34,"top FTDI RX", false,-1);
        tracep->declBus(c+19,"top FTDI TXbuffer", false,-1, 7,0);
        tracep->declBit(c+20,"top FTDI TXstart", false,-1);
        tracep->declBit(c+35,"top FTDI TX", false,-1);
        tracep->declBus(c+7,"top FTDI RXbuffer", false,-1, 7,0);
        tracep->declBit(c+8,"top FTDI RXready", false,-1);
        tracep->declBit(c+9,"top FTDI TXbusy", false,-1);
        tracep->declBus(c+42,"top FTDI CLOCK_DIVISOR", false,-1, 31,0);
        tracep->declBus(c+11,"top FTDI baudAcc", false,-1, 2,0);
        tracep->declBit(c+12,"top FTDI baudTick", false,-1);
        tracep->declBus(c+13,"top FTDI TXstate", false,-1, 3,0);
        tracep->declBit(c+14,"top FTDI TXready", false,-1);
        tracep->declBus(c+15,"top FTDI TXshift", false,-1, 7,0);
        tracep->declBus(c+16,"top FTDI RXstate", false,-1, 3,0);
        tracep->declBus(c+17,"top FTDI gap", false,-1, 2,0);
        tracep->declBit(c+18,"top FTDI nextBit", false,-1);
        tracep->declBit(c+33,"top ALU CLK", false,-1);
        tracep->declBus(c+40,"top ALU aindex", false,-1, 2,0);
        tracep->declBus(c+41,"top ALU bindex", false,-1, 2,0);
        tracep->declBus(c+40,"top ALU yindex", false,-1, 2,0);
        tracep->declBus(c+21,"top ALU op", false,-1, 5,0);
        tracep->declBus(c+22,"top ALU params", false,-1, 3,0);
        tracep->declBit(c+10,"top ALU overflow", false,-1);
        tracep->declBus(c+26,"top ALU r0", false,-1, 15,0);
        tracep->declBus(c+24,"top ALU r1", false,-1, 15,0);
        tracep->declBus(c+1,"top ALU r2", false,-1, 15,0);
        tracep->declBus(c+2,"top ALU r3", false,-1, 15,0);
        tracep->declBus(c+3,"top ALU r4", false,-1, 15,0);
        tracep->declBus(c+4,"top ALU r5", false,-1, 15,0);
        tracep->declBus(c+5,"top ALU r6", false,-1, 15,0);
        tracep->declBus(c+6,"top ALU r7", false,-1, 15,0);
        tracep->declBus(c+27,"top ALU addsub", false,-1, 16,0);
        tracep->declBus(c+28,"top ALU mult", false,-1, 16,0);
        tracep->declBus(c+29,"top ALU log", false,-1, 15,0);
        tracep->declBus(c+30,"top ALU lshift", false,-1, 15,0);
        tracep->declBus(c+31,"top ALU rshift", false,-1, 15,0);
        tracep->declBus(c+32,"top ALU a", false,-1, 15,0);
        tracep->declBus(c+25,"top ALU b", false,-1, 15,0);
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
        tracep->fullSData(oldp+1,(vlTOPp->top__DOT__ALU__DOT__r2),16);
        tracep->fullSData(oldp+2,(vlTOPp->top__DOT__ALU__DOT__r3),16);
        tracep->fullSData(oldp+3,(vlTOPp->top__DOT__ALU__DOT__r4),16);
        tracep->fullSData(oldp+4,(vlTOPp->top__DOT__ALU__DOT__r5),16);
        tracep->fullSData(oldp+5,(vlTOPp->top__DOT__ALU__DOT__r6),16);
        tracep->fullSData(oldp+6,(vlTOPp->top__DOT__ALU__DOT__r7),16);
        tracep->fullCData(oldp+7,(vlTOPp->top__DOT__RXbuffer),8);
        tracep->fullBit(oldp+8,(vlTOPp->top__DOT__RXready));
        tracep->fullBit(oldp+9,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullBit(oldp+10,(vlTOPp->top__DOT__overflow));
        tracep->fullCData(oldp+11,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
        tracep->fullBit(oldp+12,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                        >> 2U))));
        tracep->fullCData(oldp+13,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
        tracep->fullBit(oldp+14,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+15,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
        tracep->fullCData(oldp+16,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
        tracep->fullCData(oldp+17,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
        tracep->fullBit(oldp+18,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                        >> 2U))));
        tracep->fullCData(oldp+19,(vlTOPp->top__DOT__TXbuffer),8);
        tracep->fullBit(oldp+20,(vlTOPp->top__DOT__TXstart));
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__op),6);
        tracep->fullCData(oldp+22,(vlTOPp->top__DOT__params),4);
        tracep->fullCData(oldp+23,(vlTOPp->top__DOT__testState),4);
        tracep->fullSData(oldp+24,(vlTOPp->top__DOT__ALU__DOT__r1),16);
        tracep->fullSData(oldp+25,(vlTOPp->top__DOT__ALU__DOT__b),16);
        tracep->fullSData(oldp+26,(vlTOPp->top__DOT__ALU__DOT__r0),16);
        tracep->fullIData(oldp+27,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        tracep->fullIData(oldp+28,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        tracep->fullSData(oldp+29,(vlTOPp->top__DOT__ALU__DOT__log),16);
        tracep->fullSData(oldp+30,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
        tracep->fullSData(oldp+31,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
        tracep->fullSData(oldp+32,(vlTOPp->top__DOT__ALU__DOT__a),16);
        tracep->fullBit(oldp+33,(vlTOPp->CLK));
        tracep->fullBit(oldp+34,(vlTOPp->RX));
        tracep->fullBit(oldp+35,(vlTOPp->TX));
        tracep->fullBit(oldp+36,(vlTOPp->GPIO3));
        tracep->fullBit(oldp+37,(vlTOPp->GPIO9));
        tracep->fullBit(oldp+38,(vlTOPp->GPIO11));
        tracep->fullIData(oldp+39,(vlTOPp->top__DOT__clkdiv),25);
        tracep->fullCData(oldp+40,(0U),3);
        tracep->fullCData(oldp+41,(1U),3);
        tracep->fullIData(oldp+42,(2U),32);
    }
}
