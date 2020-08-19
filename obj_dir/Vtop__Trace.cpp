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
            tracep->chgCData(oldp+0,(vlTOPp->top__DOT__RXbuffer),8);
            tracep->chgBit(oldp+1,(vlTOPp->top__DOT__RXready));
            tracep->chgBit(oldp+2,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgCData(oldp+3,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
            tracep->chgBit(oldp+4,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                          >> 2U))));
            tracep->chgCData(oldp+5,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
            tracep->chgBit(oldp+6,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
            tracep->chgCData(oldp+7,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
            tracep->chgCData(oldp+8,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
            tracep->chgCData(oldp+9,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
            tracep->chgBit(oldp+10,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                           >> 2U))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgSData(oldp+11,(vlTOPp->top__DOT__ALU__DOT__g),16);
            tracep->chgBit(oldp+12,(vlTOPp->top__DOT__overflow));
            tracep->chgSData(oldp+13,(vlTOPp->top__DOT__CONTROL__DOT__programCounter),16);
            tracep->chgSData(oldp+14,(vlTOPp->top__DOT__ALU__DOT__b),16);
            tracep->chgSData(oldp+15,(vlTOPp->top__DOT__ALU__DOT__c),16);
            tracep->chgSData(oldp+16,(vlTOPp->top__DOT__ALU__DOT__d),16);
            tracep->chgSData(oldp+17,(vlTOPp->top__DOT__ALU__DOT__e),16);
            tracep->chgSData(oldp+18,(vlTOPp->top__DOT__ALU__DOT__f),16);
            tracep->chgSData(oldp+19,(vlTOPp->top__DOT__ALU__DOT__h),16);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgCData(oldp+20,(vlTOPp->top__DOT__busState),4);
            tracep->chgCData(oldp+21,(vlTOPp->top__DOT__aluOperand1),3);
            tracep->chgCData(oldp+22,(vlTOPp->top__DOT__aluOperand2),3);
            tracep->chgCData(oldp+23,(vlTOPp->top__DOT__aluResults),3);
            tracep->chgCData(oldp+24,(vlTOPp->top__DOT__aluOperation),6);
            tracep->chgCData(oldp+25,(vlTOPp->top__DOT__aluParams),4);
            tracep->chgBit(oldp+26,(vlTOPp->top__DOT__aluReadBus));
            tracep->chgBit(oldp+27,(vlTOPp->top__DOT__CONTROL__DOT__increment));
            tracep->chgBit(oldp+28,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgCData(oldp+29,(vlTOPp->top__DOT__TXbuffer),8);
            tracep->chgBit(oldp+30,(vlTOPp->top__DOT__TXstart));
            tracep->chgIData(oldp+31,(vlTOPp->top__DOT__testWord),32);
            tracep->chgBit(oldp+32,(vlTOPp->top__DOT__testClock));
            tracep->chgSData(oldp+33,((0xffffU & (vlTOPp->top__DOT__testWord 
                                                  >> 0x10U))),16);
            tracep->chgCData(oldp+34,(vlTOPp->top__DOT__testState),4);
            tracep->chgCData(oldp+35,((0x3fU & vlTOPp->top__DOT__testWord)),6);
            tracep->chgCData(oldp+36,((7U & (vlTOPp->top__DOT__testWord 
                                             >> 7U))),3);
            tracep->chgCData(oldp+37,((7U & (vlTOPp->top__DOT__testWord 
                                             >> 0xaU))),3);
            tracep->chgCData(oldp+38,((7U & (vlTOPp->top__DOT__testWord 
                                             >> 0xdU))),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgSData(oldp+39,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
            tracep->chgSData(oldp+40,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
            tracep->chgSData(oldp+41,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
            tracep->chgSData(oldp+42,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgSData(oldp+43,(vlTOPp->top__DOT__bus),16);
            tracep->chgIData(oldp+44,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
            tracep->chgIData(oldp+45,(vlTOPp->top__DOT__ALU__DOT__mult),17);
            tracep->chgSData(oldp+46,(vlTOPp->top__DOT__ALU__DOT__log),16);
            tracep->chgSData(oldp+47,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
        }
        tracep->chgBit(oldp+48,(vlTOPp->CLK));
        tracep->chgBit(oldp+49,(vlTOPp->RX));
        tracep->chgBit(oldp+50,(vlTOPp->TX));
        tracep->chgBit(oldp+51,(vlTOPp->GPIO3));
        tracep->chgBit(oldp+52,(vlTOPp->GPIO9));
        tracep->chgBit(oldp+53,(vlTOPp->GPIO11));
        tracep->chgSData(oldp+54,((0xffffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode)
                                               ? (IData)(vlTOPp->top__DOT__ALU__DOT__g)
                                               : (vlTOPp->top__DOT__testWord 
                                                  >> 0x10U)))),16);
        tracep->chgIData(oldp+55,(vlTOPp->top__DOT__clkdiv),25);
        tracep->chgSData(oldp+56,(vlTOPp->top__DOT__ALU__DOT__a),16);
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
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
        vlTOPp->__Vm_traceActivity[6U] = 0U;
    }
}
