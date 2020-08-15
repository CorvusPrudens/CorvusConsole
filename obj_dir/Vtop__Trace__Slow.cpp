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
        tracep->declBit(c+28,"CLK", false,-1);
        tracep->declBit(c+29,"RX", false,-1);
        tracep->declBit(c+30,"TX", false,-1);
        tracep->declBit(c+31,"GPIO3", false,-1);
        tracep->declBit(c+32,"GPIO9", false,-1);
        tracep->declBit(c+33,"GPIO11", false,-1);
        tracep->declBit(c+28,"top CLK", false,-1);
        tracep->declBit(c+29,"top RX", false,-1);
        tracep->declBit(c+30,"top TX", false,-1);
        tracep->declBit(c+31,"top GPIO3", false,-1);
        tracep->declBit(c+32,"top GPIO9", false,-1);
        tracep->declBit(c+33,"top GPIO11", false,-1);
        tracep->declBus(c+17,"top RXbuffer", false,-1, 7,0);
        tracep->declBus(c+34,"top TXbuffer", false,-1, 7,0);
        tracep->declBit(c+35,"top TXstart", false,-1);
        tracep->declBit(c+18,"top RXready", false,-1);
        tracep->declBit(c+19,"top TXbusy", false,-1);
        tracep->declBus(c+1,"top a", false,-1, 2,0);
        tracep->declBus(c+36,"top b", false,-1, 2,0);
        tracep->declBus(c+2,"top y", false,-1, 2,0);
        tracep->declBus(c+37,"top op", false,-1, 1,0);
        tracep->declBit(c+3,"top overflow", false,-1);
        tracep->declBus(c+38,"top testState", false,-1, 3,0);
        tracep->declBus(c+4,"top clkdiv", false,-1, 24,0);
        tracep->declBit(c+28,"top FTDI CLK", false,-1);
        tracep->declBit(c+29,"top FTDI RX", false,-1);
        tracep->declBus(c+34,"top FTDI TXbuffer", false,-1, 7,0);
        tracep->declBit(c+35,"top FTDI TXstart", false,-1);
        tracep->declBit(c+30,"top FTDI TX", false,-1);
        tracep->declBus(c+17,"top FTDI RXbuffer", false,-1, 7,0);
        tracep->declBit(c+18,"top FTDI RXready", false,-1);
        tracep->declBit(c+19,"top FTDI TXbusy", false,-1);
        tracep->declBus(c+39,"top FTDI CLOCK_DIVISOR", false,-1, 31,0);
        tracep->declBus(c+20,"top FTDI baudAcc", false,-1, 2,0);
        tracep->declBit(c+21,"top FTDI baudTick", false,-1);
        tracep->declBus(c+22,"top FTDI TXstate", false,-1, 3,0);
        tracep->declBit(c+23,"top FTDI TXready", false,-1);
        tracep->declBus(c+24,"top FTDI TXshift", false,-1, 7,0);
        tracep->declBus(c+25,"top FTDI RXstate", false,-1, 3,0);
        tracep->declBus(c+26,"top FTDI gap", false,-1, 2,0);
        tracep->declBit(c+27,"top FTDI nextBit", false,-1);
        tracep->declBit(c+28,"top ALU CLK", false,-1);
        tracep->declBus(c+1,"top ALU aindex", false,-1, 2,0);
        tracep->declBus(c+36,"top ALU bindex", false,-1, 2,0);
        tracep->declBus(c+2,"top ALU yindex", false,-1, 2,0);
        tracep->declBus(c+37,"top ALU op", false,-1, 1,0);
        tracep->declBit(c+3,"top ALU overflow", false,-1);
        tracep->declBus(c+5,"top ALU r0", false,-1, 15,0);
        tracep->declBus(c+6,"top ALU r1", false,-1, 15,0);
        tracep->declBus(c+7,"top ALU r2", false,-1, 15,0);
        tracep->declBus(c+8,"top ALU r3", false,-1, 15,0);
        tracep->declBus(c+9,"top ALU r4", false,-1, 15,0);
        tracep->declBus(c+10,"top ALU r5", false,-1, 15,0);
        tracep->declBus(c+11,"top ALU r6", false,-1, 15,0);
        tracep->declBus(c+12,"top ALU r7", false,-1, 15,0);
        tracep->declBus(c+13,"top ALU addsub", false,-1, 16,0);
        tracep->declBus(c+14,"top ALU mult", false,-1, 16,0);
        tracep->declBus(c+15,"top ALU a", false,-1, 15,0);
        tracep->declBus(c+16,"top ALU b", false,-1, 15,0);
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
        tracep->fullCData(oldp+1,(vlTOPp->top__DOT__a),3);
        tracep->fullCData(oldp+2,(vlTOPp->top__DOT__y),3);
        tracep->fullBit(oldp+3,(vlTOPp->top__DOT__overflow));
        tracep->fullIData(oldp+4,(vlTOPp->top__DOT__clkdiv),25);
        tracep->fullSData(oldp+5,(vlTOPp->top__DOT__ALU__DOT__r0),16);
        tracep->fullSData(oldp+6,(vlTOPp->top__DOT__ALU__DOT__r1),16);
        tracep->fullSData(oldp+7,(vlTOPp->top__DOT__ALU__DOT__r2),16);
        tracep->fullSData(oldp+8,(vlTOPp->top__DOT__ALU__DOT__r3),16);
        tracep->fullSData(oldp+9,(vlTOPp->top__DOT__ALU__DOT__r4),16);
        tracep->fullSData(oldp+10,(vlTOPp->top__DOT__ALU__DOT__r5),16);
        tracep->fullSData(oldp+11,(vlTOPp->top__DOT__ALU__DOT__r6),16);
        tracep->fullSData(oldp+12,(vlTOPp->top__DOT__ALU__DOT__r7),16);
        tracep->fullIData(oldp+13,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        tracep->fullIData(oldp+14,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        tracep->fullSData(oldp+15,(vlTOPp->top__DOT__ALU__DOT__a),16);
        tracep->fullSData(oldp+16,(vlTOPp->top__DOT__ALU__DOT__b),16);
        tracep->fullCData(oldp+17,(vlTOPp->top__DOT__RXbuffer),8);
        tracep->fullBit(oldp+18,(vlTOPp->top__DOT__RXready));
        tracep->fullBit(oldp+19,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+20,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
        tracep->fullBit(oldp+21,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                        >> 2U))));
        tracep->fullCData(oldp+22,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
        tracep->fullBit(oldp+23,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+24,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
        tracep->fullCData(oldp+25,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
        tracep->fullCData(oldp+26,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
        tracep->fullBit(oldp+27,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                        >> 2U))));
        tracep->fullBit(oldp+28,(vlTOPp->CLK));
        tracep->fullBit(oldp+29,(vlTOPp->RX));
        tracep->fullBit(oldp+30,(vlTOPp->TX));
        tracep->fullBit(oldp+31,(vlTOPp->GPIO3));
        tracep->fullBit(oldp+32,(vlTOPp->GPIO9));
        tracep->fullBit(oldp+33,(vlTOPp->GPIO11));
        tracep->fullCData(oldp+34,(0U),8);
        tracep->fullBit(oldp+35,(0U));
        tracep->fullCData(oldp+36,(1U),3);
        tracep->fullCData(oldp+37,(0U),2);
        tracep->fullCData(oldp+38,(0U),4);
        tracep->fullIData(oldp+39,(2U),32);
    }
}
