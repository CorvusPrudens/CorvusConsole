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
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgSData(oldp+0,(vlTOPp->top__DOT__ALU__DOT__r2),16);
            tracep->chgSData(oldp+1,(vlTOPp->top__DOT__ALU__DOT__r3),16);
            tracep->chgSData(oldp+2,(vlTOPp->top__DOT__ALU__DOT__r4),16);
            tracep->chgSData(oldp+3,(vlTOPp->top__DOT__ALU__DOT__r5),16);
            tracep->chgSData(oldp+4,(vlTOPp->top__DOT__ALU__DOT__r6),16);
            tracep->chgSData(oldp+5,(vlTOPp->top__DOT__ALU__DOT__r7),16);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+6,(vlTOPp->top__DOT__RXbuffer),8);
            tracep->chgBit(oldp+7,(vlTOPp->top__DOT__RXready));
            tracep->chgBit(oldp+8,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgBit(oldp+9,(vlTOPp->top__DOT__overflow));
            tracep->chgCData(oldp+10,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
            tracep->chgBit(oldp+11,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                           >> 2U))));
            tracep->chgCData(oldp+12,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
            tracep->chgBit(oldp+13,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgCData(oldp+14,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
            tracep->chgCData(oldp+15,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
            tracep->chgCData(oldp+16,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
            tracep->chgBit(oldp+17,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                           >> 2U))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+18,(vlTOPp->top__DOT__TXbuffer),8);
            tracep->chgBit(oldp+19,(vlTOPp->top__DOT__TXstart));
            tracep->chgCData(oldp+20,(vlTOPp->top__DOT__op),6);
            tracep->chgCData(oldp+21,(vlTOPp->top__DOT__params),4);
            tracep->chgCData(oldp+22,(vlTOPp->top__DOT__testState),4);
            tracep->chgSData(oldp+23,(vlTOPp->top__DOT__ALU__DOT__r1),16);
            tracep->chgSData(oldp+24,(vlTOPp->top__DOT__ALU__DOT__b),16);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgSData(oldp+25,(vlTOPp->top__DOT__ALU__DOT__r0),16);
            tracep->chgIData(oldp+26,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
            tracep->chgIData(oldp+27,(vlTOPp->top__DOT__ALU__DOT__mult),17);
            tracep->chgSData(oldp+28,(vlTOPp->top__DOT__ALU__DOT__log),16);
            tracep->chgSData(oldp+29,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
            tracep->chgSData(oldp+30,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
            tracep->chgSData(oldp+31,(vlTOPp->top__DOT__ALU__DOT__a),16);
        }
        tracep->chgBit(oldp+32,(vlTOPp->CLK));
        tracep->chgBit(oldp+33,(vlTOPp->RX));
        tracep->chgBit(oldp+34,(vlTOPp->TX));
        tracep->chgBit(oldp+35,(vlTOPp->GPIO3));
        tracep->chgBit(oldp+36,(vlTOPp->GPIO9));
        tracep->chgBit(oldp+37,(vlTOPp->GPIO11));
        tracep->chgIData(oldp+38,(vlTOPp->top__DOT__clkdiv),25);
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
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
