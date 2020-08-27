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
            VL_FATAL_MT("verilog/top.v", 14, "",
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
            VL_FATAL_MT("verilog/top.v", 14, "",
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
    CData/*7:0*/ __Vdly__top__DOT__UART__DOT__UART__DOT__TXshift;
    CData/*3:0*/ __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate;
    CData/*3:0*/ __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate;
    // Body
    __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate 
        = vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate;
    vlTOPp->__Vdlyvset__top__DOT__CONTROL__DOT__addrstack__v0 = 0U;
    __Vdly__top__DOT__UART__DOT__UART__DOT__TXshift 
        = vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift;
    __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate 
        = vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate;
    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 0U;
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__aluOperation = (0x3fU 
                                              & (IData)(vlTOPp->top__DOT__aluOperation));
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperation = (0x3fU 
                                                  & (IData)(vlTOPp->top__DOT__aluOperation));
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperation 
                        = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x50U;
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperation = ((8U 
                                                   & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 0x48U
                                                    : 0x44U)
                                                   : 0x44U);
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation = 0x44U;
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x42U;
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperation = 0x41U;
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation = 0x60U;
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluOperation 
                                = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluOperation 
                                = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                        }
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluOperation = 0x40U;
                        }
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluResults = (7U 
                                                & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 0xdU));
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluResults = 
                        (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                               >> 0xdU));
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluResults 
                                = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                         >> 0xdU));
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluResults 
                                = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                         >> 0xdU));
                        }
                    }
                }
            }
        }
    }
    if ((8U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
        if ((4U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
            if ((2U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 1U;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0xfU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0xeU;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0xdU;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0xcU;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0xbU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0xaU;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 9U;
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
            __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0U;
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0U;
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 0U;
                    }
                } else {
                    if ((1U & (~ (IData)(vlTOPp->RX)))) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate = 8U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__UART__DOT__UART__DOT__gap = (
                                                   (0U 
                                                    == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate))
                                                    ? 0U
                                                    : 
                                                   (7U 
                                                    & ((IData)(1U) 
                                                       + 
                                                       (3U 
                                                        & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__gap)))));
    if (((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) 
         & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate) 
            >> 3U))) {
        vlTOPp->top__DOT__UART__DOT__uartout = (((IData)(vlTOPp->RX) 
                                                 << 7U) 
                                                | (0x7fU 
                                                   & ((IData)(vlTOPp->top__DOT__UART__DOT__uartout) 
                                                      >> 1U)));
    }
    vlTOPp->top__DOT__UART__DOT__uartoutwrite = ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit) 
                                                 & (1U 
                                                    == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate)));
    if (((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxnprev) 
         != (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn))) {
        vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxnprev 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxnprev)));
    }
    if (((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0prev) 
         != (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0))) {
        vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0prev 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0prev)));
    }
    if (((IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxnprev) 
         != (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn))) {
        vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxnprev 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxnprev)));
    }
    if (((IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0prev) 
         != (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0))) {
        vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0prev 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0prev)));
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluParams 
                            = (0xfU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                       >> 0x10U));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluParams = (0xfU 
                                               & ((8U 
                                                   & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 0x10U)
                                                    : 3U)
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 2U
                                                    : 1U)));
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluParams = 0U;
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluParams 
                            = (0xeU & (IData)(vlTOPp->top__DOT__aluParams));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluParams = (
                                                   (0xeU 
                                                    & (IData)(vlTOPp->top__DOT__aluParams)) 
                                                   | (1U 
                                                      & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                         >> 2U)));
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        vlTOPp->top__DOT__aluReadBus = (1U & ((~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 5U)) 
                                              & ((~ 
                                                  (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 4U)) 
                                                 & ((~ 
                                                     (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 3U)) 
                                                    & (~ 
                                                       (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                        >> 2U))))));
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__aluReadBus = (1U & ((0x10U 
                                                   & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 2U)
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 
                                                    (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                     >> 1U)
                                                     : 
                                                    (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                     >> 1U)))
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                     >> 2U) 
                                                    & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                       >> 1U))
                                                    : 
                                                   ((~ 
                                                     (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 2U)) 
                                                    & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                       >> 1U)))));
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluReadBus = 
                        (1U & ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                ? (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                   >> 1U) : (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                             >> 1U)));
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluReadBus 
                            = (1U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 1U));
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluReadBus = 0U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluReadBus = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__aluReadBus = 0U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluReadBus = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__aluReadBus = 0U;
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                  >> 6U)))) {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    vlTOPp->top__DOT__aluOperand2 = 
                        (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                               >> 0xaU));
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperand2 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xaU));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand2 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xaU));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperand2 = 
                        (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                               >> 0xaU));
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperand2 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xaU));
                    }
                }
            }
        }
    }
    if (((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXready) 
         & (IData)(vlTOPp->top__DOT__UART__DOT__TXstart))) {
        __Vdly__top__DOT__UART__DOT__UART__DOT__TXshift 
            = vlTOPp->top__DOT__UART__DOT__uartin;
    } else {
        if ((((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate) 
              >> 3U) & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick))) {
            __Vdly__top__DOT__UART__DOT__UART__DOT__TXshift 
                = (0xffU & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift) 
                            >> 1U));
        }
    }
    vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc 
        = ((0U == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))
            ? 0U : (7U & ((IData)(1U) + (3U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc)))));
    if ((8U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
        if ((4U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
            if ((2U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 1U;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0xfU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0xeU;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0xdU;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0xcU;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0xbU;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0xaU;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 9U;
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
            if ((2U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                    __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0U;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 8U;
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                    __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))) {
                    if (vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 0U;
                    }
                } else {
                    if (vlTOPp->top__DOT__UART__DOT__TXstart) {
                        __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate = 4U;
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        vlTOPp->top__DOT__ramWrite = 0U;
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__ramWrite = 0U;
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__ramWrite = 0U;
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__ramWrite = 0U;
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__ramWrite = 1U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__ramWrite = 0U;
                        }
                    } else {
                        vlTOPp->top__DOT__ramWrite = 1U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__ramWrite = 0U;
                        }
                    } else {
                        vlTOPp->top__DOT__ramWrite = 0U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__busState = ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                   ? ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                       ? 0U : ((0x10U 
                                                & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                ? 0U
                                                : (
                                                   (8U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 0U
                                                     : 6U))))
                                   : ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                       ? ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                           ? 6U : (
                                                   (8U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 6U
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 0U
                                                     : 6U)))
                                       : ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                           ? ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                               ? 6U
                                               : ((4U 
                                                   & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 6U
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 2U
                                                    : 1U)))
                                           : ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                               ? ((4U 
                                                   & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 2U
                                                   : 1U)
                                               : ((4U 
                                                   & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 2U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 6U
                                                     : 2U))
                                                   : 0U)))));
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        vlTOPp->top__DOT__CONTROL__DOT__increment = 
            ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
              ? 4U : ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                       ? ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                           ? ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                               ? ((0U < ((vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                          >> 7U) & (IData)(vlTOPp->top__DOT__aluStatus)))
                                   ? 5U : 4U) : 7U)
                           : ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)
                               ? 6U : 5U)) : 4U));
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 4U;
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperand1 = (7U 
                                                 & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 7U));
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperand1 = 
                        (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                               >> 7U));
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluOperand1 
                                = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                         >> 7U));
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((0U < ((vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                    >> 7U) & (IData)(vlTOPp->top__DOT__aluStatus)))) {
                            vlTOPp->top__DOT__ctrlOut 
                                = (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    }
                } else {
                    vlTOPp->top__DOT__ctrlOut = (0xffffU 
                                                 & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 0x10U));
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__ctrlOut = 
                            (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                        >> 0x10U));
                    }
                } else {
                    vlTOPp->top__DOT__ctrlOut = (0xffffU 
                                                 & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 0x10U));
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__ctrlOut = 
                            (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                        >> 0x10U));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__ctrlOut = 
                            (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                        >> 0x10U));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__ctrlOut = (0xffffU 
                                                 & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 0x10U));
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__ctrlOut = 
                            (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                        >> 0x10U));
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__ctrlOut 
                                = (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__ctrlOut 
                                = (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    } else {
                        vlTOPp->top__DOT__ctrlOut = 
                            (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                        >> 0x10U));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__ctrlOut 
                                = (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    }
                }
            }
        }
    }
    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                  >> 6U)))) {
        if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                = vlTOPp->top__DOT__ALU__DOT__h;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                = vlTOPp->top__DOT__ALU__DOT__h;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                            = (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                          >> 0x10U));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                = (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate 
        = __Vdly__top__DOT__UART__DOT__UART__DOT__RXstate;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift 
        = __Vdly__top__DOT__UART__DOT__UART__DOT__TXshift;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate 
        = __Vdly__top__DOT__UART__DOT__UART__DOT__TXstate;
    vlTOPp->top__DOT__UART__DOT__UART__DOT__nextBit 
        = (1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__gap) 
                 >> 2U));
    vlTOPp->top__DOT__UART__DOT__UART__DOT__baudTick 
        = (1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc) 
                 >> 2U));
    vlTOPp->top__DOT__UART__DOT__UART__DOT__TXready 
        = (0U == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate));
    vlTOPp->TX = (1U & ((4U > (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate)) 
                        | (((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate) 
                            >> 3U) & (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift))));
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
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0;
    // Body
    __Vdlyvset__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0 = 0U;
    __Vdlyvset__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0 = 0U;
    vlTOPp->__Vdly__top__DOT__CONTROL__DOT__programCounter 
        = vlTOPp->top__DOT__CONTROL__DOT__programCounter;
    vlTOPp->top__DOT__clkdiv = (0x1ffffffU & ((IData)(1U) 
                                              + vlTOPp->top__DOT__clkdiv));
    if (vlTOPp->top__DOT____Vcellinp__UART__write) {
        __Vdlyvval__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0 
            = (0xffU & (IData)(vlTOPp->top__DOT__MEMbus));
        __Vdlyvset__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0 
            = vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxnprev;
    }
    if (vlTOPp->top__DOT__UART__DOT____Vcellinp__OUTFIFO__read) {
        vlTOPp->top__DOT__UART__DOT__dataOutReg = vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__buffer
            [vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0prev];
    }
    if (vlTOPp->top__DOT__UART__DOT__uartoutwrite) {
        __Vdlyvval__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0 
            = vlTOPp->top__DOT__UART__DOT__uartout;
        __Vdlyvset__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0 = 1U;
        __Vdlyvdim0__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0 
            = vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxnprev;
    }
    if (vlTOPp->top__DOT__UART__DOT__sendRead) {
        vlTOPp->top__DOT__UART__DOT__uartin = vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__buffer
            [vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0prev];
    }
    if (vlTOPp->top__DOT____Vcellinp__UART__write) {
        vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn)));
    }
    if (vlTOPp->top__DOT__UART__DOT____Vcellinp__OUTFIFO__read) {
        vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0)));
    }
    if (vlTOPp->top__DOT__UART__DOT__sendRead) {
        vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0)));
    }
    if (vlTOPp->top__DOT__UART__DOT__uartoutwrite) {
        vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn)));
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
        if ((1U & (IData)(vlTOPp->top__DOT__aluOperation))) {
            vlTOPp->top__DOT__aluStatus = ((0x3eU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                           | (0U == 
                                              (0xffffU 
                                               & vlTOPp->top__DOT__ALU__DOT__addsub)));
            vlTOPp->top__DOT__aluStatus = ((0x3dU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                           | (2U & 
                                              (vlTOPp->top__DOT__ALU__DOT__addsub 
                                               >> 0xfU)));
            vlTOPp->top__DOT__aluStatus = ((0x3bU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                           | (4U & 
                                              (vlTOPp->top__DOT__ALU__DOT__addsub 
                                               >> 0xdU)));
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                vlTOPp->top__DOT__aluStatus = ((0x3eU 
                                                & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                               | (0U 
                                                  == 
                                                  (0xffffU 
                                                   & vlTOPp->top__DOT__ALU__DOT__addsub)));
                vlTOPp->top__DOT__aluStatus = ((0x3dU 
                                                & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                               | (2U 
                                                  & (vlTOPp->top__DOT__ALU__DOT__addsub 
                                                     >> 0xfU)));
                vlTOPp->top__DOT__aluStatus = ((0x3bU 
                                                & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                               | (4U 
                                                  & (vlTOPp->top__DOT__ALU__DOT__addsub 
                                                     >> 0xdU)));
            } else {
                if ((4U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                    vlTOPp->top__DOT__aluStatus = (
                                                   (0x3eU 
                                                    & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                                   | (0U 
                                                      == (IData)(vlTOPp->top__DOT__ALU__DOT__log)));
                    vlTOPp->top__DOT__aluStatus = (0x3dU 
                                                   & (IData)(vlTOPp->top__DOT__aluStatus));
                    vlTOPp->top__DOT__aluStatus = (
                                                   (0x3bU 
                                                    & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                                   | (4U 
                                                      & ((IData)(vlTOPp->top__DOT__ALU__DOT__log) 
                                                         >> 0xdU)));
                } else {
                    if ((8U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                        vlTOPp->top__DOT__aluStatus 
                            = ((0x3eU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                               | (0U == (0xffffU & vlTOPp->top__DOT__ALU__DOT__addsub)));
                        vlTOPp->top__DOT__aluStatus 
                            = ((0x3dU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                               | (2U & (vlTOPp->top__DOT__ALU__DOT__addsub 
                                        >> 0xfU)));
                        vlTOPp->top__DOT__aluStatus 
                            = ((0x3bU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                               | (4U & (vlTOPp->top__DOT__ALU__DOT__addsub 
                                        >> 0xdU)));
                    } else {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                            vlTOPp->top__DOT__aluStatus 
                                = ((0x3eU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                   | (0U == (0xffffU 
                                             & vlTOPp->top__DOT__ALU__DOT__addsub)));
                            vlTOPp->top__DOT__aluStatus 
                                = ((0x3dU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                   | (2U & (vlTOPp->top__DOT__ALU__DOT__addsub 
                                            >> 0xfU)));
                            vlTOPp->top__DOT__aluStatus 
                                = ((0x3bU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                   | (4U & (vlTOPp->top__DOT__ALU__DOT__addsub 
                                            >> 0xdU)));
                        } else {
                            if ((0x20U & (IData)(vlTOPp->top__DOT__aluOperation))) {
                                vlTOPp->top__DOT__aluStatus 
                                    = ((0x37U & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                       | (((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                           == (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2)) 
                                          << 3U));
                                vlTOPp->top__DOT__aluStatus 
                                    = ((0x2fU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                       | (((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                           > (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2)) 
                                          << 4U));
                                vlTOPp->top__DOT__aluStatus 
                                    = ((0x1fU & (IData)(vlTOPp->top__DOT__aluStatus)) 
                                       | (((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                           < (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2)) 
                                          << 5U));
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__aluResults) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
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
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 2U)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
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
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 2U)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            if ((1U 
                                                 & (IData)(vlTOPp->top__DOT__aluResults))) {
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
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
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
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluResults) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__aluResults) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlTOPp->top__DOT__aluResults))) {
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
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__aluResults) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__aluResults)))) {
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
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__aluResults) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (IData)(vlTOPp->top__DOT__aluResults))) {
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
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__aluOperation))) {
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
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__aluOperation) 
                                          >> 5U)))) {
                                if (vlTOPp->top__DOT__aluReadBus) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__aluResults))) {
                                            if ((1U 
                                                 & (IData)(vlTOPp->top__DOT__aluResults))) {
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
    }
    if (__Vdlyvset__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0) {
        vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__buffer[__Vdlyvdim0__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0] 
            = __Vdlyvval__top__DOT__UART__DOT__OUTFIFO__DOT__buffer__v0;
    }
    if (__Vdlyvset__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0) {
        vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__buffer[__Vdlyvdim0__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0] 
            = __Vdlyvval__top__DOT__UART__DOT__INFIFO__DOT__buffer__v0;
    }
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
    if (vlTOPp->top__DOT__UART__DOT__sendState) {
        if (vlTOPp->top__DOT__UART__DOT__sendState) {
            vlTOPp->top__DOT__UART__DOT__sendRead = 0U;
            vlTOPp->top__DOT__UART__DOT__TXstart = 1U;
            vlTOPp->top__DOT__UART__DOT__sendState = 0U;
        }
    } else {
        vlTOPp->top__DOT__UART__DOT__TXstart = 0U;
        if (((~ (IData)(vlTOPp->top__DOT__UART__DOT__TXempty)) 
             & (0U == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate)))) {
            vlTOPp->top__DOT__UART__DOT__sendRead = 1U;
            vlTOPp->top__DOT__UART__DOT__sendState = 1U;
        }
    }
    vlTOPp->top__DOT__UART__DOT__RXempty = ((IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0) 
                                            == (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn));
    vlTOPp->top__DOT__UART__DOT__TXempty = ((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                            == (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
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
    vlTOPp->top__DOT__UART__DOT____Vcellinp__OUTFIFO__read 
        = ((3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
           & (~ (IData)(vlTOPp->top__DOT__UART__DOT__RXempty)));
    vlTOPp->__Vdly__top__DOT__CONTROL__DOT__addrstackptr 
        = vlTOPp->top__DOT__CONTROL__DOT__addrstackptr;
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

VL_INLINE_OPT void Vtop::_combo__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OE = ((IData)(vlTOPp->top__DOT__ramWrite) 
                  & (~ (IData)(vlTOPp->CLK)));
    vlTOPp->WR = (1U & (~ ((IData)(vlTOPp->top__DOT__ramWrite) 
                           & (~ (IData)(vlTOPp->CLK)))));
    vlTOPp->top__DOT__bus = ((8U & (IData)(vlTOPp->top__DOT__busState))
                              ? 0U : ((4U & (IData)(vlTOPp->top__DOT__busState))
                                       ? ((2U & (IData)(vlTOPp->top__DOT__busState))
                                           ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__clkOut)
                                               : (IData)(vlTOPp->top__DOT__ctrlOut))
                                           : ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__apuOut)
                                               : (IData)(vlTOPp->top__DOT__gpuOut)))
                                       : ((2U & (IData)(vlTOPp->top__DOT__busState))
                                           ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__romOut)
                                               : (((IData)(vlTOPp->D15_in) 
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
                                           : ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)
                                               : 0U))));
    vlTOPp->UB = vlTOPp->WR;
    vlTOPp->LB = vlTOPp->WR;
    vlTOPp->D5 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 5U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D2 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 2U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D6 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 6U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D13 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xdU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D3 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 3U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D14 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xeU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
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
    vlTOPp->D4 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 4U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D15 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xfU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                    & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D11 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                      & ((IData)(vlTOPp->top__DOT__bus) 
                         >> 0xbU)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
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
    vlTOPp->D1 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 1U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
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
                                                  (((IData)(vlTOPp->top__DOT__UART__DOT__RXempty) 
                                                    << 0xbU) 
                                                   | (((1U 
                                                        == 
                                                        (0xffU 
                                                         & ((IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0) 
                                                            - (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn)))) 
                                                       << 0xaU) 
                                                      | (((IData)(vlTOPp->top__DOT__UART__DOT__TXempty) 
                                                          << 9U) 
                                                         | (((1U 
                                                              == 
                                                              (0xffU 
                                                               & ((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                                                  - (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn)))) 
                                                             << 8U) 
                                                            | (IData)(vlTOPp->top__DOT__UART__DOT__dataOutReg))))))))
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

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__top__DOT__CONTROL__DOT__addrstack__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__CONTROL__DOT__addrstack__v0;
    // Body
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->__Vdly__top__DOT__CONTROL__DOT__addrstackptr 
                            = (0xffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__addrstackptr) 
                                        - (IData)(1U)));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        __Vdlyvval__top__DOT__CONTROL__DOT__addrstack__v0 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)));
                        vlTOPp->__Vdlyvset__top__DOT__CONTROL__DOT__addrstack__v0 = 1U;
                        __Vdlyvdim0__top__DOT__CONTROL__DOT__addrstack__v0 
                            = vlTOPp->top__DOT__CONTROL__DOT__addrstackptr;
                    }
                }
            }
        }
    }
    if (vlTOPp->__Vdlyvset__top__DOT__CONTROL__DOT__addrstack__v0) {
        vlTOPp->top__DOT__CONTROL__DOT__addrstack[__Vdlyvdim0__top__DOT__CONTROL__DOT__addrstack__v0] 
            = __Vdlyvval__top__DOT__CONTROL__DOT__addrstack__v0;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((4U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
        if ((2U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
            if ((1U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
                vlTOPp->__Vdly__top__DOT__CONTROL__DOT__programCounter 
                    = vlTOPp->top__DOT__CONTROL__DOT__addrstack
                    [vlTOPp->top__DOT__CONTROL__DOT__addrstackptr];
            } else {
                vlTOPp->__Vdly__top__DOT__CONTROL__DOT__addrstackptr 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__CONTROL__DOT__addrstackptr)));
                vlTOPp->__Vdly__top__DOT__CONTROL__DOT__programCounter 
                    = vlTOPp->top__DOT__ctrlOut;
            }
        } else {
            vlTOPp->__Vdly__top__DOT__CONTROL__DOT__programCounter 
                = (0xffffU & ((1U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))
                               ? (IData)(vlTOPp->top__DOT__ctrlOut)
                               : ((IData)(1U) + (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))));
        }
    }
    vlTOPp->top__DOT__CONTROL__DOT__programCounter 
        = vlTOPp->__Vdly__top__DOT__CONTROL__DOT__programCounter;
    vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
        = ((0x8000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
            ? 0U : ((0x4000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                     ? 0U : ((0x2000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                              ? 0U : ((0x1000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                       ? 0U : ((0x800U 
                                                & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                ? 0U
                                                : (
                                                   (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                    ? 0U
                                                    : 
                                                   ((0x200U 
                                                     & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                     ? 0U
                                                     : 
                                                    ((0x100U 
                                                      & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                      ? 0U
                                                      : 
                                                     ((0x80U 
                                                       & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                       ? 0U
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                        ? 0U
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                         ? 0U
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                           ? 0U
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0U
                                                              : 0x58U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x60050U
                                                              : 0x12085cU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xff0216U
                                                              : 0x2821aU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x30188U
                                                              : 0x86042U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x30008U
                                                              : 0x211aU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x418U
                                                              : 0x401aU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x3085cU
                                                              : 0x80000016U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4006U
                                                              : 0x2006U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10006U
                                                              : 0x20050U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x30054U
                                                              : 0x8006U))))))))))))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__9\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__CONTROL__DOT__addrstackptr = vlTOPp->__Vdly__top__DOT__CONTROL__DOT__addrstackptr;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->CLK) ^ (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity[5U] = 1U;
    }
    if (((IData)(vlTOPp->CLK) ^ (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
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
