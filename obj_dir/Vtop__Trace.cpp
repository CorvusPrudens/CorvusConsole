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
            tracep->chgCData(oldp+0,(vlTOPp->top__DOT__a),3);
            tracep->chgCData(oldp+1,(vlTOPp->top__DOT__y),3);
            tracep->chgBit(oldp+2,(vlTOPp->top__DOT__overflow));
            tracep->chgIData(oldp+3,(vlTOPp->top__DOT__clkdiv),25);
            tracep->chgSData(oldp+4,(vlTOPp->top__DOT__ALU__DOT__r0),16);
            tracep->chgSData(oldp+5,(vlTOPp->top__DOT__ALU__DOT__r1),16);
            tracep->chgSData(oldp+6,(vlTOPp->top__DOT__ALU__DOT__r2),16);
            tracep->chgSData(oldp+7,(vlTOPp->top__DOT__ALU__DOT__r3),16);
            tracep->chgSData(oldp+8,(vlTOPp->top__DOT__ALU__DOT__r4),16);
            tracep->chgSData(oldp+9,(vlTOPp->top__DOT__ALU__DOT__r5),16);
            tracep->chgSData(oldp+10,(vlTOPp->top__DOT__ALU__DOT__r6),16);
            tracep->chgSData(oldp+11,(vlTOPp->top__DOT__ALU__DOT__r7),16);
            tracep->chgIData(oldp+12,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
            tracep->chgIData(oldp+13,(vlTOPp->top__DOT__ALU__DOT__mult),17);
            tracep->chgSData(oldp+14,(vlTOPp->top__DOT__ALU__DOT__a),16);
            tracep->chgSData(oldp+15,(vlTOPp->top__DOT__ALU__DOT__b),16);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+16,(vlTOPp->top__DOT__RXbuffer),8);
            tracep->chgBit(oldp+17,(vlTOPp->top__DOT__RXready));
            tracep->chgBit(oldp+18,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgCData(oldp+19,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
            tracep->chgBit(oldp+20,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                           >> 2U))));
            tracep->chgCData(oldp+21,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
            tracep->chgBit(oldp+22,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgCData(oldp+23,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
            tracep->chgCData(oldp+24,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
            tracep->chgCData(oldp+25,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
            tracep->chgBit(oldp+26,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                           >> 2U))));
        }
        tracep->chgBit(oldp+27,(vlTOPp->CLK));
        tracep->chgBit(oldp+28,(vlTOPp->RX));
        tracep->chgBit(oldp+29,(vlTOPp->TX));
        tracep->chgBit(oldp+30,(vlTOPp->GPIO3));
        tracep->chgBit(oldp+31,(vlTOPp->GPIO9));
        tracep->chgBit(oldp+32,(vlTOPp->GPIO11));
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
