// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog/top.v", 17, "",
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
            VL_FATAL_MT("verilog/top.v", 17, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->GPIO9 = 1U;
    vlTOPp->GPIO11 = 0U;
    vlTOPp->CE = 1U;
    vlTOPp->B_CE = 1U;
    vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg = 0U;
    vlTOPp->top__DOT__aluParams = 0U;
    vlTOPp->top__DOT__gpuWrite = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand2 = 0U;
    vlTOPp->top__DOT__ramWrite = 0U;
    vlTOPp->top__DOT__aluOperand2 = 0U;
    vlTOPp->top__DOT__busState = 0U;
    vlTOPp->top__DOT__DROM__DOT__ROMDATA__DOT__dintern = 0U;
    vlTOPp->top__DOT__aluOperand1 = 0U;
    vlTOPp->top__DOT__ALU__DOT__a = 0U;
    vlTOPp->top__DOT__ALU__DOT__b = 0U;
    vlTOPp->top__DOT__ALU__DOT__c = 0U;
    vlTOPp->top__DOT__ALU__DOT__d = 0U;
    vlTOPp->top__DOT__ALU__DOT__e = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__increment = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__addrstackptr = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__tempCounter = 0U;
    vlTOPp->top__DOT__clkdiv = 0U;
    vlTOPp->top__DOT__ALU__DOT__f = 0U;
    vlTOPp->top__DOT__ALU__DOT__g = 0U;
    vlTOPp->top__DOT__ALU__DOT__h = 0U;
    vlTOPp->top__DOT__aluResults = 0U;
    vlTOPp->top__DOT__aluStatus = 0U;
    vlTOPp->top__DOT__aluReadBus = 0U;
    vlTOPp->top__DOT__bus = 0U;
    vlTOPp->top__DOT__aluOperation = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand1 = 0U;
    vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern = 0U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__top__DOT__CONTROL__DOT__addrstackptr;
    // Body
    __Vdly__top__DOT__CONTROL__DOT__addrstackptr = vlTOPp->top__DOT__CONTROL__DOT__addrstackptr;
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperation = (0x3fU 
                                                  & (IData)(vlTOPp->top__DOT__aluOperation));
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0U;
                    }
                } else {
                    vlTOPp->top__DOT__aluOperation 
                        = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperation = (0x3fU 
                                                  & (IData)(vlTOPp->top__DOT__aluOperation));
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperation 
                        = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x50U;
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperation = ((8U 
                                                   & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 0x48U
                                                    : 0x44U)
                                                   : 0x44U);
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation = 0x44U;
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x42U;
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperation = ((8U 
                                                   & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 0x41U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 0x60U
                                                    : 0U));
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperation 
                        = ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                            ? 0x40U : 0U);
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation = 0x40U;
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x3fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluResults = (7U 
                                                & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 0xdU));
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluResults = 
                        (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                               >> 0xdU));
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluResults 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 0xdU));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluParams 
                            = (0xeU & (IData)(vlTOPp->top__DOT__aluParams));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluParams 
                            = (0xeU & (IData)(vlTOPp->top__DOT__aluParams));
                    } else {
                        vlTOPp->top__DOT__aluParams = 3U;
                    }
                } else {
                    vlTOPp->top__DOT__aluParams = (
                                                   (4U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 2U
                                                    : 1U);
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluParams = 0U;
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluParams 
                            = (0xeU & (IData)(vlTOPp->top__DOT__aluParams));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluParams = (
                                                   (0xeU 
                                                    & (IData)(vlTOPp->top__DOT__aluParams)) 
                                                   | (1U 
                                                      & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                         >> 2U)));
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__gpuWrite 
                            = (1U & ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                      ? (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                      : (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)));
                    }
                } else {
                    vlTOPp->top__DOT__gpuWrite = 0U;
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__gpuWrite = 0U;
            } else {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__gpuWrite = 0U;
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__gpuWrite = 0U;
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__gpuWrite = 0U;
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__gpuWrite = 0U;
                    } else {
                        if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__gpuWrite = 1U;
                            }
                        } else {
                            vlTOPp->top__DOT__gpuWrite = 0U;
                        }
                    }
                }
            } else {
                vlTOPp->top__DOT__gpuWrite = ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                               >> 3U) 
                                              & ((~ 
                                                  (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 2U)) 
                                                 & ((0U 
                                                     != 
                                                     (3U 
                                                      & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) 
                                                    & (2U 
                                                       == 
                                                       (3U 
                                                        & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)))));
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluReadBus = 0U;
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluReadBus = 0U;
                    }
                } else {
                    vlTOPp->top__DOT__aluReadBus = 0U;
                }
            }
        } else {
            vlTOPp->top__DOT__aluReadBus = (1U & ((~ 
                                                   (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 4U)) 
                                                  & ((~ 
                                                      (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                       >> 3U)) 
                                                     & ((~ 
                                                         (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                          >> 2U)) 
                                                        & ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                            >> 1U) 
                                                           | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))))));
        }
    } else {
        vlTOPp->top__DOT__aluReadBus = (1U & ((0x20U 
                                               & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                               ? ((0x10U 
                                                   & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 
                                                    ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 1U) 
                                                     | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))
                                                     : 
                                                    ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 1U) 
                                                     | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)))
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 
                                                    ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 1U) 
                                                     | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))
                                                     : 
                                                    ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 1U) 
                                                     | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))))
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                     >> 2U) 
                                                    & ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                        >> 1U) 
                                                       | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)))
                                                    : 
                                                   ((~ 
                                                     (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 2U)) 
                                                    & ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                        >> 1U) 
                                                       | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)))))
                                               : ((0x10U 
                                                   & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 
                                                    ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 1U) 
                                                     | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))
                                                     : 
                                                    ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                      >> 1U) 
                                                     | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)))
                                                    : 
                                                   ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                     >> 2U) 
                                                    & ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                        >> 1U) 
                                                       | (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))))
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 2U)
                                                    : 
                                                   (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 2U)))));
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        vlTOPp->top__DOT__ramWrite = (1U & ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 5U) 
                                            & ((~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 4U)) 
                                               & ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 3U) 
                                                  & ((~ 
                                                      (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                       >> 2U)) 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)))));
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__ramWrite = 0U;
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__ramWrite = 0U;
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__ramWrite = 0U;
                    } else {
                        if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ramWrite = 0U;
                            }
                        } else {
                            vlTOPp->top__DOT__ramWrite = 1U;
                        }
                    }
                }
            } else {
                vlTOPp->top__DOT__ramWrite = ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                               >> 3U) 
                                              & ((~ 
                                                  (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 2U)) 
                                                 & (0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))));
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    } else {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    } else {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    } else {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__aluOperand2 
                                    = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU));
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__busState = ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                           ? 0U : (
                                                   (8U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((4U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                      ? 3U
                                                      : 
                                                     ((1U 
                                                       & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                       ? 4U
                                                       : 2U)))
                                                    : 0U));
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__busState = 0U;
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__busState = 0U;
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__busState = 0U;
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__busState = 0U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__busState = 0U;
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            vlTOPp->top__DOT__busState 
                                = ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                    ? 6U : 4U);
                        } else {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__busState = 2U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__busState 
                            = ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                ? 6U : 1U);
                    }
                }
            } else {
                vlTOPp->top__DOT__busState = ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                               ? ((4U 
                                                   & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 0U
                                                     : 4U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 3U
                                                     : 2U))
                                                   : 1U)
                                               : ((4U 
                                                   & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 6U
                                                     : 4U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 3U
                                                     : 2U))
                                                   : 0U));
            }
        }
    }
    vlTOPp->top__DOT__CONTROL__DOT__increment = ((0x40U 
                                                  & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                  ? 
                                                 ((0x20U 
                                                   & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                   ? 
                                                  ((0x10U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 4U
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 4U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                      ? 
                                                     ((0U 
                                                       < 
                                                       ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                         >> 7U) 
                                                        & (IData)(vlTOPp->top__DOT__aluStatus)))
                                                       ? 7U
                                                       : 4U)
                                                      : 
                                                     ((0U 
                                                       < 
                                                       ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                         >> 7U) 
                                                        & (IData)(vlTOPp->top__DOT__aluStatus)))
                                                       ? 6U
                                                       : 4U))))
                                                   : 
                                                  ((0x10U 
                                                    & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                     ? 
                                                    ((4U 
                                                      & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                      ? 
                                                     ((0U 
                                                       < 
                                                       ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                         >> 7U) 
                                                        & (IData)(vlTOPp->top__DOT__aluStatus)))
                                                       ? 5U
                                                       : 4U)
                                                      : 7U)
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)
                                                      ? 6U
                                                      : 5U))
                                                    : 4U))
                                                  : 4U);
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((0U < ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                    >> 7U) & (IData)(vlTOPp->top__DOT__aluStatus)))) {
                            __Vdly__top__DOT__CONTROL__DOT__addrstackptr 
                                = (0xffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__addrstackptr) 
                                            - (IData)(1U)));
                        }
                    } else {
                        if ((0U < ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                    >> 7U) & (IData)(vlTOPp->top__DOT__aluStatus)))) {
                            __Vdly__top__DOT__CONTROL__DOT__addrstackptr 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlTOPp->top__DOT__CONTROL__DOT__addrstackptr)));
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        __Vdly__top__DOT__CONTROL__DOT__addrstackptr 
                            = (0xffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__addrstackptr) 
                                        - (IData)(1U)));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        __Vdly__top__DOT__CONTROL__DOT__addrstackptr 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->top__DOT__CONTROL__DOT__addrstackptr)));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((0U < ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                    >> 7U) & (IData)(vlTOPp->top__DOT__aluStatus)))) {
                            vlTOPp->top__DOT__CONTROL__DOT__tempCounter 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)));
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__CONTROL__DOT__tempCounter 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperand1 = (7U 
                                                 & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 7U));
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperand1 = (7U 
                                                 & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 7U));
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__aluOperand1 
                            = (7U & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                     >> 7U));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((0U < ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                    >> 7U) & (IData)(vlTOPp->top__DOT__aluStatus)))) {
                            vlTOPp->top__DOT__ctrlOut 
                                = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((0U < ((vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                    >> 7U) & (IData)(vlTOPp->top__DOT__aluStatus)))) {
                            vlTOPp->top__DOT__ctrlOut 
                                = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    }
                } else {
                    vlTOPp->top__DOT__ctrlOut = (0xffffU 
                                                 & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                    >> 0x10U));
                }
            } else {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__ctrlOut = 
                            (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                        >> 0x10U));
                    }
                }
            } else {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__ctrlOut 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                            = vlTOPp->top__DOT__ALU__DOT__h;
                    }
                }
            }
        } else {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = vlTOPp->top__DOT__ALU__DOT__h;
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = vlTOPp->top__DOT__ALU__DOT__h;
                            }
                        }
                    } else {
                        if ((0U != (3U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                            if ((2U == (3U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((2U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                            = vlTOPp->top__DOT__ALU__DOT__f;
                    }
                }
            }
        } else {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                              >> 3U)))) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                = vlTOPp->top__DOT__ALU__DOT__f;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = vlTOPp->top__DOT__ALU__DOT__f;
                            }
                        }
                    } else {
                        if ((0U == (3U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                              >> 0x10U));
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & (~ vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern))) {
                                vlTOPp->top__DOT__CONTROL__DOT__ramAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
                        vlTOPp->top__DOT__CONTROL__DOT__romAddReg 
                            = vlTOPp->top__DOT__ALU__DOT__g;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                      >> 5U)))) {
            if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                          >> 4U)))) {
                if ((8U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__CONTROL__DOT__romAddReg 
                                    = vlTOPp->top__DOT__ALU__DOT__g;
                            }
                        }
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                      >> 1U)))) {
                            if ((1U & vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern)) {
                                vlTOPp->top__DOT__CONTROL__DOT__romAddReg 
                                    = (0xffffU & (vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U));
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__CONTROL__DOT__addrstackptr = __Vdly__top__DOT__CONTROL__DOT__addrstackptr;
    vlTOPp->BUFFER_ADDRESS = vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg;
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
    vlTOPp->top__DOT__DROM__DOT__ROMDATA__DOT__dintern 
        = ((0x8000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
            ? 0U : ((0x4000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                     ? 0U : ((0x2000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                              ? 0U : ((0x1000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                       ? 0U : ((0x800U 
                                                & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                ? 0U
                                                : (
                                                   (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                    ? 0U
                                                    : 
                                                   ((0x200U 
                                                     & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                     ? 
                                                    ((0x100U 
                                                      & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                      ? 0U
                                                      : 
                                                     ((0x80U 
                                                       & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                       ? 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 0U
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x73U
                                                              : 0x63U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x69U
                                                              : 0x68U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x70U
                                                              : 0x61U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x72U
                                                              : 0x67U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x74U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x78U
                                                              : 0x65U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x74U
                                                              : 0x20U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x64U
                                                              : 0x6eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x61U
                                                              : 0x20U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x65U
                                                              : 0x74U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x69U
                                                              : 0x72U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x70U
                                                              : 0x73U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x67U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6eU
                                                              : 0x69U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6bU
                                                              : 0x72U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6fU
                                                              : 0x77U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x2aU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x65U
                                                              : 0x6cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x70U
                                                              : 0x6dU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x69U
                                                              : 0x73U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x2aU
                                                              : 0x20U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x65U
                                                              : 0x76U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x61U
                                                              : 0x68U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x77U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6fU
                                                              : 0x6eU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x49U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x33U
                                                              : 0x22c5U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xabU
                                                              : 0x7d6eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x2020U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xffU
                                                              : 0xffffU)
                                                             : 0U))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 0U
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x400U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x600U
                                                              : 0xf20U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fe0U
                                                              : 0xf20U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xbfe0U
                                                              : 0xffc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe7c0U
                                                              : 0x380U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x180U
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 0xc0U)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x61c0U
                                                              : 0x7990U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bf0U
                                                              : 0x1f90U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xff0U
                                                              : 0x17e0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11e0U
                                                              : 0xe0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0xc0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc0U
                                                              : 0U))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc0U
                                                              : 0x30c0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x38c0U
                                                              : 0x3cc8U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1df8U
                                                              : 0x1fc8U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xff8U
                                                              : 0xff0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x14f0U
                                                              : 0x1860U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x60U
                                                              : 0xc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc0U
                                                              : 0U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x180U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3180U
                                                              : 0x3b90U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3bf0U
                                                              : 0x1f90U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1ff0U
                                                              : 0xfe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x38e0U
                                                              : 0x31c0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1c0U
                                                              : 0x180U)
                                                             : 0U))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x300U
                                                              : 0x3720U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x37e0U
                                                              : 0x3f20U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fe0U
                                                              : 0x2fc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6380U
                                                              : 0x300U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x600U
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xe60U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x37e0U
                                                              : 0x7e60U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xbfe0U
                                                              : 0xafc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x380U
                                                              : 0x700U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe00U
                                                              : 0xc00U)
                                                             : 0U))))))))
                                                     : 
                                                    ((0x100U 
                                                      & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                      ? 
                                                     ((0x80U 
                                                       & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                       ? 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x640U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfc0U
                                                              : 0xde40U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xbfc0U
                                                              : 0x3f80U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1700U
                                                              : 0xe00U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc00U
                                                              : 0U)
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x9fe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe720U
                                                              : 0xdfe0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fe0U
                                                              : 0x33c0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x2780U
                                                              : 0x600U))
                                                            : 0U)))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc000U
                                                              : 0xfcf0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xff90U
                                                              : 0x37f0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcf0U
                                                              : 0x1fe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bc0U
                                                              : 0x1300U))
                                                            : 0U))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x7800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7c00U
                                                              : 0x3ef0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1f90U
                                                              : 0xcf0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xf70U
                                                              : 0x1be0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bc0U
                                                              : 0x1800U))
                                                            : 0U))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xc00U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe00U
                                                              : 0xf78U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7c8U
                                                              : 0x678U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7b8U
                                                              : 0xdf0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1de0U
                                                              : 0x1800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x800U
                                                              : 0U)
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc00U
                                                              : 0xff0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x790U
                                                              : 0x5f0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xa70U
                                                              : 0x1be0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bc0U
                                                              : 0x3800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3000U
                                                              : 0U)
                                                             : 0U))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1800U
                                                              : 0x1fe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1f20U
                                                              : 0xfe0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x9e0U
                                                              : 0x17c0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3700U
                                                              : 0x3000U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6000U
                                                              : 0U)
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x400U
                                                              : 0xfe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1f20U
                                                              : 0x17e0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfe0U
                                                              : 0x3bc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7700U
                                                              : 0xe700U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x4600U
                                                              : 0U)
                                                             : 0U))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 1U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 2U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x1bU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bU
                                                              : 0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x16U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x1aU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x28U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 6U
                                                              : 0x12U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x12U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x1cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0xeU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x18U
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x10U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x12U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 2U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x1eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x14U
                                                              : 2U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0x1cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3eU
                                                              : 0x12U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0xcU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0x3eU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x12U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x1cU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0x1eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0xeU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x10U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0xcU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x1dU))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x10U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1dU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x2aU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 5U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 4U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x16U
                                                              : 0x1aU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0xcU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x12U
                                                             : 0xcU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1cU
                                                              : 0x16U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1aU
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 1U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x10U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 2U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 1U
                                                              : 2U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 8U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 2U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x11U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x13U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x19U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 0x1cU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 0x1bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x1bU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xcU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 7U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x18U
                                                              : 7U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x10U))))))))
                                                      : 
                                                     ((0x80U 
                                                       & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                       ? 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfU
                                                              : 1U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 1U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 9U
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0x16U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xdU
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x19U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 2U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 5U
                                                              : 0x1fU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x11U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 6U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x10U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bU
                                                              : 4U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xfU)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 8U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1dU
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 5U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 5U
                                                              : 0x1fU)
                                                             : 0x15U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x11U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0xaU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 5U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x16U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0xeU))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 1U
                                                              : 4U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x11U)
                                                             : 0xaU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x11U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 4U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xaU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 0U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfU
                                                              : 0x15U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x17U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 5U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x19U
                                                              : 0x1dU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x1eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 9U
                                                              : 0x15U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x17U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 7U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x12U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x19U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0xfU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1eU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 4U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x18U
                                                              : 0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 0U)
                                                             : 4U))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 8U
                                                              : 0x10U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 5U)))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 5U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xeU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x11U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 3U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1cU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x17U
                                                              : 0xfU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 4U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 9U
                                                              : 5U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xaU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xaU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 3U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 3U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x17U))
                                                            : 0U)))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0x1fU
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))))))))))))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__top__DOT__CONTROL__DOT__addrstack__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__CONTROL__DOT__addrstack__v0;
    SData/*15:0*/ __Vdlyvval__top__DOT__CONTROL__DOT__addrstack__v0;
    // Body
    __Vdlyvset__top__DOT__CONTROL__DOT__addrstack__v0 = 0U;
    vlTOPp->top__DOT__clkdiv = (0x1ffffffU & ((IData)(1U) 
                                              + vlTOPp->top__DOT__clkdiv));
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
    if ((4U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
        if ((2U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment)))) {
                __Vdlyvval__top__DOT__CONTROL__DOT__addrstack__v0 
                    = vlTOPp->top__DOT__CONTROL__DOT__tempCounter;
                __Vdlyvset__top__DOT__CONTROL__DOT__addrstack__v0 = 1U;
                __Vdlyvdim0__top__DOT__CONTROL__DOT__addrstack__v0 
                    = (0xffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__addrstackptr) 
                                - (IData)(1U)));
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
    if ((4U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
        vlTOPp->top__DOT__CONTROL__DOT__programCounter 
            = (0xffffU & ((2U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))
                           ? ((1U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))
                               ? vlTOPp->top__DOT__CONTROL__DOT__addrstack
                              [vlTOPp->top__DOT__CONTROL__DOT__addrstackptr]
                               : (IData)(vlTOPp->top__DOT__ctrlOut))
                           : ((1U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))
                               ? (IData)(vlTOPp->top__DOT__ctrlOut)
                               : ((IData)(1U) + (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)))));
    }
    if (__Vdlyvset__top__DOT__CONTROL__DOT__addrstack__v0) {
        vlTOPp->top__DOT__CONTROL__DOT__addrstack[__Vdlyvdim0__top__DOT__CONTROL__DOT__addrstack__v0] 
            = __Vdlyvval__top__DOT__CONTROL__DOT__addrstack__v0;
    }
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
    vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
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
                                                       ? 
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
                                                          ? 0U
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
                                                              ? 0U
                                                              : 0x870050U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1e39bU
                                                              : 0x1c31bU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x11U
                                                              : 0xdU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1209bU
                                                              : 0x464U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xa0097U
                                                              : 0x2007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x9900e007U
                                                              : 0x280c007U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x58U
                                                              : 0x4010008U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 7U
                                                              : 0x58U)))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 0x4010008U
                                                              : 0x81045cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xe0017U
                                                              : 0x1001bU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4010004U
                                                              : 0x4020008U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x2001bU
                                                              : 0x4020004U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x480054U
                                                              : 0x402e004U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x180c31bU
                                                              : 0x10c323U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x401c004U
                                                              : 0x4a007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10108007U
                                                              : 0x58U))))
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
                                                              ? 0x71045cU
                                                              : 0x17U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4000004U
                                                              : 0x4d0050U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4007U
                                                              : 0x1e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xdU
                                                              : 0x1c31bU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xeb9dU
                                                              : 0x1004123U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1619bU
                                                              : 0x464U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1195U
                                                              : 0x88243U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4048004U
                                                              : 0x4d0050U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 0x10043U
                                                              : 0x1411bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x100e39bU
                                                              : 0x291U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x8a2c3U
                                                              : 0x405a004U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4d0050U
                                                              : 0x10043U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1411bU
                                                              : 0x100e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x291U
                                                              : 0xffa2afU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x405a004U
                                                              : 0x5a00dcU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1202fU
                                                              : 0x61045cU))))
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
                                                              ? 0x1115U
                                                              : 0xff822fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4048004U
                                                              : 0xdU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x6007U
                                                              : 0x4007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4040208U
                                                              : 0x4050288U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x3d0050U
                                                              : 0x1c31bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x403c004U
                                                              : 0x600e39fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x2e39bU
                                                              : 0x220054U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xc01bU
                                                              : 0x464U))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 0x17U
                                                              : 0xdU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4030308U
                                                              : 0x270050U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x600e39fU
                                                              : 0x1e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4007U
                                                              : 0xdU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1c31bU
                                                              : 0x1619bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x464U
                                                              : 0x20197U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x270050U
                                                              : 0x100e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x291U
                                                              : 0x270050U))))
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
                                                              ? 0x100e39bU
                                                              : 0x211U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x31045cU
                                                              : 0x97U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10043U
                                                              : 0x1202fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1411bU
                                                              : 0x34045cU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x60117U
                                                              : 0x6007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4007U
                                                              : 0xdU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xc31bU
                                                              : 0x3c323U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x58U
                                                              : 0x4000008U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 7U
                                                              : 0x1064U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10017U
                                                              : 0x4000008U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1001bU
                                                              : 0x4000004U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x58U
                                                              : 0x311U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xc007U
                                                              : 0xffffe007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x110050U
                                                              : 0x464U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10017U
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xffffe007U
                                                              : 0x100050U))))
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
                                                              ? 0x60050U
                                                              : 0x6d0054U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x3d0054U
                                                              : 0xa007U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x38007U
                                                              : 0xc20e007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x28ac007U
                                                              : 0x1a0054U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x160054U
                                                              : 0x110054U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x840054U
                                                              : 0x4020008U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x20100007U
                                                              : 0x4010008U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4000008U
                                                              : 7U))))))))))))))));
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->top__DOT__DROM__DOT__ROMDATA__DOT__dintern 
        = ((0x8000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
            ? 0U : ((0x4000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                     ? 0U : ((0x2000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                              ? 0U : ((0x1000U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                       ? 0U : ((0x800U 
                                                & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                ? 0U
                                                : (
                                                   (0x400U 
                                                    & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                    ? 0U
                                                    : 
                                                   ((0x200U 
                                                     & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                     ? 
                                                    ((0x100U 
                                                      & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                      ? 0U
                                                      : 
                                                     ((0x80U 
                                                       & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                       ? 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 0U
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x73U
                                                              : 0x63U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x69U
                                                              : 0x68U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x70U
                                                              : 0x61U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x72U
                                                              : 0x67U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x74U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x78U
                                                              : 0x65U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x74U
                                                              : 0x20U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x64U
                                                              : 0x6eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x61U
                                                              : 0x20U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x65U
                                                              : 0x74U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x69U
                                                              : 0x72U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x70U
                                                              : 0x73U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x67U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6eU
                                                              : 0x69U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6bU
                                                              : 0x72U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6fU
                                                              : 0x77U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x2aU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x65U
                                                              : 0x6cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x70U
                                                              : 0x6dU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x69U
                                                              : 0x73U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x2aU
                                                              : 0x20U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x65U
                                                              : 0x76U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x61U
                                                              : 0x68U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x77U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6fU
                                                              : 0x6eU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x49U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x33U
                                                              : 0x22c5U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xabU
                                                              : 0x7d6eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x2020U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xffU
                                                              : 0xffffU)
                                                             : 0U))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 0U
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x400U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x600U
                                                              : 0xf20U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fe0U
                                                              : 0xf20U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xbfe0U
                                                              : 0xffc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe7c0U
                                                              : 0x380U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x180U
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 0xc0U)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x61c0U
                                                              : 0x7990U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bf0U
                                                              : 0x1f90U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xff0U
                                                              : 0x17e0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11e0U
                                                              : 0xe0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0xc0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc0U
                                                              : 0U))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc0U
                                                              : 0x30c0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x38c0U
                                                              : 0x3cc8U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1df8U
                                                              : 0x1fc8U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xff8U
                                                              : 0xff0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x14f0U
                                                              : 0x1860U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x60U
                                                              : 0xc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc0U
                                                              : 0U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x180U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3180U
                                                              : 0x3b90U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3bf0U
                                                              : 0x1f90U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1ff0U
                                                              : 0xfe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x38e0U
                                                              : 0x31c0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1c0U
                                                              : 0x180U)
                                                             : 0U))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x300U
                                                              : 0x3720U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x37e0U
                                                              : 0x3f20U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fe0U
                                                              : 0x2fc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6380U
                                                              : 0x300U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x600U
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xe60U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x37e0U
                                                              : 0x7e60U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xbfe0U
                                                              : 0xafc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x380U
                                                              : 0x700U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe00U
                                                              : 0xc00U)
                                                             : 0U))))))))
                                                     : 
                                                    ((0x100U 
                                                      & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                      ? 
                                                     ((0x80U 
                                                       & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                       ? 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x640U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfc0U
                                                              : 0xde40U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xbfc0U
                                                              : 0x3f80U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1700U
                                                              : 0xe00U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc00U
                                                              : 0U)
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x9fe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe720U
                                                              : 0xdfe0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fe0U
                                                              : 0x33c0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x2780U
                                                              : 0x600U))
                                                            : 0U)))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc000U
                                                              : 0xfcf0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xff90U
                                                              : 0x37f0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcf0U
                                                              : 0x1fe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bc0U
                                                              : 0x1300U))
                                                            : 0U))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x7800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7c00U
                                                              : 0x3ef0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1f90U
                                                              : 0xcf0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xf70U
                                                              : 0x1be0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bc0U
                                                              : 0x1800U))
                                                            : 0U))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xc00U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xe00U
                                                              : 0xf78U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7c8U
                                                              : 0x678U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7b8U
                                                              : 0xdf0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1de0U
                                                              : 0x1800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x800U
                                                              : 0U)
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xc00U
                                                              : 0xff0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x790U
                                                              : 0x5f0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xa70U
                                                              : 0x1be0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bc0U
                                                              : 0x3800U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3000U
                                                              : 0U)
                                                             : 0U))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1800U
                                                              : 0x1fe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1f20U
                                                              : 0xfe0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x9e0U
                                                              : 0x17c0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3700U
                                                              : 0x3000U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x6000U
                                                              : 0U)
                                                             : 0U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0U
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x400U
                                                              : 0xfe0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1f20U
                                                              : 0x17e0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfe0U
                                                              : 0x3bc0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x7700U
                                                              : 0xe700U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x4600U
                                                              : 0U)
                                                             : 0U))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 1U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 2U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x1bU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bU
                                                              : 0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x16U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x1aU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x28U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 6U
                                                              : 0x12U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x12U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x1cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0xeU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x18U
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x10U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x12U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 2U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x1eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x14U
                                                              : 2U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0x1cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x3eU
                                                              : 0x12U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0xcU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0x3eU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x12U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x1cU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0x1eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0xeU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x10U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0xcU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x1dU))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x20U
                                                              : 0x10U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1dU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x2aU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 5U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 4U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x16U
                                                              : 0x1aU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xcU
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0xcU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x12U
                                                             : 0xcU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1cU
                                                              : 0x16U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1aU
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 1U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x10U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 2U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 1U
                                                              : 2U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 8U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 2U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x11U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x13U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x19U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 0x1cU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 0x1bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x1bU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xcU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 7U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x18U
                                                              : 7U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x10U))))))))
                                                      : 
                                                     ((0x80U 
                                                       & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                       ? 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfU
                                                              : 1U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 1U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 9U
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 0x16U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xdU
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x19U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 2U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 5U
                                                              : 0x1fU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x11U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 6U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x10U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1bU
                                                              : 4U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xfU)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 8U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1dU
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 5U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 5U
                                                              : 0x1fU)
                                                             : 0x15U)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x11U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0xaU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 5U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1eU
                                                              : 0x16U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0xeU))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 1U
                                                              : 4U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x11U)
                                                             : 0xaU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x11U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 4U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xaU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 0U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xfU
                                                              : 0x15U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x17U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 5U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x19U
                                                              : 0x1dU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x1eU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 9U
                                                              : 0x15U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x17U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 7U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xaU
                                                              : 0x15U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x12U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x15U
                                                              : 0x19U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 0xfU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1eU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 3U
                                                              : 4U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x18U
                                                              : 0U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x10U
                                                              : 0U)
                                                             : 4U))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 8U
                                                              : 0x10U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 4U
                                                              : 5U)))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 2U
                                                              : 5U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0xeU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x11U
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0xeU
                                                              : 0U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 3U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x1cU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x17U
                                                              : 0xfU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x12U
                                                              : 4U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 9U
                                                              : 5U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xaU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0xaU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 3U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 3U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0U
                                                              : 0x17U))
                                                            : 0U)))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 0x1fU
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                          ? 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU)
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))))
                                                          : 
                                                         ((8U 
                                                           & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                           ? 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U)
                                                             : 0x1fU))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x1fU
                                                              : 0x11U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                             ? 0x1fU
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__romAddReg))
                                                              ? 0x11U
                                                              : 0x1fU))))))))))))))));
    vlTOPp->top__DOT__PROM__DOT__ROMDATA__DOT__dintern 
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
                                                       ? 
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
                                                          ? 0U
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
                                                              ? 0U
                                                              : 0x870050U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1e39bU
                                                              : 0x1c31bU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x11U
                                                              : 0xdU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1209bU
                                                              : 0x464U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xa0097U
                                                              : 0x2007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x9900e007U
                                                              : 0x280c007U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x58U
                                                              : 0x4010008U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 7U
                                                              : 0x58U)))))))
                                                       : 
                                                      ((0x40U 
                                                        & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                        ? 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 0x4010008U
                                                              : 0x81045cU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xe0017U
                                                              : 0x1001bU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4010004U
                                                              : 0x4020008U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x2001bU
                                                              : 0x4020004U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x480054U
                                                              : 0x402e004U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x180c31bU
                                                              : 0x10c323U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x401c004U
                                                              : 0x4a007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10108007U
                                                              : 0x58U))))
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
                                                              ? 0x71045cU
                                                              : 0x17U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4000004U
                                                              : 0x4d0050U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4007U
                                                              : 0x1e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xdU
                                                              : 0x1c31bU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xeb9dU
                                                              : 0x1004123U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1619bU
                                                              : 0x464U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1195U
                                                              : 0x88243U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4048004U
                                                              : 0x4d0050U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 0x10043U
                                                              : 0x1411bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x100e39bU
                                                              : 0x291U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x8a2c3U
                                                              : 0x405a004U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4d0050U
                                                              : 0x10043U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1411bU
                                                              : 0x100e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x291U
                                                              : 0xffa2afU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x405a004U
                                                              : 0x5a00dcU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1202fU
                                                              : 0x61045cU))))
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
                                                              ? 0x1115U
                                                              : 0xff822fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4048004U
                                                              : 0xdU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x6007U
                                                              : 0x4007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4040208U
                                                              : 0x4050288U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x3d0050U
                                                              : 0x1c31bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x403c004U
                                                              : 0x600e39fU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x2e39bU
                                                              : 0x220054U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xc01bU
                                                              : 0x464U))))))
                                                        : 
                                                       ((0x20U 
                                                         & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                         ? 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 0x17U
                                                              : 0xdU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4030308U
                                                              : 0x270050U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x600e39fU
                                                              : 0x1e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4007U
                                                              : 0xdU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1c31bU
                                                              : 0x1619bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x464U
                                                              : 0x20197U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x270050U
                                                              : 0x100e39bU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x291U
                                                              : 0x270050U))))
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
                                                              ? 0x100e39bU
                                                              : 0x211U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x31045cU
                                                              : 0x97U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10043U
                                                              : 0x1202fU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1411bU
                                                              : 0x34045cU)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x60117U
                                                              : 0x6007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4007U
                                                              : 0xdU))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xc31bU
                                                              : 0x3c323U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x58U
                                                              : 0x4000008U)))))
                                                         : 
                                                        ((0x10U 
                                                          & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                          ? 
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
                                                              ? 7U
                                                              : 0x1064U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10017U
                                                              : 0x4000008U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x1001bU
                                                              : 0x4000004U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x58U
                                                              : 0x311U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xc007U
                                                              : 0xffffe007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x110050U
                                                              : 0x464U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x10017U
                                                              : 0xeU)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0xffffe007U
                                                              : 0x100050U))))
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
                                                              ? 0x60050U
                                                              : 0x6d0054U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x3d0054U
                                                              : 0xa007U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x38007U
                                                              : 0xc20e007U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x28ac007U
                                                              : 0x1a0054U)))
                                                           : 
                                                          ((4U 
                                                            & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                            ? 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x160054U
                                                              : 0x110054U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x840054U
                                                              : 0x4020008U))
                                                            : 
                                                           ((2U 
                                                             & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                             ? 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x20100007U
                                                              : 0x4010008U)
                                                             : 
                                                            ((1U 
                                                              & (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                              ? 0x4000008U
                                                              : 7U))))))))))))))));
    vlTOPp->BUFFER_ADDRESS = vlTOPp->top__DOT__CONTROL__DOT__gpuAddReg;
    vlTOPp->B_OE = ((IData)(vlTOPp->top__DOT__gpuWrite) 
                    & (~ (IData)(vlTOPp->CLK)));
    vlTOPp->B_WR = (1U & (~ ((IData)(vlTOPp->top__DOT__gpuWrite) 
                             & (~ (IData)(vlTOPp->CLK)))));
    vlTOPp->OE = ((IData)(vlTOPp->top__DOT__ramWrite) 
                  & (~ (IData)(vlTOPp->CLK)));
    vlTOPp->WR = (1U & (~ (((IData)(vlTOPp->top__DOT__ramWrite) 
                            & (~ (IData)(vlTOPp->CLK))) 
                           & (~ ((((((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                     | (1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                    | (2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                   | (3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                  | (4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                 | (5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)))))));
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
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
    vlTOPp->B_UB = vlTOPp->B_WR;
    vlTOPp->B_LB = vlTOPp->B_WR;
    vlTOPp->UB = vlTOPp->WR;
    vlTOPp->LB = vlTOPp->WR;
    vlTOPp->top__DOT__bus = ((8U & (IData)(vlTOPp->top__DOT__busState))
                              ? 0U : ((4U & (IData)(vlTOPp->top__DOT__busState))
                                       ? ((2U & (IData)(vlTOPp->top__DOT__busState))
                                           ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__clkOut)
                                               : (IData)(vlTOPp->top__DOT__ctrlOut))
                                           : ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__apuOut)
                                               : (IData)(vlTOPp->BUFFER_DATA_IN)))
                                       : ((2U & (IData)(vlTOPp->top__DOT__busState))
                                           ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__DROM__DOT__ROMDATA__DOT__dintern)
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
    vlTOPp->BUFFER_DATA_OUT = vlTOPp->top__DOT__bus;
    vlTOPp->D6 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 6U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D7 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 7U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D8 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 8U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D9 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 9U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
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
    vlTOPp->top__DOT__ALU__DOT__combOperand2 = ((IData)(vlTOPp->top__DOT__aluReadBus)
                                                 ? (IData)(vlTOPp->top__DOT__bus)
                                                 : (IData)(vlTOPp->top__DOT__ALU__DOT__operand2));
    vlTOPp->top__DOT__ALU__DOT__lshift = ((8U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xe000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xdU))
                                                    : 
                                                   (0xf000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xfe00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 9U))
                                                    : 
                                                   (0xff00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xffe0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 5U))
                                                    : 
                                                   (0xfff0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xfffeU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
    vlTOPp->top__DOT__ALU__DOT__rshift = ((8U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xdU))
                                                    : 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0x7fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 9U))
                                                    : 
                                                   (0xffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0x7ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 5U))
                                                    : 
                                                   (0xfffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0x7fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
    vlTOPp->top__DOT__ALU__DOT__mult = (0x1ffffU & 
                                        ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                         * (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2)));
    vlTOPp->top__DOT__ALU__DOT__log = (0xffffU & ((1U 
                                                   & (((IData)(vlTOPp->top__DOT__aluParams) 
                                                       >> 1U) 
                                                      & (IData)(vlTOPp->top__DOT__aluParams)))
                                                   ? 
                                                  (~ (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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

VL_INLINE_OPT void Vtop::_combo__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->B_OE = ((IData)(vlTOPp->top__DOT__gpuWrite) 
                    & (~ (IData)(vlTOPp->CLK)));
    vlTOPp->B_WR = (1U & (~ ((IData)(vlTOPp->top__DOT__gpuWrite) 
                             & (~ (IData)(vlTOPp->CLK)))));
    vlTOPp->OE = ((IData)(vlTOPp->top__DOT__ramWrite) 
                  & (~ (IData)(vlTOPp->CLK)));
    vlTOPp->WR = (1U & (~ (((IData)(vlTOPp->top__DOT__ramWrite) 
                            & (~ (IData)(vlTOPp->CLK))) 
                           & (~ ((((((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                     | (1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                    | (2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                   | (3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                  | (4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                 | (5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)))))));
    vlTOPp->B_UB = vlTOPp->B_WR;
    vlTOPp->B_LB = vlTOPp->B_WR;
    vlTOPp->UB = vlTOPp->WR;
    vlTOPp->LB = vlTOPp->WR;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
}

VL_INLINE_OPT void Vtop::_combo__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__bus = ((8U & (IData)(vlTOPp->top__DOT__busState))
                              ? 0U : ((4U & (IData)(vlTOPp->top__DOT__busState))
                                       ? ((2U & (IData)(vlTOPp->top__DOT__busState))
                                           ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__clkOut)
                                               : (IData)(vlTOPp->top__DOT__ctrlOut))
                                           : ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__apuOut)
                                               : (IData)(vlTOPp->BUFFER_DATA_IN)))
                                       : ((2U & (IData)(vlTOPp->top__DOT__busState))
                                           ? ((1U & (IData)(vlTOPp->top__DOT__busState))
                                               ? (IData)(vlTOPp->top__DOT__DROM__DOT__ROMDATA__DOT__dintern)
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
    vlTOPp->BUFFER_DATA_OUT = vlTOPp->top__DOT__bus;
    vlTOPp->D6 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 6U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D7 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 7U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D8 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 8U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D9 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 9U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
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
    vlTOPp->top__DOT__ALU__DOT__combOperand2 = ((IData)(vlTOPp->top__DOT__aluReadBus)
                                                 ? (IData)(vlTOPp->top__DOT__bus)
                                                 : (IData)(vlTOPp->top__DOT__ALU__DOT__operand2));
    vlTOPp->top__DOT__ALU__DOT__lshift = ((8U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xe000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xdU))
                                                    : 
                                                   (0xf000U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xfe00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 9U))
                                                    : 
                                                   (0xff00U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xffe0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 5U))
                                                    : 
                                                   (0xfff0U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0xfffeU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       << 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
    vlTOPp->top__DOT__ALU__DOT__rshift = ((8U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (7U 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xdU))
                                                    : 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 0xcU))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0x7fU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 9U))
                                                    : 
                                                   (0xffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0x7ffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 5U))
                                                    : 
                                                   (0xfffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 4U))))
                                               : ((2U 
                                                   & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
                                                    & (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
                                                    ? 
                                                   (0x7fffU 
                                                    & ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                                       >> 1U))
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
    vlTOPp->top__DOT__ALU__DOT__mult = (0x1ffffU & 
                                        ((IData)(vlTOPp->top__DOT__ALU__DOT__operand1) 
                                         * (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2)));
    vlTOPp->top__DOT__ALU__DOT__log = (0xffffU & ((1U 
                                                   & (((IData)(vlTOPp->top__DOT__aluParams) 
                                                       >> 1U) 
                                                      & (IData)(vlTOPp->top__DOT__aluParams)))
                                                   ? 
                                                  (~ (IData)(vlTOPp->top__DOT__ALU__DOT__combOperand2))
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
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    if (((IData)(vlTOPp->CLK) ^ (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_multiclk__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    CLK = 0;
    RX = 0;
    TX = 0;
    GPIO3 = 0;
    GPIO9 = 0;
    GPIO11 = 0;
    CE = 0;
    OE = 0;
    WR = 0;
    UB = 0;
    LB = 0;
    A0 = 0;
    A1 = 0;
    A2 = 0;
    A3 = 0;
    A4 = 0;
    A5 = 0;
    A6 = 0;
    A7 = 0;
    A8 = 0;
    A9 = 0;
    A10 = 0;
    A11 = 0;
    A12 = 0;
    A13 = 0;
    A14 = 0;
    A15 = 0;
    D0 = 0;
    D1 = 0;
    D2 = 0;
    D3 = 0;
    D4 = 0;
    D5 = 0;
    D6 = 0;
    D7 = 0;
    D8 = 0;
    D9 = 0;
    D10 = 0;
    D11 = 0;
    D12 = 0;
    D13 = 0;
    D14 = 0;
    D15 = 0;
    D0_in = 0;
    D1_in = 0;
    D2_in = 0;
    D3_in = 0;
    D4_in = 0;
    D5_in = 0;
    D6_in = 0;
    D7_in = 0;
    D8_in = 0;
    D9_in = 0;
    D10_in = 0;
    D11_in = 0;
    D12_in = 0;
    D13_in = 0;
    D14_in = 0;
    D15_in = 0;
    BUFFER_DATA_IN = 0;
    BUFFER_DATA_OUT = 0;
    BUFFER_ADDRESS = 0;
    B_CE = 0;
    B_OE = 0;
    B_WR = 0;
    B_UB = 0;
    B_LB = 0;
    top__DOT__busState = 0;
    top__DOT__aluOperand1 = 0;
    top__DOT__aluOperand2 = 0;
    top__DOT__aluResults = 0;
    top__DOT__aluOperation = 0;
    top__DOT__aluParams = 0;
    top__DOT__aluReadBus = 0;
    top__DOT__ramWrite = 0;
    top__DOT__gpuWrite = 0;
    top__DOT__ctrlOut = 0;
    top__DOT__apuOut = 0;
    top__DOT__clkOut = 0;
    top__DOT__bus = 0;
    top__DOT__aluStatus = 0;
    top__DOT__clkdiv = 0;
    top__DOT__CONTROL__DOT__increment = 0;
    top__DOT__CONTROL__DOT__ramAddReg = 0;
    top__DOT__CONTROL__DOT__romAddReg = 0;
    top__DOT__CONTROL__DOT__gpuAddReg = 0;
    top__DOT__CONTROL__DOT__programCounter = 0;
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            top__DOT__CONTROL__DOT__addrstack[__Vi0] = 0;
    }}
    top__DOT__CONTROL__DOT__addrstackptr = 0;
    top__DOT__CONTROL__DOT__tempCounter = 0;
    top__DOT__PROM__DOT__ROMDATA__DOT__dintern = 0;
    top__DOT__DROM__DOT__ROMDATA__DOT__dintern = 0;
    top__DOT__ALU__DOT__a = 0;
    top__DOT__ALU__DOT__b = 0;
    top__DOT__ALU__DOT__c = 0;
    top__DOT__ALU__DOT__d = 0;
    top__DOT__ALU__DOT__e = 0;
    top__DOT__ALU__DOT__f = 0;
    top__DOT__ALU__DOT__g = 0;
    top__DOT__ALU__DOT__h = 0;
    top__DOT__ALU__DOT__addsub = 0;
    top__DOT__ALU__DOT__mult = 0;
    top__DOT__ALU__DOT__log = 0;
    top__DOT__ALU__DOT__lshift = 0;
    top__DOT__ALU__DOT__rshift = 0;
    top__DOT__ALU__DOT__operand1 = 0;
    top__DOT__ALU__DOT__operand2 = 0;
    top__DOT__ALU__DOT__combOperand2 = 0;
}
