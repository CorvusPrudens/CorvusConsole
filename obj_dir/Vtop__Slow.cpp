// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-10);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->GPIO9 = 1U;
    vlTOPp->GPIO11 = 0U;
    vlTOPp->top__DOT__testWord = 0U;
    vlTOPp->top__DOT__aluParams = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand2 = 0U;
    vlTOPp->top__DOT__busState = 0U;
    vlTOPp->top__DOT__aluOperand2 = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand1 = 0U;
    vlTOPp->top__DOT__aluOperand1 = 0U;
    vlTOPp->top__DOT__ALU__DOT__b = 0U;
    vlTOPp->top__DOT__ALU__DOT__c = 0U;
    vlTOPp->top__DOT__ALU__DOT__d = 0U;
    vlTOPp->top__DOT__ALU__DOT__e = 0U;
    vlTOPp->top__DOT__ALU__DOT__f = 0U;
    vlTOPp->top__DOT__ALU__DOT__g = 0U;
    vlTOPp->top__DOT__ALU__DOT__h = 0U;
    vlTOPp->top__DOT__testClock = 1U;
    vlTOPp->top__DOT__TXbuffer = 0U;
    vlTOPp->top__DOT__TXstart = 0U;
    vlTOPp->top__DOT__clkdiv = 0U;
    vlTOPp->top__DOT__FTDI__DOT__baudAcc = 0U;
    vlTOPp->top__DOT__FTDI__DOT__TXshift = 0U;
    vlTOPp->top__DOT__FTDI__DOT__TXstate = 0U;
    vlTOPp->top__DOT__testState = 0U;
    vlTOPp->top__DOT__RXready = 0U;
    vlTOPp->top__DOT__ALU__DOT__a = 2U;
    vlTOPp->top__DOT__FTDI__DOT__RXstate = 0U;
    vlTOPp->top__DOT__FTDI__DOT__gap = 0U;
    vlTOPp->top__DOT__RXbuffer = 0U;
    vlTOPp->top__DOT__aluResults = 0U;
    vlTOPp->top__DOT__aluOperation = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__increment = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__programCounter = 0U;
    vlTOPp->top__DOT__overflow = 0U;
    vlTOPp->top__DOT__bus = 0U;
    vlTOPp->top__DOT__aluReadBus = 0U;
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
    vlTOPp->top__DOT__FTDI__DOT__baudTick = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                                   >> 2U));
    vlTOPp->top__DOT__FTDI__DOT__TXready = (0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate));
    vlTOPp->TX = (1U & ((4U > (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate)) 
                        | (((IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate) 
                            >> 3U) & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXshift))));
    vlTOPp->top__DOT__ALU__DOT__operand2 = ((4U & (IData)(vlTOPp->top__DOT__aluOperand2))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->top__DOT__aluOperand2))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand2))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__h)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__g))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand2))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__f)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__e)))
                                             : ((2U 
                                                 & (IData)(vlTOPp->top__DOT__aluOperand2))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand2))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__d)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__c))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand2))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__b)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__a))));
    vlTOPp->top__DOT__ALU__DOT__operand1 = ((4U & (IData)(vlTOPp->top__DOT__aluOperand1))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->top__DOT__aluOperand1))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand1))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__h)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__g))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand1))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__f)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__e)))
                                             : ((2U 
                                                 & (IData)(vlTOPp->top__DOT__aluOperand1))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand1))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__d)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__c))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__aluOperand1))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__b)
                                                  : (IData)(vlTOPp->top__DOT__ALU__DOT__a))));
    vlTOPp->top__DOT__FTDI__DOT__nextBit = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                                  >> 2U));
    if ((8U & (IData)(vlTOPp->top__DOT__aluParams))) {
        vlTOPp->top__DOT__ALU__DOT__lshift = ((4U & (IData)(vlTOPp->top__DOT__aluParams))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0x8000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xfU))
                                                    : 
                                                   (0xc000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xeU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0xe000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xdU))
                                                    : 
                                                   (0xf000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0xf800U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xbU))
                                                    : 
                                                   (0xfc00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xaU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0xfe00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 9U))
                                                    : 
                                                   (0xff00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 8U)))));
        vlTOPp->top__DOT__ALU__DOT__rshift = ((4U & (IData)(vlTOPp->top__DOT__aluParams))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (1U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xfU))
                                                    : 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xeU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xdU))
                                                    : 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xbU))
                                                    : 
                                                   (0x3fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xaU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0x7fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 9U))
                                                    : 
                                                   (0xffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 8U)))));
    } else {
        vlTOPp->top__DOT__ALU__DOT__lshift = ((4U & (IData)(vlTOPp->top__DOT__aluParams))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0xff80U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 7U))
                                                    : 
                                                   (0xffc0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 6U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0xffe0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 5U))
                                                    : 
                                                   (0xfff0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0xfff8U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 3U))
                                                    : 
                                                   (0xfffcU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 2U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0xfffeU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1))));
        vlTOPp->top__DOT__ALU__DOT__rshift = ((4U & (IData)(vlTOPp->top__DOT__aluParams))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0x1ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 7U))
                                                    : 
                                                   (0x3ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 6U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0x7ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 5U))
                                                    : 
                                                   (0xfffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__aluParams))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0x1fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 3U))
                                                    : 
                                                   (0x3fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 2U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   (0x7fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1))));
    }
    vlTOPp->top__DOT__bus = ((8U & (IData)(vlTOPp->top__DOT__busState))
                              ? ((4U & (IData)(vlTOPp->top__DOT__busState))
                                  ? 0U : ((2U & (IData)(vlTOPp->top__DOT__busState))
                                           ? 0U : (
                                                   (1U 
                                                    & (IData)(vlTOPp->top__DOT__busState))
                                                    ? 0U
                                                    : 
                                                   ((0xff00U 
                                                     & (IData)(vlTOPp->top__DOT__bus)) 
                                                    | (IData)(vlTOPp->top__DOT__RXbuffer)))))
                              : ((4U & (IData)(vlTOPp->top__DOT__busState))
                                  ? ((2U & (IData)(vlTOPp->top__DOT__busState))
                                      ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                          ? (IData)(vlTOPp->top__DOT__clkOut)
                                          : 4U) : (
                                                   (1U 
                                                    & (IData)(vlTOPp->top__DOT__busState))
                                                    ? (IData)(vlTOPp->top__DOT__apuOut)
                                                    : (IData)(vlTOPp->top__DOT__gpuOut)))
                                  : ((2U & (IData)(vlTOPp->top__DOT__busState))
                                      ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                          ? (IData)(vlTOPp->top__DOT__romOut)
                                          : (IData)(vlTOPp->top__DOT__ramOut))
                                      : ((1U & (IData)(vlTOPp->top__DOT__busState))
                                          ? (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)
                                          : 0U))));
    vlTOPp->top__DOT__ALU__DOT__combOperand2 = ((IData)(vlTOPp->top__DOT__aluReadBus)
                                                 ? (IData)(vlTOPp->top__DOT__bus)
                                                 : (IData)(vlTOPp->top__DOT__ALU__DOT__operand2));
    vlTOPp->top__DOT__ALU__DOT__mult = (0x1ffffU & 
                                        ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                         * (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2)));
    vlTOPp->top__DOT__ALU__DOT__log = (0xffffU & ((1U 
                                                   & (((IData)(vlTOPp->top__DOT__aluParams) 
                                                       >> 1U) 
                                                      & (IData)(vlTOPp->top__DOT__aluParams)))
                                                   ? 
                                                  (~ (IData)(vlTOPp->top__DOT__ALU__DOT__operand1))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->top__DOT__aluParams))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                    ^ (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__aluParams))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                     | (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                     & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))))));
    vlTOPp->top__DOT__ALU__DOT__addsub = (0x1ffffU 
                                          & ((1U & (IData)(vlTOPp->top__DOT__aluParams))
                                              ? ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                 - (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                              : ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                 + (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))));
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[6U] = 1U;
    vlTOPp->__Vm_traceActivity[5U] = 1U;
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock 
        = vlTOPp->__VinpClk__TOP__top__DOT__testClock;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[6U] = 1U;
    vlTOPp->__Vm_traceActivity[5U] = 1U;
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    RX = VL_RAND_RESET_I(1);
    TX = VL_RAND_RESET_I(1);
    GPIO3 = VL_RAND_RESET_I(1);
    GPIO9 = VL_RAND_RESET_I(1);
    GPIO11 = VL_RAND_RESET_I(1);
    top__DOT__RXbuffer = VL_RAND_RESET_I(8);
    top__DOT__TXbuffer = VL_RAND_RESET_I(8);
    top__DOT__TXstart = VL_RAND_RESET_I(1);
    top__DOT__RXready = VL_RAND_RESET_I(1);
    top__DOT__testWord = VL_RAND_RESET_I(32);
    top__DOT__testClock = VL_RAND_RESET_I(1);
    top__DOT__busState = VL_RAND_RESET_I(4);
    top__DOT__aluOperand1 = VL_RAND_RESET_I(3);
    top__DOT__aluOperand2 = VL_RAND_RESET_I(3);
    top__DOT__aluResults = VL_RAND_RESET_I(3);
    top__DOT__aluOperation = VL_RAND_RESET_I(6);
    top__DOT__aluParams = VL_RAND_RESET_I(4);
    top__DOT__aluReadBus = VL_RAND_RESET_I(1);
    top__DOT__hreg = VL_RAND_RESET_I(16);
    top__DOT__romAddress = VL_RAND_RESET_I(16);
    top__DOT__ramOut = VL_RAND_RESET_I(16);
    top__DOT__romOut = VL_RAND_RESET_I(16);
    top__DOT__gpuOut = VL_RAND_RESET_I(16);
    top__DOT__apuOut = VL_RAND_RESET_I(16);
    top__DOT__clkOut = VL_RAND_RESET_I(16);
    top__DOT__bus = VL_RAND_RESET_I(16);
    top__DOT__din = VL_RAND_RESET_I(16);
    top__DOT__dout = VL_RAND_RESET_I(16);
    top__DOT__overflow = VL_RAND_RESET_I(1);
    top__DOT__testState = VL_RAND_RESET_I(4);
    top__DOT__clkdiv = VL_RAND_RESET_I(25);
    top__DOT__FTDI__DOT__baudAcc = VL_RAND_RESET_I(3);
    top__DOT__FTDI__DOT__baudTick = VL_RAND_RESET_I(1);
    top__DOT__FTDI__DOT__TXstate = VL_RAND_RESET_I(4);
    top__DOT__FTDI__DOT__TXready = VL_RAND_RESET_I(1);
    top__DOT__FTDI__DOT__TXshift = VL_RAND_RESET_I(8);
    top__DOT__FTDI__DOT__RXstate = VL_RAND_RESET_I(4);
    top__DOT__FTDI__DOT__gap = VL_RAND_RESET_I(3);
    top__DOT__FTDI__DOT__nextBit = VL_RAND_RESET_I(1);
    top__DOT__CONTROL__DOT__increment = VL_RAND_RESET_I(1);
    top__DOT__CONTROL__DOT__programCounter = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__a = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__b = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__c = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__d = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__e = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__f = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__g = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__h = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__addsub = VL_RAND_RESET_I(17);
    top__DOT__ALU__DOT__mult = VL_RAND_RESET_I(17);
    top__DOT__ALU__DOT__log = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__lshift = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__rshift = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__operand1 = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__operand2 = VL_RAND_RESET_I(16);
    top__DOT__ALU__DOT__combOperand2 = VL_RAND_RESET_I(16);
    __VinpClk__TOP__top__DOT__testClock = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__testClock = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<7; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
