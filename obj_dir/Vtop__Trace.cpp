// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 3U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 4U))))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 5U))))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 6U))))) {
            vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->top__DOT__TXbuffer),8);
        vcdp->chgBit(c+9,(vlTOPp->top__DOT__TXstart));
        vcdp->chgBit(c+17,(vlTOPp->top__DOT__testClock));
        vcdp->chgBus(c+25,(vlTOPp->top__DOT__testState),4);
        vcdp->chgBus(c+33,(vlTOPp->top__DOT__clkdiv),25);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+41,(vlTOPp->top__DOT__RXbuffer),8);
        vcdp->chgBit(c+49,(vlTOPp->top__DOT__RXready));
        vcdp->chgBit(c+57,((0U != (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        vcdp->chgBus(c+65,(vlTOPp->top__DOT__FTDI__DOT__baudAcc),3);
        vcdp->chgBit(c+73,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                  >> 2U))));
        vcdp->chgBus(c+81,(vlTOPp->top__DOT__FTDI__DOT__TXstate),4);
        vcdp->chgBit(c+89,((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))));
        vcdp->chgBus(c+97,(vlTOPp->top__DOT__FTDI__DOT__TXshift),8);
        vcdp->chgBus(c+105,(vlTOPp->top__DOT__FTDI__DOT__RXstate),4);
        vcdp->chgBus(c+113,(vlTOPp->top__DOT__FTDI__DOT__gap),3);
        vcdp->chgBit(c+121,((1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                   >> 2U))));
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+129,(vlTOPp->top__DOT__busState),4);
        vcdp->chgBus(c+137,(vlTOPp->top__DOT__aluOperand1),3);
        vcdp->chgBus(c+145,(vlTOPp->top__DOT__aluOperand2),3);
        vcdp->chgBus(c+153,(vlTOPp->top__DOT__aluResults),3);
        vcdp->chgBus(c+161,(vlTOPp->top__DOT__aluOperation),6);
        vcdp->chgBus(c+169,(vlTOPp->top__DOT__aluParams),4);
        vcdp->chgBit(c+177,(vlTOPp->top__DOT__aluReadBus));
        vcdp->chgBit(c+185,(vlTOPp->top__DOT__ramWrite));
        vcdp->chgBus(c+193,(vlTOPp->top__DOT__CONTROL__DOT__increment),2);
        vcdp->chgBit(c+201,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+209,(vlTOPp->top__DOT__ALU__DOT__g),16);
        vcdp->chgBus(c+217,(vlTOPp->top__DOT__CONTROL__DOT__programCounter),16);
        vcdp->chgBus(c+225,((0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                        >> 0x10U))),16);
        vcdp->chgBus(c+233,(vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern),32);
        vcdp->chgBit(c+241,(vlTOPp->top__DOT__overflow));
        vcdp->chgBus(c+249,((3U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)),2);
        vcdp->chgBus(c+257,((0x1fU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                      >> 2U))),5);
        vcdp->chgBus(c+265,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                   >> 7U))),3);
        vcdp->chgBus(c+273,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                   >> 0xaU))),3);
        vcdp->chgBus(c+281,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                   >> 0xdU))),3);
        vcdp->chgBus(c+289,(vlTOPp->top__DOT__ALU__DOT__a),16);
        vcdp->chgBus(c+297,(vlTOPp->top__DOT__ALU__DOT__b),16);
        vcdp->chgBus(c+305,(vlTOPp->top__DOT__ALU__DOT__c),16);
        vcdp->chgBus(c+313,(vlTOPp->top__DOT__ALU__DOT__d),16);
        vcdp->chgBus(c+321,(vlTOPp->top__DOT__ALU__DOT__e),16);
        vcdp->chgBus(c+329,(vlTOPp->top__DOT__ALU__DOT__f),16);
        vcdp->chgBus(c+337,(vlTOPp->top__DOT__ALU__DOT__h),16);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+345,(vlTOPp->top__DOT__bus),16);
        vcdp->chgBus(c+353,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
        vcdp->chgBus(c+361,(vlTOPp->top__DOT__ALU__DOT__mult),17);
        vcdp->chgBus(c+369,(vlTOPp->top__DOT__ALU__DOT__log),16);
        vcdp->chgBus(c+377,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+385,(vlTOPp->top__DOT__ramAddress),16);
        vcdp->chgBus(c+393,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
        vcdp->chgBus(c+401,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
        vcdp->chgBus(c+409,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
        vcdp->chgBus(c+417,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+425,(vlTOPp->CLK));
        vcdp->chgBit(c+433,(vlTOPp->RX));
        vcdp->chgBit(c+441,(vlTOPp->TX));
        vcdp->chgBit(c+449,(vlTOPp->GPIO3));
        vcdp->chgBit(c+457,(vlTOPp->GPIO9));
        vcdp->chgBit(c+465,(vlTOPp->GPIO11));
        vcdp->chgBit(c+473,(vlTOPp->CE));
        vcdp->chgBit(c+481,(vlTOPp->OE));
        vcdp->chgBit(c+489,(vlTOPp->WR));
        vcdp->chgBit(c+497,(vlTOPp->UB));
        vcdp->chgBit(c+505,(vlTOPp->LB));
        vcdp->chgBit(c+513,(vlTOPp->A0));
        vcdp->chgBit(c+521,(vlTOPp->A1));
        vcdp->chgBit(c+529,(vlTOPp->A2));
        vcdp->chgBit(c+537,(vlTOPp->A3));
        vcdp->chgBit(c+545,(vlTOPp->A4));
        vcdp->chgBit(c+553,(vlTOPp->A5));
        vcdp->chgBit(c+561,(vlTOPp->A6));
        vcdp->chgBit(c+569,(vlTOPp->A7));
        vcdp->chgBit(c+577,(vlTOPp->A8));
        vcdp->chgBit(c+585,(vlTOPp->A9));
        vcdp->chgBit(c+593,(vlTOPp->A10));
        vcdp->chgBit(c+601,(vlTOPp->A11));
        vcdp->chgBit(c+609,(vlTOPp->A12));
        vcdp->chgBit(c+617,(vlTOPp->A13));
        vcdp->chgBit(c+625,(vlTOPp->A14));
        vcdp->chgBit(c+633,(vlTOPp->A15));
        vcdp->chgBit(c+641,(vlTOPp->D0));
        vcdp->chgBit(c+649,(vlTOPp->D1));
        vcdp->chgBit(c+657,(vlTOPp->D2));
        vcdp->chgBit(c+665,(vlTOPp->D3));
        vcdp->chgBit(c+673,(vlTOPp->D4));
        vcdp->chgBit(c+681,(vlTOPp->D5));
        vcdp->chgBit(c+689,(vlTOPp->D6));
        vcdp->chgBit(c+697,(vlTOPp->D7));
        vcdp->chgBit(c+705,(vlTOPp->D8));
        vcdp->chgBit(c+713,(vlTOPp->D9));
        vcdp->chgBit(c+721,(vlTOPp->D10));
        vcdp->chgBit(c+729,(vlTOPp->D11));
        vcdp->chgBit(c+737,(vlTOPp->D12));
        vcdp->chgBit(c+745,(vlTOPp->D13));
        vcdp->chgBit(c+753,(vlTOPp->D14));
        vcdp->chgBit(c+761,(vlTOPp->D15));
        vcdp->chgBit(c+769,(vlTOPp->D0_in));
        vcdp->chgBit(c+777,(vlTOPp->D1_in));
        vcdp->chgBit(c+785,(vlTOPp->D2_in));
        vcdp->chgBit(c+793,(vlTOPp->D3_in));
        vcdp->chgBit(c+801,(vlTOPp->D4_in));
        vcdp->chgBit(c+809,(vlTOPp->D5_in));
        vcdp->chgBit(c+817,(vlTOPp->D6_in));
        vcdp->chgBit(c+825,(vlTOPp->D7_in));
        vcdp->chgBit(c+833,(vlTOPp->D8_in));
        vcdp->chgBit(c+841,(vlTOPp->D9_in));
        vcdp->chgBit(c+849,(vlTOPp->D10_in));
        vcdp->chgBit(c+857,(vlTOPp->D11_in));
        vcdp->chgBit(c+865,(vlTOPp->D12_in));
        vcdp->chgBit(c+873,(vlTOPp->D13_in));
        vcdp->chgBit(c+881,(vlTOPp->D14_in));
        vcdp->chgBit(c+889,(vlTOPp->D15_in));
        vcdp->chgBus(c+897,((((IData)(vlTOPp->D15_in) 
                              << 0xfU) | (((IData)(vlTOPp->D14_in) 
                                           << 0xeU) 
                                          | (((IData)(vlTOPp->D13_in) 
                                              << 0xdU) 
                                             | (((IData)(vlTOPp->D12_in) 
                                                 << 0xcU) 
                                                | (((IData)(vlTOPp->D11_in) 
                                                    << 0xbU) 
                                                   | (((IData)(vlTOPp->D10_in) 
                                                       << 0xaU) 
                                                      | (((IData)(vlTOPp->D9_in) 
                                                          << 9U) 
                                                         | (((IData)(vlTOPp->D8_in) 
                                                             << 8U) 
                                                            | (((IData)(vlTOPp->D7_in) 
                                                                << 7U) 
                                                               | (((IData)(vlTOPp->D6_in) 
                                                                   << 6U) 
                                                                  | (((IData)(vlTOPp->D5_in) 
                                                                      << 5U) 
                                                                     | (((IData)(vlTOPp->D4_in) 
                                                                         << 4U) 
                                                                        | (((IData)(vlTOPp->D3_in) 
                                                                            << 3U) 
                                                                           | (((IData)(vlTOPp->D2_in) 
                                                                               << 2U) 
                                                                              | (((IData)(vlTOPp->D1_in) 
                                                                                << 1U) 
                                                                                | (IData)(vlTOPp->D0_in))))))))))))))))),16);
    }
}
