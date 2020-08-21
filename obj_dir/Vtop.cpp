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
            VL_FATAL_MT("verilog/top.v", 12, "",
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
            VL_FATAL_MT("verilog/top.v", 12, "",
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
    vlTOPp->top__DOT__ramOut = (((IData)(vlTOPp->D15_in) 
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
                                                                                | (IData)(vlTOPp->D0_in))))))))))))))));
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
    // Body
    __Vdly__top__DOT__FTDI__DOT__RXstate = vlTOPp->top__DOT__FTDI__DOT__RXstate;
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
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__overflow;
    // Body
    __Vdly__top__DOT__overflow = vlTOPp->top__DOT__overflow;
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            __Vdly__top__DOT__overflow = (1U & ((IData)(vlTOPp->top__DOT__overflow) 
                                                | (vlTOPp->top__DOT__ALU__DOT__addsub 
                                                   >> 0x10U)));
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                __Vdly__top__DOT__overflow = (1U & 
                                              ((IData)(vlTOPp->top__DOT__overflow) 
                                               | (vlTOPp->top__DOT__ALU__DOT__mult 
                                                  >> 0x10U)));
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                        vlTOPp->top__DOT__ALU__DOT__c 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                            vlTOPp->top__DOT__ALU__DOT__c 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                vlTOPp->top__DOT__ALU__DOT__c 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                    vlTOPp->top__DOT__ALU__DOT__c 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                        vlTOPp->top__DOT__ALU__DOT__c 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                            vlTOPp->top__DOT__ALU__DOT__c 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        vlTOPp->top__DOT__ALU__DOT__d 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            vlTOPp->top__DOT__ALU__DOT__d 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                vlTOPp->top__DOT__ALU__DOT__d 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    vlTOPp->top__DOT__ALU__DOT__d 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        vlTOPp->top__DOT__ALU__DOT__d 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            vlTOPp->top__DOT__ALU__DOT__d 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        vlTOPp->top__DOT__ALU__DOT__b 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            vlTOPp->top__DOT__ALU__DOT__b 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                vlTOPp->top__DOT__ALU__DOT__b 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    vlTOPp->top__DOT__ALU__DOT__b 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        vlTOPp->top__DOT__ALU__DOT__b 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            vlTOPp->top__DOT__ALU__DOT__b 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        vlTOPp->top__DOT__ALU__DOT__h 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            vlTOPp->top__DOT__ALU__DOT__h 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                vlTOPp->top__DOT__ALU__DOT__h 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    vlTOPp->top__DOT__ALU__DOT__h 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        vlTOPp->top__DOT__ALU__DOT__h 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            vlTOPp->top__DOT__ALU__DOT__h 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                        vlTOPp->top__DOT__ALU__DOT__e 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                            vlTOPp->top__DOT__ALU__DOT__e 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                vlTOPp->top__DOT__ALU__DOT__e 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                    vlTOPp->top__DOT__ALU__DOT__e 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                        vlTOPp->top__DOT__ALU__DOT__e 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                            vlTOPp->top__DOT__ALU__DOT__e 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        vlTOPp->top__DOT__ALU__DOT__f 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            vlTOPp->top__DOT__ALU__DOT__f 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                vlTOPp->top__DOT__ALU__DOT__f 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    vlTOPp->top__DOT__ALU__DOT__f 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        vlTOPp->top__DOT__ALU__DOT__f 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            vlTOPp->top__DOT__ALU__DOT__f 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                        vlTOPp->top__DOT__ALU__DOT__g 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                            vlTOPp->top__DOT__ALU__DOT__g 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                vlTOPp->top__DOT__ALU__DOT__g 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                    vlTOPp->top__DOT__ALU__DOT__g 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                        vlTOPp->top__DOT__ALU__DOT__g 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                            vlTOPp->top__DOT__ALU__DOT__g 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->top__DOT__CONTROL__DOT__increment) {
        vlTOPp->top__DOT__CONTROL__DOT__programCounter 
            = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)));
    }
    vlTOPp->top__DOT__overflow = __Vdly__top__DOT__overflow;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x40U & vlTOPp->top__DOT__testWord)) {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            vlTOPp->top__DOT__aluOperation = (0x1fU 
                                              & (IData)(vlTOPp->top__DOT__aluOperation));
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                vlTOPp->top__DOT__aluOperation = (0x1fU 
                                                  & (IData)(vlTOPp->top__DOT__aluOperation));
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__aluOperation 
                        = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x30U;
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                vlTOPp->top__DOT__aluOperation = ((8U 
                                                   & vlTOPp->top__DOT__testWord)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 0x28U
                                                    : 0x24U)
                                                   : 0x24U);
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluOperation = 0x24U;
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x22U;
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__aluOperation = 0x21U;
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluOperation 
                                = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluOperation 
                                = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                        }
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluOperation 
                                = (0x20U | (IData)(vlTOPp->top__DOT__aluOperation));
                        }
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__testWord)) {
        if ((1U & (~ (vlTOPp->top__DOT__testWord >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__testWord 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__testWord 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 0xdU));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                vlTOPp->top__DOT__aluResults = (7U 
                                                & (vlTOPp->top__DOT__testWord 
                                                   >> 0xdU));
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 0xdU));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 0xdU));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__aluResults = 
                        (7U & (vlTOPp->top__DOT__testWord 
                               >> 0xdU));
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluResults 
                                = (7U & (vlTOPp->top__DOT__testWord 
                                         >> 0xdU));
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluResults 
                                = (7U & (vlTOPp->top__DOT__testWord 
                                         >> 0xdU));
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__testWord)) {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
            vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 1U;
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__testWord)) {
        if ((1U & (~ (vlTOPp->top__DOT__testWord >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__testWord 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__testWord 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluParams 
                            = (0xfU & (vlTOPp->top__DOT__testWord 
                                       >> 0x10U));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                vlTOPp->top__DOT__aluParams = (0xfU 
                                               & ((8U 
                                                   & vlTOPp->top__DOT__testWord)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 
                                                   (vlTOPp->top__DOT__testWord 
                                                    >> 0x10U)
                                                    : 3U)
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 2U
                                                    : 1U)));
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluParams = 0U;
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluParams 
                            = (0xeU & (IData)(vlTOPp->top__DOT__aluParams));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__aluParams = (
                                                   (0xeU 
                                                    & (IData)(vlTOPp->top__DOT__aluParams)) 
                                                   | (1U 
                                                      & (vlTOPp->top__DOT__testWord 
                                                         >> 2U)));
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__testWord)) {
        vlTOPp->top__DOT__aluReadBus = (1U & ((~ (vlTOPp->top__DOT__testWord 
                                                  >> 5U)) 
                                              & ((~ 
                                                  (vlTOPp->top__DOT__testWord 
                                                   >> 4U)) 
                                                 & ((~ 
                                                     (vlTOPp->top__DOT__testWord 
                                                      >> 3U)) 
                                                    & (~ 
                                                       (vlTOPp->top__DOT__testWord 
                                                        >> 2U))))));
    } else {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            vlTOPp->top__DOT__aluReadBus = (1U & ((0x10U 
                                                   & vlTOPp->top__DOT__testWord)
                                                   ? 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 
                                                   (vlTOPp->top__DOT__testWord 
                                                    >> 2U)
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__testWord)
                                                     ? 
                                                    (vlTOPp->top__DOT__testWord 
                                                     >> 1U)
                                                     : 
                                                    (vlTOPp->top__DOT__testWord 
                                                     >> 1U)))
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 
                                                   ((vlTOPp->top__DOT__testWord 
                                                     >> 2U) 
                                                    & (vlTOPp->top__DOT__testWord 
                                                       >> 1U))
                                                    : 
                                                   ((~ 
                                                     (vlTOPp->top__DOT__testWord 
                                                      >> 2U)) 
                                                    & (vlTOPp->top__DOT__testWord 
                                                       >> 1U)))));
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__aluReadBus = 
                        (1U & ((4U & vlTOPp->top__DOT__testWord)
                                ? (vlTOPp->top__DOT__testWord 
                                   >> 1U) : (vlTOPp->top__DOT__testWord 
                                             >> 1U)));
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluReadBus = 0U;
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluReadBus = 0U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluReadBus = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__aluReadBus = 0U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluReadBus = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__aluReadBus = 0U;
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->top__DOT__testWord >> 6U)))) {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((1U & (~ (vlTOPp->top__DOT__testWord 
                              >> 3U)))) {
                    vlTOPp->top__DOT__aluOperand2 = 
                        (7U & (vlTOPp->top__DOT__testWord 
                               >> 0xaU));
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluOperand2 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 0xaU));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand2 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 0xaU));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__aluOperand2 = 
                        (7U & (vlTOPp->top__DOT__testWord 
                               >> 0xaU));
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__testWord)) {
        vlTOPp->top__DOT__ramWrite = 0U;
    } else {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            vlTOPp->top__DOT__ramWrite = 0U;
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__ramWrite = 0U;
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__ramWrite = 0U;
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__ramWrite = 1U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__ramWrite = 0U;
                        }
                    } else {
                        vlTOPp->top__DOT__ramWrite = 1U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__ramWrite = 0U;
                        }
                    } else {
                        vlTOPp->top__DOT__ramWrite = 0U;
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->top__DOT__testWord >> 6U)))) {
        if ((1U & (~ (vlTOPp->top__DOT__testWord >> 5U)))) {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((1U & (~ (vlTOPp->top__DOT__testWord 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 1U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 0U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 0U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__busState = ((0x40U & vlTOPp->top__DOT__testWord)
                                   ? ((0x20U & vlTOPp->top__DOT__testWord)
                                       ? 0U : ((0x10U 
                                                & vlTOPp->top__DOT__testWord)
                                                ? 0U
                                                : (
                                                   (8U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__testWord)
                                                     ? 0U
                                                     : 6U))))
                                   : ((0x20U & vlTOPp->top__DOT__testWord)
                                       ? ((0x10U & vlTOPp->top__DOT__testWord)
                                           ? 6U : (
                                                   (8U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__testWord)
                                                     ? 6U
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__testWord)
                                                     ? 0U
                                                     : 6U)))
                                       : ((0x10U & vlTOPp->top__DOT__testWord)
                                           ? ((8U & vlTOPp->top__DOT__testWord)
                                               ? 6U
                                               : ((4U 
                                                   & vlTOPp->top__DOT__testWord)
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 2U
                                                    : 1U)))
                                           : ((8U & vlTOPp->top__DOT__testWord)
                                               ? ((4U 
                                                   & vlTOPp->top__DOT__testWord)
                                                   ? 2U
                                                   : 1U)
                                               : ((4U 
                                                   & vlTOPp->top__DOT__testWord)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->top__DOT__testWord)
                                                    ? 2U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->top__DOT__testWord)
                                                     ? 6U
                                                     : 2U))
                                                   : 0U)))));
    if ((0x40U & vlTOPp->top__DOT__testWord)) {
        if ((1U & (~ (vlTOPp->top__DOT__testWord >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__testWord 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__testWord 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 7U));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__testWord)) {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                vlTOPp->top__DOT__aluOperand1 = (7U 
                                                 & (vlTOPp->top__DOT__testWord 
                                                    >> 7U));
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((4U & vlTOPp->top__DOT__testWord)) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 7U));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 7U));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__testWord)) {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    vlTOPp->top__DOT__aluOperand1 = 
                        (7U & (vlTOPp->top__DOT__testWord 
                               >> 7U));
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        if ((1U & (~ vlTOPp->top__DOT__testWord))) {
                            vlTOPp->top__DOT__aluOperand1 
                                = (7U & (vlTOPp->top__DOT__testWord 
                                         >> 7U));
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__testWord)) {
                    if ((1U & (~ (vlTOPp->top__DOT__testWord 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__testWord 
                                     >> 7U));
                    }
                }
            }
        }
    }
    vlTOPp->OE = vlTOPp->top__DOT__ramWrite;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((8U & (IData)(vlTOPp->top__DOT__testState))) {
        vlTOPp->top__DOT__TXstart = 0U;
        vlTOPp->__Vdly__top__DOT__testState = 0U;
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__testState))) {
            if ((2U & (IData)(vlTOPp->top__DOT__testState))) {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    vlTOPp->top__DOT__TXstart = 0U;
                    vlTOPp->__Vdly__top__DOT__testState = 0U;
                } else {
                    vlTOPp->top__DOT__TXbuffer = (0xffU 
                                                  & (IData)(vlTOPp->top__DOT__ALU__DOT__a));
                    vlTOPp->top__DOT__TXstart = 1U;
                    vlTOPp->__Vdly__top__DOT__testState = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    vlTOPp->top__DOT__testClock = 1U;
                    vlTOPp->__Vdly__top__DOT__testState = 6U;
                } else {
                    vlTOPp->top__DOT__testClock = 0U;
                    vlTOPp->__Vdly__top__DOT__testState = 5U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__testState))) {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__testWord 
                            = ((0xffffffU & vlTOPp->top__DOT__testWord) 
                               | ((IData)(vlTOPp->top__DOT__RXbuffer) 
                                  << 0x18U));
                        vlTOPp->__Vdly__top__DOT__testState = 4U;
                    }
                } else {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__testWord 
                            = ((0xff00ffffU & vlTOPp->top__DOT__testWord) 
                               | ((IData)(vlTOPp->top__DOT__RXbuffer) 
                                  << 0x10U));
                        vlTOPp->__Vdly__top__DOT__testState = 3U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__testState))) {
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__testWord 
                            = ((0xffff00ffU & vlTOPp->top__DOT__testWord) 
                               | ((IData)(vlTOPp->top__DOT__RXbuffer) 
                                  << 8U));
                        vlTOPp->__Vdly__top__DOT__testState = 2U;
                    }
                } else {
                    vlTOPp->top__DOT__TXstart = 0U;
                    if (vlTOPp->top__DOT__RXready) {
                        vlTOPp->top__DOT__testWord 
                            = ((0xffffff00U & vlTOPp->top__DOT__testWord) 
                               | (IData)(vlTOPp->top__DOT__RXbuffer));
                        vlTOPp->__Vdly__top__DOT__testState = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__testState = vlTOPp->__Vdly__top__DOT__testState;
}

VL_INLINE_OPT void Vtop::_combo__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__8\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->WR = (1U & ((~ (IData)(vlTOPp->top__DOT__ramWrite)) 
                        | (~ (IData)(vlTOPp->CLK))));
    vlTOPp->UB = vlTOPp->WR;
    vlTOPp->LB = vlTOPp->WR;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__9\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                        vlTOPp->top__DOT__ALU__DOT__a 
                            = (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                            vlTOPp->top__DOT__ALU__DOT__a 
                                = (0xffffU & vlTOPp->top__DOT__ALU__DOT__mult);
                        }
                    }
                }
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                vlTOPp->top__DOT__ALU__DOT__a 
                                    = vlTOPp->top__DOT__ALU__DOT__log;
                            }
                        }
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                    vlTOPp->top__DOT__ALU__DOT__a 
                                        = vlTOPp->top__DOT__ALU__DOT__lshift;
                                }
                            }
                        }
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                        vlTOPp->top__DOT__ALU__DOT__a 
                                            = vlTOPp->top__DOT__ALU__DOT__rshift;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->top__DOT__aluReadBus) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
                                            vlTOPp->top__DOT__ALU__DOT__a 
                                                = vlTOPp->top__DOT__bus;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__10(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__10\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ramAddress = (0xffffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode)
                                                ? (IData)(vlTOPp->top__DOT__ALU__DOT__g)
                                                : (vlTOPp->top__DOT__testWord 
                                                   >> 0x10U)));
    vlTOPp->A0 = (1U & (IData)(vlTOPp->top__DOT__ramAddress));
    vlTOPp->A1 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 1U));
    vlTOPp->A2 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 2U));
    vlTOPp->A3 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 3U));
    vlTOPp->A4 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 4U));
    vlTOPp->A5 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 5U));
    vlTOPp->A6 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 6U));
    vlTOPp->A7 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 7U));
    vlTOPp->A8 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 8U));
    vlTOPp->A9 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                        >> 9U));
    vlTOPp->A10 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                         >> 0xaU));
    vlTOPp->A11 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                         >> 0xbU));
    vlTOPp->A12 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                         >> 0xcU));
    vlTOPp->A13 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                         >> 0xdU));
    vlTOPp->A14 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                         >> 0xeU));
    vlTOPp->A15 = (1U & ((IData)(vlTOPp->top__DOT__ramAddress) 
                         >> 0xfU));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__11(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__11\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__12(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__12\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
                              : (0xffffU & ((4U & (IData)(vlTOPp->top__DOT__busState))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->top__DOT__busState))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__busState))
                                                  ? (IData)(vlTOPp->top__DOT__clkOut)
                                                  : 
                                                 (vlTOPp->top__DOT__testWord 
                                                  >> 0x10U))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__busState))
                                                  ? (IData)(vlTOPp->top__DOT__apuOut)
                                                  : (IData)(vlTOPp->top__DOT__gpuOut)))
                                             : ((2U 
                                                 & (IData)(vlTOPp->top__DOT__busState))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__busState))
                                                  ? (IData)(vlTOPp->top__DOT__romOut)
                                                  : (IData)(vlTOPp->top__DOT__ramOut))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__busState))
                                                  ? (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)
                                                  : 0U)))));
    vlTOPp->D10 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xaU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D5 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 5U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D7 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 7U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D11 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xbU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D12 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xcU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
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
    vlTOPp->D1 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 1U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D4 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 4U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D9 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 9U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
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
    vlTOPp->D0 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & (IData)(vlTOPp->top__DOT__bus)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D8 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 8U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
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
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((~ (IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock)) 
         & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock)))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock) 
            ^ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock)))) {
        vlTOPp->_multiclk__TOP__10(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock) 
         ^ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock))) {
        vlTOPp->_multiclk__TOP__11(vlSymsp);
        vlTOPp->__Vm_traceActivity[5U] = 1U;
    }
    if ((((IData)(vlTOPp->CLK) ^ (IData)(vlTOPp->__Vclklast__TOP__CLK)) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock) 
            ^ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock)))) {
        vlTOPp->_multiclk__TOP__12(vlSymsp);
        vlTOPp->__Vm_traceActivity[6U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock 
        = vlTOPp->__VinpClk__TOP__top__DOT__testClock;
    vlTOPp->__VinpClk__TOP__top__DOT__testClock = vlTOPp->top__DOT__testClock;
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
    __req |= ((vlTOPp->top__DOT__testClock ^ vlTOPp->__Vchglast__TOP__top__DOT__testClock));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__testClock ^ vlTOPp->__Vchglast__TOP__top__DOT__testClock))) VL_DBG_MSGF("        CHANGE: verilog/top.v:83: top.testClock\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__testClock = vlTOPp->top__DOT__testClock;
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
    if (VL_UNLIKELY((D0_in & 0xfeU))) {
        Verilated::overWidthError("D0_in");}
    if (VL_UNLIKELY((D1_in & 0xfeU))) {
        Verilated::overWidthError("D1_in");}
    if (VL_UNLIKELY((D2_in & 0xfeU))) {
        Verilated::overWidthError("D2_in");}
    if (VL_UNLIKELY((D3_in & 0xfeU))) {
        Verilated::overWidthError("D3_in");}
    if (VL_UNLIKELY((D4_in & 0xfeU))) {
        Verilated::overWidthError("D4_in");}
    if (VL_UNLIKELY((D5_in & 0xfeU))) {
        Verilated::overWidthError("D5_in");}
    if (VL_UNLIKELY((D6_in & 0xfeU))) {
        Verilated::overWidthError("D6_in");}
    if (VL_UNLIKELY((D7_in & 0xfeU))) {
        Verilated::overWidthError("D7_in");}
    if (VL_UNLIKELY((D8_in & 0xfeU))) {
        Verilated::overWidthError("D8_in");}
    if (VL_UNLIKELY((D9_in & 0xfeU))) {
        Verilated::overWidthError("D9_in");}
    if (VL_UNLIKELY((D10_in & 0xfeU))) {
        Verilated::overWidthError("D10_in");}
    if (VL_UNLIKELY((D11_in & 0xfeU))) {
        Verilated::overWidthError("D11_in");}
    if (VL_UNLIKELY((D12_in & 0xfeU))) {
        Verilated::overWidthError("D12_in");}
    if (VL_UNLIKELY((D13_in & 0xfeU))) {
        Verilated::overWidthError("D13_in");}
    if (VL_UNLIKELY((D14_in & 0xfeU))) {
        Verilated::overWidthError("D14_in");}
    if (VL_UNLIKELY((D15_in & 0xfeU))) {
        Verilated::overWidthError("D15_in");}
}
#endif  // VL_DEBUG
