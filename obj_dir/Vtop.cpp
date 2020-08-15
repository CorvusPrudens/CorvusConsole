// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog/top.v", 9, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog/top.v", 9, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__top__DOT__testState = vlTOPp->top__DOT__testState;
    vlTOPp->top__DOT__clkdiv = (0x1ffffffU & ((IData)(1U) 
                                              + vlTOPp->top__DOT__clkdiv));
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__top__DOT__FTDI__DOT__TXshift;
    CData/*3:0*/ __Vdly__top__DOT__FTDI__DOT__TXstate;
    CData/*3:0*/ __Vdly__top__DOT__FTDI__DOT__RXstate;
    CData/*0:0*/ __Vdly__top__DOT__overflow;
    // Body
    __Vdly__top__DOT__FTDI__DOT__RXstate = vlTOPp->top__DOT__FTDI__DOT__RXstate;
    __Vdly__top__DOT__overflow = vlTOPp->top__DOT__overflow;
    __Vdly__top__DOT__FTDI__DOT__TXshift = vlTOPp->top__DOT__FTDI__DOT__TXshift;
    __Vdly__top__DOT__FTDI__DOT__TXstate = vlTOPp->top__DOT__FTDI__DOT__TXstate;
    if ((8U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
        if ((4U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
            if ((2U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 1U;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 0xfU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 0xeU;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 0xdU;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 0xcU;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 0xbU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 0xaU;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 9U;
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
            __Vdly__top__DOT__FTDI__DOT__RXstate = 0U;
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                __Vdly__top__DOT__FTDI__DOT__RXstate = 0U;
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__nextBit) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 0U;
                    }
                } else {
                    if ((1U & (~ (IData)(vlTOPp->RX)))) {
                        __Vdly__top__DOT__FTDI__DOT__RXstate = 8U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__FTDI__DOT__gap = ((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate))
                                         ? 0U : (7U 
                                                 & ((IData)(1U) 
                                                    + 
                                                    (3U 
                                                     & (IData)(vlTOPp->top__DOT__FTDI__DOT__gap)))));
    if (((IData)(vlTOPp->top__DOT__FTDI__DOT__nextBit) 
         & ((IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate) 
            >> 3U))) {
        vlTOPp->top__DOT__RXbuffer = (((IData)(vlTOPp->RX) 
                                       << 7U) | (0x7fU 
                                                 & ((IData)(vlTOPp->top__DOT__RXbuffer) 
                                                    >> 1U)));
    }
    vlTOPp->top__DOT__RXready = ((IData)(vlTOPp->top__DOT__FTDI__DOT__nextBit) 
                                 & (1U == (IData)(vlTOPp->top__DOT__FTDI__DOT__RXstate)));
    if ((0x20U & (IData)(vlTOPp->top__DOT__op))) {
        if ((1U & (IData)(vlTOPp->top__DOT__op))) {
            __Vdly__top__DOT__overflow = (1U & ((IData)(vlTOPp->top__DOT__overflow) 
                                                | (vlTOPp->top__DOT__ALU__DOT__addsub 
                                                   >> 0x10U)));
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__op))) {
                __Vdly__top__DOT__overflow = (1U & 
                                              ((IData)(vlTOPp->top__DOT__overflow) 
                                               | (vlTOPp->top__DOT__ALU__DOT__mult 
                                                  >> 0x10U)));
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__FTDI__DOT__TXready) 
         & (IData)(vlTOPp->top__DOT__TXstart))) {
        __Vdly__top__DOT__FTDI__DOT__TXshift = vlTOPp->top__DOT__TXbuffer;
    } else {
        if ((((IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate) 
              >> 3U) & (IData)(vlTOPp->top__DOT__FTDI__DOT__baudTick))) {
            __Vdly__top__DOT__FTDI__DOT__TXshift = 
                (0xffU & ((IData)(vlTOPp->top__DOT__FTDI__DOT__TXshift) 
                          >> 1U));
        }
    }
    vlTOPp->top__DOT__FTDI__DOT__baudAcc = ((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))
                                             ? 0U : 
                                            (7U & ((IData)(1U) 
                                                   + 
                                                   (3U 
                                                    & (IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc)))));
    if ((8U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
        if ((4U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
            if ((2U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 1U;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0xfU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0xeU;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0xdU;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0xcU;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0xbU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0xaU;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 9U;
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
            if ((2U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                    __Vdly__top__DOT__FTDI__DOT__TXstate = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0U;
                    }
                } else {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 8U;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                    __Vdly__top__DOT__FTDI__DOT__TXstate = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__FTDI__DOT__baudTick) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 0U;
                    }
                } else {
                    if (vlTOPp->top__DOT__TXstart) {
                        __Vdly__top__DOT__FTDI__DOT__TXstate = 4U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__FTDI__DOT__RXstate = __Vdly__top__DOT__FTDI__DOT__RXstate;
    vlTOPp->top__DOT__overflow = __Vdly__top__DOT__overflow;
    vlTOPp->top__DOT__FTDI__DOT__TXshift = __Vdly__top__DOT__FTDI__DOT__TXshift;
    vlTOPp->top__DOT__FTDI__DOT__TXstate = __Vdly__top__DOT__FTDI__DOT__TXstate;
    vlTOPp->top__DOT__FTDI__DOT__nextBit = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                                  >> 2U));
    vlTOPp->top__DOT__FTDI__DOT__baudTick = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                                   >> 2U));
    vlTOPp->top__DOT__FTDI__DOT__TXready = (0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate));
    vlTOPp->TX = (1U & ((4U > (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate)) 
                        | (((IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate) 
                            >> 3U) & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXshift))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 = vlTOPp->top__DOT__ALU__DOT__r0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x20U & (IData)(vlTOPp->top__DOT__op))) {
        if ((1U & (IData)(vlTOPp->top__DOT__op))) {
            vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 
                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__op))) {
                vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 
                    = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__op))) {
                    vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 
                        = vlTOPp->top__DOT__ALU__DOT__log;
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__op))) {
                        vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 
                            = vlTOPp->top__DOT__ALU__DOT__lshift;
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__op))) {
                            vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 
                                = vlTOPp->top__DOT__ALU__DOT__rshift;
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((8U & (IData)(vlTOPp->top__DOT__testState))) {
        if ((4U & (IData)(vlTOPp->top__DOT__testState))) {
            vlTOPp->top__DOT__TXstart = 0U;
            vlTOPp->__Vdly__top__DOT__testState = 0U;
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__testState))) {
                vlTOPp->top__DOT__TXstart = 0U;
                vlTOPp->__Vdly__top__DOT__testState = 0U;
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    vlTOPp->top__DOT__TXstart = 0U;
                    vlTOPp->__Vdly__top__DOT__testState = 0U;
                } else {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__params = 
                            (0xfU & (IData)(vlTOPp->top__DOT__RXbuffer));
                        vlTOPp->__Vdly__top__DOT__testState = 1U;
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__testState))) {
            if ((2U & (IData)(vlTOPp->top__DOT__testState))) {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    vlTOPp->top__DOT__TXstart = 0U;
                    if ((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                        vlTOPp->top__DOT__TXbuffer 
                            = vlTOPp->top__DOT__overflow;
                        vlTOPp->top__DOT__TXstart = 1U;
                        vlTOPp->__Vdly__top__DOT__testState = 0U;
                    }
                } else {
                    vlTOPp->top__DOT__TXstart = 0U;
                    if ((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                        vlTOPp->top__DOT__TXbuffer 
                            = (0xffU & ((IData)(vlTOPp->top__DOT__ALU__DOT__r0) 
                                        >> 8U));
                        vlTOPp->top__DOT__TXstart = 1U;
                        vlTOPp->__Vdly__top__DOT__testState = 7U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    if ((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                        vlTOPp->top__DOT__op = (0x1fU 
                                                & (IData)(vlTOPp->top__DOT__op));
                        vlTOPp->top__DOT__TXbuffer 
                            = (0xffU & (IData)(vlTOPp->top__DOT__ALU__DOT__r0));
                        vlTOPp->top__DOT__TXstart = 1U;
                        vlTOPp->__Vdly__top__DOT__testState = 6U;
                    }
                } else {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__ALU__DOT__r1 
                            = ((0xffU & (IData)(vlTOPp->top__DOT__ALU__DOT__r1)) 
                               | ((IData)(vlTOPp->top__DOT__RXbuffer) 
                                  << 8U));
                        vlTOPp->__Vdly__top__DOT__testState = 5U;
                        vlTOPp->top__DOT__op = (0x20U 
                                                | (IData)(vlTOPp->top__DOT__op));
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__testState))) {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__ALU__DOT__r1 
                            = ((0xff00U & (IData)(vlTOPp->top__DOT__ALU__DOT__r1)) 
                               | (IData)(vlTOPp->top__DOT__RXbuffer));
                        vlTOPp->__Vdly__top__DOT__testState = 4U;
                    }
                } else {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 
                            = ((0xffU & (IData)(vlTOPp->__Vdly__top__DOT__ALU__DOT__r0)) 
                               | ((IData)(vlTOPp->top__DOT__RXbuffer) 
                                  << 8U));
                        vlTOPp->__Vdly__top__DOT__testState = 3U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->__Vdly__top__DOT__ALU__DOT__r0 
                            = ((0xff00U & (IData)(vlTOPp->__Vdly__top__DOT__ALU__DOT__r0)) 
                               | (IData)(vlTOPp->top__DOT__RXbuffer));
                        vlTOPp->__Vdly__top__DOT__testState = 2U;
                    }
                } else {
                    vlTOPp->top__DOT__TXstart = 0U;
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__op = (0x3fU 
                                                & (IData)(vlTOPp->top__DOT__RXbuffer));
                        vlTOPp->__Vdly__top__DOT__testState = 8U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__testState = vlTOPp->__Vdly__top__DOT__testState;
    vlTOPp->top__DOT__ALU__DOT__b = vlTOPp->top__DOT__ALU__DOT__r1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ALU__DOT__r0 = vlTOPp->__Vdly__top__DOT__ALU__DOT__r0;
    vlTOPp->top__DOT__ALU__DOT__a = vlTOPp->top__DOT__ALU__DOT__r0;
    if ((8U & (IData)(vlTOPp->top__DOT__params))) {
        vlTOPp->top__DOT__ALU__DOT__lshift = ((4U & (IData)(vlTOPp->top__DOT__params))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0x8000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 0xfU))
                                                    : 
                                                   (0xc000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 0xeU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0xe000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 0xdU))
                                                    : 
                                                   (0xf000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0xf800U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 0xbU))
                                                    : 
                                                   (0xfc00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 0xaU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0xfe00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 9U))
                                                    : 
                                                   (0xff00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 8U)))));
        vlTOPp->top__DOT__ALU__DOT__rshift = ((4U & (IData)(vlTOPp->top__DOT__params))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (1U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 0xfU))
                                                    : 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 0xeU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 0xdU))
                                                    : 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0x1fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 0xbU))
                                                    : 
                                                   (0x3fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 0xaU)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0x7fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 9U))
                                                    : 
                                                   (0xffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 8U)))));
    } else {
        vlTOPp->top__DOT__ALU__DOT__lshift = ((4U & (IData)(vlTOPp->top__DOT__params))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0xff80U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 7U))
                                                    : 
                                                   (0xffc0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 6U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0xffe0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 5U))
                                                    : 
                                                   (0xfff0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0xfff8U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 3U))
                                                    : 
                                                   (0xfffcU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 2U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0xfffeU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       << 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__a))));
        vlTOPp->top__DOT__ALU__DOT__rshift = ((4U & (IData)(vlTOPp->top__DOT__params))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0x1ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 7U))
                                                    : 
                                                   (0x3ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 6U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0x7ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 5U))
                                                    : 
                                                   (0xfffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__params))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0x1fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 3U))
                                                    : 
                                                   (0x3fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 2U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   (0x7fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                       >> 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__a))));
    }
    vlTOPp->top__DOT__ALU__DOT__mult = (0x1ffffU & 
                                        ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                         * (IData)(vlTOPp->top__DOT__ALU__DOT__b)));
    vlTOPp->top__DOT__ALU__DOT__log = (0xffffU & ((1U 
                                                   & (((IData)(vlTOPp->top__DOT__params) 
                                                       >> 1U) 
                                                      & (IData)(vlTOPp->top__DOT__params)))
                                                   ? 
                                                  (~ (IData)(vlTOPp->top__DOT__ALU__DOT__a))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->top__DOT__params))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                    ^ (IData)(vlTOPp->top__DOT__ALU__DOT__b))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__params))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                     | (IData)(vlTOPp->top__DOT__ALU__DOT__b))
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                     & (IData)(vlTOPp->top__DOT__ALU__DOT__b))))));
    vlTOPp->top__DOT__ALU__DOT__addsub = (0x1ffffU 
                                          & ((1U & (IData)(vlTOPp->top__DOT__params))
                                              ? ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                 - (IData)(vlTOPp->top__DOT__ALU__DOT__b))
                                              : ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                 + (IData)(vlTOPp->top__DOT__ALU__DOT__b))));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->CLK) ^ (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->CLK) ^ (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((RX & 0xfeU))) {
        Verilated::overWidthError("RX");}
}
#endif  // VL_DEBUG
