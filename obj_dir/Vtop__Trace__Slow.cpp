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
        tracep->declBit(c+23,"CLK", false,-1);
        tracep->declBit(c+24,"RX", false,-1);
        tracep->declBit(c+25,"TX", false,-1);
        tracep->declBit(c+26,"GPIO0", false,-1);
        tracep->declBit(c+27,"GPIO1", false,-1);
        tracep->declBit(c+28,"GPIO2", false,-1);
        tracep->declBit(c+29,"GPIO3", false,-1);
        tracep->declBit(c+30,"GPIO9", false,-1);
        tracep->declBit(c+31,"GPIO11", false,-1);
        tracep->declBit(c+23,"top CLK", false,-1);
        tracep->declBit(c+24,"top RX", false,-1);
        tracep->declBit(c+25,"top TX", false,-1);
        tracep->declBit(c+26,"top GPIO0", false,-1);
        tracep->declBit(c+27,"top GPIO1", false,-1);
        tracep->declBit(c+28,"top GPIO2", false,-1);
        tracep->declBit(c+29,"top GPIO3", false,-1);
        tracep->declBit(c+30,"top GPIO9", false,-1);
        tracep->declBit(c+31,"top GPIO11", false,-1);
        tracep->declBus(c+12,"top RXbuffer", false,-1, 7,0);
        tracep->declBus(c+1,"top TXbuffer", false,-1, 7,0);
        tracep->declBit(c+2,"top TXstart", false,-1);
        tracep->declBit(c+13,"top RXready", false,-1);
        tracep->declBit(c+14,"top TXbusy", false,-1);
        tracep->declBus(c+3,"top a", false,-1, 15,0);
        tracep->declBus(c+4,"top b", false,-1, 15,0);
        tracep->declBus(c+5,"top op", false,-1, 1,0);
        tracep->declBus(c+6,"top res", false,-1, 15,0);
        tracep->declBit(c+7,"top overflow", false,-1);
        tracep->declBus(c+8,"top testState", false,-1, 3,0);
        tracep->declBus(c+9,"top clkdiv", false,-1, 24,0);
        tracep->declBit(c+23,"top FTDI CLK", false,-1);
        tracep->declBit(c+24,"top FTDI RX", false,-1);
        tracep->declBus(c+1,"top FTDI TXbuffer", false,-1, 7,0);
        tracep->declBit(c+2,"top FTDI TXstart", false,-1);
        tracep->declBit(c+25,"top FTDI TX", false,-1);
        tracep->declBus(c+12,"top FTDI RXbuffer", false,-1, 7,0);
        tracep->declBit(c+13,"top FTDI RXready", false,-1);
        tracep->declBit(c+14,"top FTDI TXbusy", false,-1);
        tracep->declBus(c+32,"top FTDI CLOCK_DIVISOR", false,-1, 31,0);
        tracep->declBus(c+15,"top FTDI baudAcc", false,-1, 2,0);
        tracep->declBit(c+16,"top FTDI baudTick", false,-1);
        tracep->declBus(c+17,"top FTDI TXstate", false,-1, 3,0);
        tracep->declBit(c+18,"top FTDI TXready", false,-1);
        tracep->declBus(c+19,"top FTDI TXshift", false,-1, 7,0);
        tracep->declBus(c+20,"top FTDI RXstate", false,-1, 3,0);
        tracep->declBus(c+21,"top FTDI gap", false,-1, 2,0);
        tracep->declBit(c+22,"top FTDI nextBit", false,-1);
        tracep->declBit(c+23,"top ALU CLK", false,-1);
        tracep->declBus(c+3,"top ALU a", false,-1, 15,0);
        tracep->declBus(c+4,"top ALU b", false,-1, 15,0);
        tracep->declBus(c+5,"top ALU op", false,-1, 1,0);
        tracep->declBus(c+6,"top ALU res", false,-1, 15,0);
        tracep->declBit(c+7,"top ALU overflow", false,-1);
        tracep->declBus(c+10,"top ALU addsub", false,-1, 16,0);
        tracep->declBus(c+11,"top ALU mult", false,-1, 16,0);
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
        tracep->fullSData(oldp+3,(vlTOPp->top__DOT__a),16);
        tracep->fullSData(oldp+4,(vlTOPp->top__DOT__b),16);
        tracep->fullCData(oldp+5,(vlTOPp->top__DOT__op),2);
        tracep->fullSData(oldp+6,(vlTOPp->top__DOT__res),16);
        tracep->fullBit(oldp+7,(vlTOPp->top__DOT__overflow));
        tracep->fullCData(oldp+8,(vlTOPp->top__DOT__testState),4);
        tracep->fullIData(oldp+9,(vlTOPp->top__DOT__clkdiv),25);
        tracep->fullIData(oldp+10,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        tracep->fullIData(oldp+11,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        tracep->fullCData(oldp+12,(vlTOPp->top__DOT__RXbuffer),8);
        tracep->fullBit(oldp+13,(vlTOPp->top__DOT__RXready));
        tracep->fullBit(oldp+14,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+15,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
        tracep->fullBit(oldp+16,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                        >> 2U))));
        tracep->fullCData(oldp+17,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
        tracep->fullBit(oldp+18,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        tracep->fullCData(oldp+19,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
        tracep->fullCData(oldp+20,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
        tracep->fullBit(oldp+22,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                        >> 2U))));
        tracep->fullBit(oldp+23,(vlTOPp->CLK));
        tracep->fullBit(oldp+24,(vlTOPp->RX));
        tracep->fullBit(oldp+25,(vlTOPp->TX));
        tracep->fullBit(oldp+26,(vlTOPp->GPIO0));
        tracep->fullBit(oldp+27,(vlTOPp->GPIO1));
        tracep->fullBit(oldp+28,(vlTOPp->GPIO2));
        tracep->fullBit(oldp+29,(vlTOPp->GPIO3));
        tracep->fullBit(oldp+30,(vlTOPp->GPIO9));
        tracep->fullBit(oldp+31,(vlTOPp->GPIO11));
        tracep->fullIData(oldp+32,(2U),32);
    }
}
