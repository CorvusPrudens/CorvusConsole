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
    vlTOPp->CE = 1U;
    vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 0U;
    vlTOPp->top__DOT__aluParams = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand2 = 0U;
    vlTOPp->top__DOT__aluOperand2 = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__ramAddReg = 0x400U;
    vlTOPp->top__DOT__ramWrite = 0U;
    vlTOPp->top__DOT__busState = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand1 = 0U;
    vlTOPp->top__DOT__aluOperand1 = 0U;
    vlTOPp->top__DOT__ALU__DOT__a = 2U;
    vlTOPp->top__DOT__ALU__DOT__b = 0U;
    vlTOPp->top__DOT__ALU__DOT__c = 0U;
    vlTOPp->top__DOT__ALU__DOT__d = 0U;
    vlTOPp->top__DOT__ALU__DOT__e = 0U;
    vlTOPp->top__DOT__ALU__DOT__f = 0U;
    vlTOPp->top__DOT__ALU__DOT__g = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__increment = 0U;
    vlTOPp->top__DOT__overflow = 0U;
    vlTOPp->top__DOT__UART__DOT__TXstart = 0U;
    vlTOPp->top__DOT__UART__DOT__uartoutwrite = 0U;
    vlTOPp->top__DOT__MEMbus = 0U;
    vlTOPp->top__DOT__clkdiv = 0U;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc = 0U;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__programCounter = 0U;
    vlTOPp->top__DOT__ALU__DOT__h = 0U;
    vlTOPp->top__DOT__aluResults = 0U;
    vlTOPp->top__DOT__aluOperation = 0U;
    vlTOPp->top__DOT__UART__DOT__sendRead = 0U;
    vlTOPp->top__DOT__UART__DOT__uartout = 0U;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate = 0U;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__gap = 0U;
    vlTOPp->top__DOT__aluReadBus = 0U;
    vlTOPp->top__DOT__bus = 0U;
    vlTOPp->top__DOT__UART__DOT__sendState = 0U;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate = 0U;
    vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern = 0U;
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__UART__DOT__empty = ((IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0) 
                                          == (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn));
    vlTOPp->A0 = (1U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg));
    vlTOPp->A1 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 1U));
    vlTOPp->A2 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 2U));
    vlTOPp->A3 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 3U));
    vlTOPp->A4 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 4U));
    vlTOPp->A5 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 5U));
    vlTOPp->A6 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 6U));
    vlTOPp->A7 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 7U));
    vlTOPp->A8 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 8U));
    vlTOPp->A9 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                        >> 9U));
    vlTOPp->A10 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                         >> 0xaU));
    vlTOPp->A11 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                         >> 0xbU));
    vlTOPp->A12 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                         >> 0xcU));
    vlTOPp->A13 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                         >> 0xdU));
    vlTOPp->A14 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                         >> 0xeU));
    vlTOPp->A15 = (1U & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg) 
                         >> 0xfU));
    vlTOPp->top__DOT____Vcellinp__UART__write = ((IData)(vlTOPp->top__DOT__ramWrite) 
                                                 & (3U 
                                                    == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)));
    vlTOPp->OE = ((IData)(vlTOPp->top__DOT__ramWrite) 
                  & (~ (IData)(vlTOPp->CLK)));
    vlTOPp->WR = (1U & (~ ((IData)(vlTOPp->top__DOT__ramWrite) 
                           & (~ (IData)(vlTOPp->CLK)))));
    vlTOPp->top__DOT__MEMstate = (((IData)(vlTOPp->top__DOT__ramWrite) 
                                   << 6U) | (((5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                              << 5U) 
                                             | (((4U 
                                                  == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                                 << 4U) 
                                                | (((3U 
                                                     == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                                    << 3U) 
                                                   | (((2U 
                                                        == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                                       << 2U) 
                                                      | (((1U 
                                                           == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                                          << 1U) 
                                                         | (0U 
                                                            == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))))))));
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
    vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick 
        = (1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc) 
                 >> 2U));
    vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
        = (((((((((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)) 
                  | (1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))) 
                 | (2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))) 
                | (3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))) 
               | (4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))) 
              | (5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))) 
             | (6U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))) 
            | (7U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)))
            ? ((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                ? 0x10006U : ((1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                               ? 0x2006U : ((2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                             ? 0x4006U
                                             : ((3U 
                                                 == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                 ? 0x401aU
                                                 : 
                                                ((4U 
                                                  == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                  ? 0x418U
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                   ? 0x211aU
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                    ? 0x30008U
                                                    : 0x86042U)))))))
            : ((8U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                ? 0x30188U : ((9U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                               ? 0x30050U : 0U)));
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
    vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit 
        = (1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__gap) 
                 >> 2U));
    vlTOPp->top__DOT__UART__DOT__UART__DOT__TXready 
        = (0U == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate));
    vlTOPp->TX = (1U & ((4U > (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate)) 
                        | (((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate) 
                            >> 3U) & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift))));
    vlTOPp->top__DOT__UART__DOT____Vcellinp__OUTFIFO__read 
        = ((3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
           & (~ (IData)(vlTOPp->top__DOT__UART__DOT__empty)));
    vlTOPp->UB = vlTOPp->WR;
    vlTOPp->LB = vlTOPp->WR;
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
                              ? 0U : (0xffffU & ((4U 
                                                  & (IData)(vlTOPp->top__DOT__busState))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__busState))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__busState))
                                                    ? (IData)(vlTOPp->top__DOT__clkOut)
                                                    : 
                                                   (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 0x10U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__busState))
                                                    ? (IData)(vlTOPp->top__DOT__apuOut)
                                                    : (IData)(vlTOPp->top__DOT__gpuOut)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__busState))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__busState))
                                                    ? (IData)(vlTOPp->top__DOT__romOut)
                                                    : 
                                                   (((IData)(vlTOPp->D15_in) 
                                                     << 0xfU) 
                                                    | (((IData)(vlTOPp->D14_in) 
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
                                                                                | (IData)(vlTOPp->D0_in)))))))))))))))))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__busState))
                                                    ? (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)
                                                    : 0U)))));
    vlTOPp->D12 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xcU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D10 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xaU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D11 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xbU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D13 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xdU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D14 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xeU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D15 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xfU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D8 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 8U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D7 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 7U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D9 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 9U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D0 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & (IData)(vlTOPp->top__DOT__bus)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D1 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 1U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D2 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 2U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D3 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 3U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D6 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 6U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D5 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 5U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D4 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 4U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->top__DOT__MEMbus = ((0x40U & (IData)(vlTOPp->top__DOT__MEMstate))
                                 ? (IData)(vlTOPp->top__DOT__bus)
                                 : ((0x20U & (IData)(vlTOPp->top__DOT__MEMstate))
                                     ? ((0x10U & (IData)(vlTOPp->top__DOT__MEMstate))
                                         ? (IData)(vlTOPp->top__DOT__bus)
                                         : ((8U & (IData)(vlTOPp->top__DOT__MEMstate))
                                             ? (IData)(vlTOPp->top__DOT__bus)
                                             : ((4U 
                                                 & (IData)(vlTOPp->top__DOT__MEMstate))
                                                 ? (IData)(vlTOPp->top__DOT__bus)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__MEMstate))
                                                  ? (IData)(vlTOPp->top__DOT__bus)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__MEMstate))
                                                   ? (IData)(vlTOPp->top__DOT__bus)
                                                   : (IData)(vlTOPp->top__DOT__gpiodirOut))))))
                                     : ((0x10U & (IData)(vlTOPp->top__DOT__MEMstate))
                                         ? ((8U & (IData)(vlTOPp->top__DOT__MEMstate))
                                             ? (IData)(vlTOPp->top__DOT__bus)
                                             : ((4U 
                                                 & (IData)(vlTOPp->top__DOT__MEMstate))
                                                 ? (IData)(vlTOPp->top__DOT__bus)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__MEMstate))
                                                  ? (IData)(vlTOPp->top__DOT__bus)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__MEMstate))
                                                   ? (IData)(vlTOPp->top__DOT__bus)
                                                   : (IData)(vlTOPp->top__DOT__gpioOut)))))
                                         : ((8U & (IData)(vlTOPp->top__DOT__MEMstate))
                                             ? ((4U 
                                                 & (IData)(vlTOPp->top__DOT__MEMstate))
                                                 ? (IData)(vlTOPp->top__DOT__bus)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__MEMstate))
                                                  ? (IData)(vlTOPp->top__DOT__bus)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__MEMstate))
                                                   ? (IData)(vlTOPp->top__DOT__bus)
                                                   : 
                                                  (((IData)(vlTOPp->top__DOT__UART__DOT__empty) 
                                                    << 9U) 
                                                   | (((1U 
                                                        == 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                                            - (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn)))) 
                                                       << 8U) 
                                                      | (IData)(vlTOPp->top__DOT__UART__DOT__dataOutReg))))))
                                             : ((4U 
                                                 & (IData)(vlTOPp->top__DOT__MEMstate))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__MEMstate))
                                                  ? (IData)(vlTOPp->top__DOT__bus)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__MEMstate))
                                                   ? (IData)(vlTOPp->top__DOT__bus)
                                                   : (IData)(vlTOPp->top__DOT__userstackOut)))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__MEMstate))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__MEMstate))
                                                   ? (IData)(vlTOPp->top__DOT__bus)
                                                   : (IData)(vlTOPp->top__DOT__addrstackOut))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__MEMstate))
                                                   ? (IData)(vlTOPp->top__DOT__statusOut)
                                                   : (IData)(vlTOPp->top__DOT__bus))))))));
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
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
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
    CE = VL_RAND_RESET_I(1);
    OE = VL_RAND_RESET_I(1);
    WR = VL_RAND_RESET_I(1);
    UB = VL_RAND_RESET_I(1);
    LB = VL_RAND_RESET_I(1);
    A0 = VL_RAND_RESET_I(1);
    A1 = VL_RAND_RESET_I(1);
    A2 = VL_RAND_RESET_I(1);
    A3 = VL_RAND_RESET_I(1);
    A4 = VL_RAND_RESET_I(1);
    A5 = VL_RAND_RESET_I(1);
    A6 = VL_RAND_RESET_I(1);
    A7 = VL_RAND_RESET_I(1);
    A8 = VL_RAND_RESET_I(1);
    A9 = VL_RAND_RESET_I(1);
    A10 = VL_RAND_RESET_I(1);
    A11 = VL_RAND_RESET_I(1);
    A12 = VL_RAND_RESET_I(1);
    A13 = VL_RAND_RESET_I(1);
    A14 = VL_RAND_RESET_I(1);
    A15 = VL_RAND_RESET_I(1);
    D0 = VL_RAND_RESET_I(1);
    D1 = VL_RAND_RESET_I(1);
    D2 = VL_RAND_RESET_I(1);
    D3 = VL_RAND_RESET_I(1);
    D4 = VL_RAND_RESET_I(1);
    D5 = VL_RAND_RESET_I(1);
    D6 = VL_RAND_RESET_I(1);
    D7 = VL_RAND_RESET_I(1);
    D8 = VL_RAND_RESET_I(1);
    D9 = VL_RAND_RESET_I(1);
    D10 = VL_RAND_RESET_I(1);
    D11 = VL_RAND_RESET_I(1);
    D12 = VL_RAND_RESET_I(1);
    D13 = VL_RAND_RESET_I(1);
    D14 = VL_RAND_RESET_I(1);
    D15 = VL_RAND_RESET_I(1);
    D0_in = VL_RAND_RESET_I(1);
    D1_in = VL_RAND_RESET_I(1);
    D2_in = VL_RAND_RESET_I(1);
    D3_in = VL_RAND_RESET_I(1);
    D4_in = VL_RAND_RESET_I(1);
    D5_in = VL_RAND_RESET_I(1);
    D6_in = VL_RAND_RESET_I(1);
    D7_in = VL_RAND_RESET_I(1);
    D8_in = VL_RAND_RESET_I(1);
    D9_in = VL_RAND_RESET_I(1);
    D10_in = VL_RAND_RESET_I(1);
    D11_in = VL_RAND_RESET_I(1);
    D12_in = VL_RAND_RESET_I(1);
    D13_in = VL_RAND_RESET_I(1);
    D14_in = VL_RAND_RESET_I(1);
    D15_in = VL_RAND_RESET_I(1);
    top__DOT__busState = VL_RAND_RESET_I(4);
    top__DOT__aluOperand1 = VL_RAND_RESET_I(3);
    top__DOT__aluOperand2 = VL_RAND_RESET_I(3);
    top__DOT__aluResults = VL_RAND_RESET_I(3);
    top__DOT__aluOperation = VL_RAND_RESET_I(6);
    top__DOT__aluParams = VL_RAND_RESET_I(4);
    top__DOT__aluReadBus = VL_RAND_RESET_I(1);
    top__DOT__ramWrite = VL_RAND_RESET_I(1);
    top__DOT__romOut = VL_RAND_RESET_I(16);
    top__DOT__gpuOut = VL_RAND_RESET_I(16);
    top__DOT__apuOut = VL_RAND_RESET_I(16);
    top__DOT__clkOut = VL_RAND_RESET_I(16);
    top__DOT__bus = VL_RAND_RESET_I(16);
    top__DOT__MEMbus = VL_RAND_RESET_I(16);
    top__DOT__statusOut = VL_RAND_RESET_I(16);
    top__DOT__addrstackOut = VL_RAND_RESET_I(16);
    top__DOT__userstackOut = VL_RAND_RESET_I(16);
    top__DOT__gpioOut = VL_RAND_RESET_I(16);
    top__DOT__gpiodirOut = VL_RAND_RESET_I(16);
    top__DOT__MEMstate = VL_RAND_RESET_I(7);
    top__DOT__din = VL_RAND_RESET_I(16);
    top__DOT__dout = VL_RAND_RESET_I(16);
    top__DOT__overflow = VL_RAND_RESET_I(1);
    top__DOT____Vcellinp__UART__write = VL_RAND_RESET_I(1);
    top__DOT__clkdiv = VL_RAND_RESET_I(25);
    top__DOT__CONTROL__DOT__increment = VL_RAND_RESET_I(2);
    top__DOT__CONTROL__DOT__ramAddMode = VL_RAND_RESET_I(1);
    top__DOT__CONTROL__DOT__ramAddReg = VL_RAND_RESET_I(16);
    top__DOT__CONTROL__DOT__programCounter = VL_RAND_RESET_I(16);
    top__DOT__ROM__DOT__ROMDATA__DOT__dintern = VL_RAND_RESET_I(32);
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
    top__DOT__UART__DOT__dataOutReg = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__uartread = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT__uartin = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__uartout = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__uartoutwrite = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT__empty = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT__sendState = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT__sendRead = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT__TXstart = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT____Vcellinp__OUTFIFO__read = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            top__DOT__UART__DOT__INFIFO__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__UART__DOT__INFIFO__DOT__idx0 = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__INFIFO__DOT__idxn = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__INFIFO__DOT__idx0prev = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__INFIFO__DOT__idxnprev = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__UART__DOT__baudAcc = VL_RAND_RESET_I(3);
    top__DOT__UART__DOT__UART__DOT__baudTick = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT__UART__DOT__TXstate = VL_RAND_RESET_I(4);
    top__DOT__UART__DOT__UART__DOT__TXready = VL_RAND_RESET_I(1);
    top__DOT__UART__DOT__UART__DOT__TXshift = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__UART__DOT__RXstate = VL_RAND_RESET_I(4);
    top__DOT__UART__DOT__UART__DOT__gap = VL_RAND_RESET_I(3);
    top__DOT__UART__DOT__UART__DOT__nextBit = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            top__DOT__UART__DOT__OUTFIFO__DOT__buffer[__Vi0] = VL_RAND_RESET_I(8);
    }}
    top__DOT__UART__DOT__OUTFIFO__DOT__idx0 = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__OUTFIFO__DOT__idxn = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__OUTFIFO__DOT__idx0prev = VL_RAND_RESET_I(8);
    top__DOT__UART__DOT__OUTFIFO__DOT__idxnprev = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
