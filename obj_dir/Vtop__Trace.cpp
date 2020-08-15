// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->top__DOT__TXbuffer),8);
            tracep->chgBit(oldp+1,(vlTOPp->top__DOT__TXstart));
            tracep->chgSData(oldp+2,(vlTOPp->top__DOT__a),16);
            tracep->chgSData(oldp+3,(vlTOPp->top__DOT__b),16);
            tracep->chgCData(oldp+4,(vlTOPp->top__DOT__op),2);
            tracep->chgSData(oldp+5,(vlTOPp->top__DOT__res),16);
            tracep->chgBit(oldp+6,(vlTOPp->top__DOT__overflow));
            tracep->chgCData(oldp+7,(vlTOPp->top__DOT__testState),4);
            tracep->chgIData(oldp+8,(vlTOPp->top__DOT__clkdiv),25);
            tracep->chgIData(oldp+9,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
            tracep->chgIData(oldp+10,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+11,(vlTOPp->top__DOT__RXbuffer),8);
            tracep->chgBit(oldp+12,(vlTOPp->top__DOT__RXready));
            tracep->chgBit(oldp+13,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgCData(oldp+14,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
            tracep->chgBit(oldp+15,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                           >> 2U))));
            tracep->chgCData(oldp+16,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
            tracep->chgBit(oldp+17,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgCData(oldp+18,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
            tracep->chgCData(oldp+19,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
            tracep->chgCData(oldp+20,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
            tracep->chgBit(oldp+21,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                           >> 2U))));
        }
        tracep->chgBit(oldp+22,(vlTOPp->CLK));
        tracep->chgBit(oldp+23,(vlTOPp->RX));
        tracep->chgBit(oldp+24,(vlTOPp->TX));
        tracep->chgBit(oldp+25,(vlTOPp->GPIO0));
        tracep->chgBit(oldp+26,(vlTOPp->GPIO1));
        tracep->chgBit(oldp+27,(vlTOPp->GPIO2));
        tracep->chgBit(oldp+28,(vlTOPp->GPIO3));
        tracep->chgBit(oldp+29,(vlTOPp->GPIO9));
        tracep->chgBit(oldp+30,(vlTOPp->GPIO11));
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
