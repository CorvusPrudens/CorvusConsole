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
            tracep->chgBit(oldp+27,(vlTOPp->top__DOT__ramWrite));
            tracep->chgBit(oldp+28,(vlTOPp->top__DOT__CONTROL__DOT__increment));
            tracep->chgBit(oldp+29,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgCData(oldp+30,(vlTOPp->top__DOT__TXbuffer),8);
            tracep->chgBit(oldp+31,(vlTOPp->top__DOT__TXstart));
            tracep->chgIData(oldp+32,(vlTOPp->top__DOT__testWord),32);
            tracep->chgBit(oldp+33,(vlTOPp->top__DOT__testClock));
            tracep->chgSData(oldp+34,((0xffffU & (vlTOPp->top__DOT__testWord 
                                                  >> 0x10U))),16);
            tracep->chgCData(oldp+35,(vlTOPp->top__DOT__testState),4);
            tracep->chgCData(oldp+36,((3U & vlTOPp->top__DOT__testWord)),2);
            tracep->chgCData(oldp+37,((0x1fU & (vlTOPp->top__DOT__testWord 
                                                >> 2U))),5);
            tracep->chgCData(oldp+38,((7U & (vlTOPp->top__DOT__testWord 
                                             >> 7U))),3);
            tracep->chgCData(oldp+39,((7U & (vlTOPp->top__DOT__testWord 
                                             >> 0xaU))),3);
            tracep->chgCData(oldp+40,((7U & (vlTOPp->top__DOT__testWord 
                                             >> 0xdU))),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgSData(oldp+41,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
            tracep->chgSData(oldp+42,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
            tracep->chgSData(oldp+43,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
            tracep->chgSData(oldp+44,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgSData(oldp+45,(vlTOPp->top__DOT__bus),16);
            tracep->chgIData(oldp+46,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
            tracep->chgIData(oldp+47,(vlTOPp->top__DOT__ALU__DOT__mult),17);
            tracep->chgSData(oldp+48,(vlTOPp->top__DOT__ALU__DOT__log),16);
            tracep->chgSData(oldp+49,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
        }
        tracep->chgBit(oldp+50,(vlTOPp->CLK));
        tracep->chgBit(oldp+51,(vlTOPp->RX));
        tracep->chgBit(oldp+52,(vlTOPp->TX));
        tracep->chgBit(oldp+53,(vlTOPp->GPIO3));
        tracep->chgBit(oldp+54,(vlTOPp->GPIO9));
        tracep->chgBit(oldp+55,(vlTOPp->GPIO11));
        tracep->chgBit(oldp+56,(vlTOPp->CE));
        tracep->chgBit(oldp+57,(vlTOPp->OE));
        tracep->chgBit(oldp+58,(vlTOPp->WR));
        tracep->chgBit(oldp+59,(vlTOPp->UB));
        tracep->chgBit(oldp+60,(vlTOPp->LB));
        tracep->chgBit(oldp+61,(vlTOPp->A0));
        tracep->chgBit(oldp+62,(vlTOPp->A1));
        tracep->chgBit(oldp+63,(vlTOPp->A2));
        tracep->chgBit(oldp+64,(vlTOPp->A3));
        tracep->chgBit(oldp+65,(vlTOPp->A4));
        tracep->chgBit(oldp+66,(vlTOPp->A5));
        tracep->chgBit(oldp+67,(vlTOPp->A6));
        tracep->chgBit(oldp+68,(vlTOPp->A7));
        tracep->chgBit(oldp+69,(vlTOPp->A8));
        tracep->chgBit(oldp+70,(vlTOPp->A9));
        tracep->chgBit(oldp+71,(vlTOPp->A10));
        tracep->chgBit(oldp+72,(vlTOPp->A11));
        tracep->chgBit(oldp+73,(vlTOPp->A12));
        tracep->chgBit(oldp+74,(vlTOPp->A13));
        tracep->chgBit(oldp+75,(vlTOPp->A14));
        tracep->chgBit(oldp+76,(vlTOPp->A15));
        tracep->chgBit(oldp+77,(vlTOPp->D0));
        tracep->chgBit(oldp+78,(vlTOPp->D1));
        tracep->chgBit(oldp+79,(vlTOPp->D2));
        tracep->chgBit(oldp+80,(vlTOPp->D3));
        tracep->chgBit(oldp+81,(vlTOPp->D4));
        tracep->chgBit(oldp+82,(vlTOPp->D5));
        tracep->chgBit(oldp+83,(vlTOPp->D6));
        tracep->chgBit(oldp+84,(vlTOPp->D7));
        tracep->chgBit(oldp+85,(vlTOPp->D8));
        tracep->chgBit(oldp+86,(vlTOPp->D9));
        tracep->chgBit(oldp+87,(vlTOPp->D10));
        tracep->chgBit(oldp+88,(vlTOPp->D11));
        tracep->chgBit(oldp+89,(vlTOPp->D12));
        tracep->chgBit(oldp+90,(vlTOPp->D13));
        tracep->chgBit(oldp+91,(vlTOPp->D14));
        tracep->chgBit(oldp+92,(vlTOPp->D15));
        tracep->chgBit(oldp+93,(vlTOPp->D0_in));
        tracep->chgBit(oldp+94,(vlTOPp->D1_in));
        tracep->chgBit(oldp+95,(vlTOPp->D2_in));
        tracep->chgBit(oldp+96,(vlTOPp->D3_in));
        tracep->chgBit(oldp+97,(vlTOPp->D4_in));
        tracep->chgBit(oldp+98,(vlTOPp->D5_in));
        tracep->chgBit(oldp+99,(vlTOPp->D6_in));
        tracep->chgBit(oldp+100,(vlTOPp->D7_in));
        tracep->chgBit(oldp+101,(vlTOPp->D8_in));
        tracep->chgBit(oldp+102,(vlTOPp->D9_in));
        tracep->chgBit(oldp+103,(vlTOPp->D10_in));
        tracep->chgBit(oldp+104,(vlTOPp->D11_in));
        tracep->chgBit(oldp+105,(vlTOPp->D12_in));
        tracep->chgBit(oldp+106,(vlTOPp->D13_in));
        tracep->chgBit(oldp+107,(vlTOPp->D14_in));
        tracep->chgBit(oldp+108,(vlTOPp->D15_in));
        tracep->chgSData(oldp+109,(vlTOPp->top__DOT__ramAddress),16);
        tracep->chgSData(oldp+110,(vlTOPp->top__DOT__ramOut),16);
        tracep->chgIData(oldp+111,(vlTOPp->top__DOT__clkdiv),25);
        tracep->chgSData(oldp+112,(vlTOPp->top__DOT__ALU__DOT__a),16);
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
