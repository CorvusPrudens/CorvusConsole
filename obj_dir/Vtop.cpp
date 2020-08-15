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
    // Variables
    IData/*24:0*/ __Vdly__top__DOT__clkdiv;
    // Body
    __Vdly__top__DOT__clkdiv = vlTOPp->top__DOT__clkdiv;
    vlTOPp->top__DOT__overflow = (1U & (vlTOPp->top__DOT__ALU__DOT__addsub 
                                        >> 0x10U));
    if ((4U & (IData)(vlTOPp->top__DOT__y))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->top__DOT__y))) {
                vlTOPp->top__DOT__ALU__DOT__r5 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    if ((4U & (IData)(vlTOPp->top__DOT__y))) {
        if ((2U & (IData)(vlTOPp->top__DOT__y))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__y)))) {
                vlTOPp->top__DOT__ALU__DOT__r6 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) >> 2U)))) {
        if ((2U & (IData)(vlTOPp->top__DOT__y))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__y)))) {
                vlTOPp->top__DOT__ALU__DOT__r2 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    if ((4U & (IData)(vlTOPp->top__DOT__y))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__y)))) {
                vlTOPp->top__DOT__ALU__DOT__r4 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    if ((4U & (IData)(vlTOPp->top__DOT__y))) {
        if ((2U & (IData)(vlTOPp->top__DOT__y))) {
            if ((1U & (IData)(vlTOPp->top__DOT__y))) {
                vlTOPp->top__DOT__ALU__DOT__r7 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) >> 2U)))) {
        if ((2U & (IData)(vlTOPp->top__DOT__y))) {
            if ((1U & (IData)(vlTOPp->top__DOT__y))) {
                vlTOPp->top__DOT__ALU__DOT__r3 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__y)))) {
                vlTOPp->top__DOT__ALU__DOT__r0 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__y) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->top__DOT__y))) {
                vlTOPp->top__DOT__ALU__DOT__r1 = (0xffffU 
                                                  & vlTOPp->top__DOT__ALU__DOT__addsub);
            }
        }
    }
    __Vdly__top__DOT__clkdiv = (0x1ffffffU & ((IData)(1U) 
                                              + vlTOPp->top__DOT__clkdiv));
    if ((0xfU == (0xfU & vlTOPp->top__DOT__clkdiv))) {
        vlTOPp->top__DOT__a = (7U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__a)));
        vlTOPp->top__DOT__y = (7U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__y)));
    }
    vlTOPp->top__DOT__clkdiv = __Vdly__top__DOT__clkdiv;
    vlTOPp->top__DOT__ALU__DOT__b = vlTOPp->top__DOT__ALU__DOT__r1;
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
    vlTOPp->top__DOT__ALU__DOT__a = ((4U & (IData)(vlTOPp->top__DOT__a))
                                      ? ((2U & (IData)(vlTOPp->top__DOT__a))
                                          ? ((1U & (IData)(vlTOPp->top__DOT__a))
                                              ? (IData)(vlTOPp->top__DOT__ALU__DOT__r7)
                                              : (IData)(vlTOPp->top__DOT__ALU__DOT__r6))
                                          : ((1U & (IData)(vlTOPp->top__DOT__a))
                                              ? (IData)(vlTOPp->top__DOT__ALU__DOT__r5)
                                              : (IData)(vlTOPp->top__DOT__ALU__DOT__r4)))
                                      : ((2U & (IData)(vlTOPp->top__DOT__a))
                                          ? ((1U & (IData)(vlTOPp->top__DOT__a))
                                              ? (IData)(vlTOPp->top__DOT__ALU__DOT__r3)
                                              : (IData)(vlTOPp->top__DOT__ALU__DOT__r2))
                                          : ((1U & (IData)(vlTOPp->top__DOT__a))
                                              ? (IData)(vlTOPp->top__DOT__ALU__DOT__r1)
                                              : (IData)(vlTOPp->top__DOT__ALU__DOT__r0))));
    vlTOPp->top__DOT__ALU__DOT__addsub = (0x1ffffU 
                                          & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                             + (IData)(vlTOPp->top__DOT__ALU__DOT__b)));
    vlTOPp->top__DOT__ALU__DOT__mult = (0x1ffffU & 
                                        ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                         * (IData)(vlTOPp->top__DOT__ALU__DOT__b)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__top__DOT__FTDI__DOT__TXstate;
    CData/*3:0*/ __Vdly__top__DOT__FTDI__DOT__RXstate;
    // Body
    __Vdly__top__DOT__FTDI__DOT__RXstate = vlTOPp->top__DOT__FTDI__DOT__RXstate;
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
    if ((((IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate) 
          >> 3U) & (IData)(vlTOPp->top__DOT__FTDI__DOT__baudTick))) {
        vlTOPp->top__DOT__FTDI__DOT__TXshift = (0xffU 
                                                & ((IData)(vlTOPp->top__DOT__FTDI__DOT__TXshift) 
                                                   >> 1U));
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
                }
            }
        }
    }
    vlTOPp->top__DOT__FTDI__DOT__RXstate = __Vdly__top__DOT__FTDI__DOT__RXstate;
    vlTOPp->top__DOT__FTDI__DOT__TXstate = __Vdly__top__DOT__FTDI__DOT__TXstate;
    vlTOPp->top__DOT__FTDI__DOT__nextBit = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
                                                  >> 2U));
    vlTOPp->top__DOT__FTDI__DOT__baudTick = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                                   >> 2U));
    vlTOPp->TX = (1U & ((4U > (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate)) 
                        | (((IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate) 
                            >> 3U) & (IData)(vlTOPp->top__DOT__FTDI__DOT__TXshift))));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
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
