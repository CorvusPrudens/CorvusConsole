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
    vlTOPp->top__DOT__a = 0U;
    vlTOPp->top__DOT__b = 0x1000U;
    vlTOPp->top__DOT__TXbuffer = 0U;
    vlTOPp->top__DOT__TXstart = 0U;
    vlTOPp->top__DOT__clkdiv = 0U;
    vlTOPp->top__DOT__FTDI__DOT__baudAcc = 0U;
    vlTOPp->top__DOT__FTDI__DOT__TXshift = 0U;
    vlTOPp->top__DOT__testState = 0U;
    vlTOPp->top__DOT__RXready = 0U;
    vlTOPp->top__DOT__overflow = 0U;
    vlTOPp->top__DOT__FTDI__DOT__TXstate = 0U;
    vlTOPp->top__DOT__res = 0U;
    vlTOPp->top__DOT__RXbuffer = 0U;
    vlTOPp->top__DOT__FTDI__DOT__RXstate = 0U;
    vlTOPp->top__DOT__FTDI__DOT__gap = 0U;
    vlTOPp->top__DOT__op = 2U;
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ALU__DOT__mult = (0x1ffffU & 
                                        ((IData)(vlTOPp->top__DOT__a) 
                                         * (IData)(vlTOPp->top__DOT__b)));
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
    vlTOPp->top__DOT__FTDI__DOT__baudTick = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                                   >> 2U));
    vlTOPp->top__DOT__FTDI__DOT__TXready = (0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate));
    vlTOPp->TX = (1U & ((4U > (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate)) 
                        | (((IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate) 
                            >> 3U) & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXshift))));
    vlTOPp->GPIO0 = (1U & (IData)(vlTOPp->top__DOT__res));
    vlTOPp->GPIO1 = (1U & ((IData)(vlTOPp->top__DOT__res) 
                           >> 1U));
    vlTOPp->GPIO2 = (1U & ((IData)(vlTOPp->top__DOT__res) 
                           >> 2U));
    vlTOPp->top__DOT__FTDI__DOT__nextBit = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                                  >> 2U));
    vlTOPp->top__DOT__ALU__DOT__addsub = (0x1ffffU 
                                          & ((1U & (IData)(vlTOPp->top__DOT__op))
                                              ? ((IData)(vlTOPp->top__DOT__a) 
                                                 - (IData)(vlTOPp->top__DOT__b))
                                              : ((IData)(vlTOPp->top__DOT__a) 
                                                 + (IData)(vlTOPp->top__DOT__b))));
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
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
    GPIO0 = VL_RAND_RESET_I(1);
    GPIO1 = VL_RAND_RESET_I(1);
    GPIO2 = VL_RAND_RESET_I(1);
    GPIO3 = VL_RAND_RESET_I(1);
    GPIO9 = VL_RAND_RESET_I(1);
    GPIO11 = VL_RAND_RESET_I(1);
    top__DOT__RXbuffer = VL_RAND_RESET_I(8);
    top__DOT__TXbuffer = VL_RAND_RESET_I(8);
    top__DOT__TXstart = VL_RAND_RESET_I(1);
    top__DOT__RXready = VL_RAND_RESET_I(1);
    top__DOT__a = VL_RAND_RESET_I(16);
    top__DOT__b = VL_RAND_RESET_I(16);
    top__DOT__op = VL_RAND_RESET_I(2);
    top__DOT__res = VL_RAND_RESET_I(16);
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
    top__DOT__ALU__DOT__addsub = VL_RAND_RESET_I(17);
    top__DOT__ALU__DOT__mult = VL_RAND_RESET_I(17);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
