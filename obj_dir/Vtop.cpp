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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog/top.v", 13, "",
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
            VL_FATAL_MT("verilog/top.v", 13, "",
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
    vlTOPp->top__DOT__RXready = 0U;
    vlTOPp->top__DOT__aluParams = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand2 = 0U;
    vlTOPp->top__DOT__aluOperand2 = 0U;
    vlTOPp->top__DOT__ramWrite = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 0U;
    vlTOPp->top__DOT__busState = 0U;
    vlTOPp->top__DOT__ALU__DOT__operand1 = 0U;
    vlTOPp->top__DOT__aluOperand1 = 0U;
    vlTOPp->top__DOT__ALU__DOT__b = 0U;
    vlTOPp->top__DOT__ALU__DOT__c = 0U;
    vlTOPp->top__DOT__ALU__DOT__d = 0U;
    vlTOPp->top__DOT__ALU__DOT__e = 0U;
    vlTOPp->top__DOT__ALU__DOT__f = 0U;
    vlTOPp->top__DOT__ALU__DOT__h = 0U;
    vlTOPp->top__DOT__ALU__DOT__g = 0U;
    vlTOPp->top__DOT__testClock = 1U;
    vlTOPp->top__DOT__TXbuffer = 0U;
    vlTOPp->top__DOT__TXstart = 0U;
    vlTOPp->top__DOT__FTDI__DOT__RXstate = 0U;
    vlTOPp->top__DOT__clkdiv = 0U;
    vlTOPp->top__DOT__FTDI__DOT__baudAcc = 0U;
    vlTOPp->top__DOT__FTDI__DOT__gap = 0U;
    vlTOPp->top__DOT__FTDI__DOT__TXshift = 0U;
    vlTOPp->top__DOT__RXbuffer = 0U;
    vlTOPp->top__DOT__testState = 0U;
    vlTOPp->top__DOT__FTDI__DOT__TXstate = 0U;
    vlTOPp->top__DOT__ALU__DOT__a = 2U;
    vlTOPp->top__DOT__aluResults = 0U;
    vlTOPp->top__DOT__aluOperation = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__increment = 0U;
    vlTOPp->top__DOT__overflow = 0U;
    vlTOPp->top__DOT__aluReadBus = 0U;
    vlTOPp->top__DOT__bus = 0U;
    vlTOPp->top__DOT__CONTROL__DOT__programCounter = 0U;
    vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern = 0U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__top__DOT__testState;
    // Body
    __Vdly__top__DOT__testState = vlTOPp->top__DOT__testState;
    vlTOPp->top__DOT__clkdiv = (0x1ffffffU & ((IData)(1U) 
                                              + vlTOPp->top__DOT__clkdiv));
    if ((0U == (IData)(vlTOPp->top__DOT__testState))) {
        vlTOPp->top__DOT__TXstart = 0U;
        if ((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
            vlTOPp->top__DOT__testClock = 0U;
            __Vdly__top__DOT__testState = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->top__DOT__testState))) {
            vlTOPp->top__DOT__testClock = 1U;
            vlTOPp->top__DOT__TXbuffer = (0xffU & (IData)(vlTOPp->top__DOT__ALU__DOT__a));
            vlTOPp->top__DOT__TXstart = 1U;
            __Vdly__top__DOT__testState = 2U;
        } else {
            if ((2U == (IData)(vlTOPp->top__DOT__testState))) {
                vlTOPp->top__DOT__TXstart = 0U;
                if ((0U == (IData)(vlTOPp->top__DOT__FTDI__DOT__TXstate))) {
                    vlTOPp->top__DOT__TXbuffer = (0xffU 
                                                  & ((IData)(vlTOPp->top__DOT__ALU__DOT__a) 
                                                     >> 8U));
                    vlTOPp->top__DOT__TXstart = 1U;
                    __Vdly__top__DOT__testState = 0U;
                }
            } else {
                __Vdly__top__DOT__testState = 0U;
            }
        }
    }
    vlTOPp->top__DOT__testState = __Vdly__top__DOT__testState;
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OE = ((IData)(vlTOPp->top__DOT__ramWrite) 
                  & (~ (IData)(vlTOPp->top__DOT__testClock)));
    vlTOPp->WR = (1U & (~ ((IData)(vlTOPp->top__DOT__ramWrite) 
                           & (~ (IData)(vlTOPp->top__DOT__testClock)))));
    vlTOPp->GPIO3 = (1U & (vlTOPp->top__DOT__clkdiv 
                           >> 0x17U));
    vlTOPp->top__DOT__FTDI__DOT__baudTick = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__baudAcc) 
                                                   >> 2U));
    vlTOPp->top__DOT__FTDI__DOT__nextBit = (1U & ((IData)(vlTOPp->top__DOT__FTDI__DOT__gap) 
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
    vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
        = ((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
            ? 0x10006U : ((1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                           ? 0x2006U : ((2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                         ? 0x4006U : 
                                        ((3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                          ? 0x401aU
                                          : ((4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                              ? 0x418U
                                              : ((5U 
                                                  == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                  ? 0x211aU
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                   ? 0x30050U
                                                   : 0U)))))));
    vlTOPp->UB = vlTOPp->WR;
    vlTOPp->LB = vlTOPp->WR;
    vlTOPp->top__DOT__ALU__DOT__lshift = ((8U & (IData)(vlTOPp->top__DOT__aluParams))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                       << 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
    vlTOPp->top__DOT__ALU__DOT__rshift = ((8U & (IData)(vlTOPp->top__DOT__aluParams))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                       >> 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
    vlTOPp->top__DOT__ramAddress = (0xffffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode)
                                                ? (IData)(vlTOPp->top__DOT__ALU__DOT__g)
                                                : (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 0x10U)));
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
                                                 (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
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
    vlTOPp->D4 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 4U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D5 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 5U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
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

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__aluOperation = (0x1fU 
                                              & (IData)(vlTOPp->top__DOT__aluOperation));
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__aluOperation = (0x1fU 
                                                  & (IData)(vlTOPp->top__DOT__aluOperation));
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperation 
                        = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x30U;
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
                                                    ? 0x28U
                                                    : 0x24U)
                                                   : 0x24U);
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation = 0x24U;
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0x22U;
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__aluOperation = 0x21U;
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluOperation 
                                = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluOperation 
                                = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                        }
                    } else {
                        vlTOPp->top__DOT__aluOperation = 0U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__aluOperation = 0x20U;
                        }
                    } else {
                        vlTOPp->top__DOT__aluOperation 
                            = (0x1fU & (IData)(vlTOPp->top__DOT__aluOperation));
                    }
                }
            }
        }
    }
    if ((0x40U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
            vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 3U;
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    }
                }
            }
        } else {
            if ((0x10U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    } else {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
                        vlTOPp->top__DOT__CONTROL__DOT__increment = 2U;
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
                        vlTOPp->top__DOT__aluReadBus = 0U;
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
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 1U;
                        }
                    }
                }
            } else {
                if ((8U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 1U;
                        }
                    } else {
                        vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 0U;
                    }
                } else {
                    if ((4U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)) {
                        if ((1U & (~ vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern))) {
                            vlTOPp->top__DOT__CONTROL__DOT__ramAddMode = 0U;
                        }
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
                                                   ? 0U
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
                    if ((1U & (~ (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 2U)))) {
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
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__overflow;
    SData/*15:0*/ __Vdly__top__DOT__CONTROL__DOT__programCounter;
    // Body
    __Vdly__top__DOT__overflow = vlTOPp->top__DOT__overflow;
    __Vdly__top__DOT__CONTROL__DOT__programCounter 
        = vlTOPp->top__DOT__CONTROL__DOT__programCounter;
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
    if ((2U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
        if ((1U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
            if ((1U & (IData)(vlTOPp->top__DOT__CONTROL__DOT__increment))) {
                __Vdly__top__DOT__CONTROL__DOT__programCounter 
                    = (0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                  >> 0x10U));
            }
        } else {
            __Vdly__top__DOT__CONTROL__DOT__programCounter 
                = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter)));
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
    vlTOPp->top__DOT__overflow = __Vdly__top__DOT__overflow;
    vlTOPp->top__DOT__CONTROL__DOT__programCounter 
        = __Vdly__top__DOT__CONTROL__DOT__programCounter;
    vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
        = ((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
            ? 0x10006U : ((1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                           ? 0x2006U : ((2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                         ? 0x4006U : 
                                        ((3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                          ? 0x401aU
                                          : ((4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                              ? 0x418U
                                              : ((5U 
                                                  == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                  ? 0x211aU
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlTOPp->top__DOT__CONTROL__DOT__programCounter))
                                                   ? 0x30050U
                                                   : 0U)))))));
}

VL_INLINE_OPT void Vtop::_combo__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OE = ((IData)(vlTOPp->top__DOT__ramWrite) 
                  & (~ (IData)(vlTOPp->top__DOT__testClock)));
    vlTOPp->WR = (1U & (~ ((IData)(vlTOPp->top__DOT__ramWrite) 
                           & (~ (IData)(vlTOPp->top__DOT__testClock)))));
    vlTOPp->UB = vlTOPp->WR;
    vlTOPp->LB = vlTOPp->WR;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__8\n"); );
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
    vlTOPp->top__DOT__ramAddress = (0xffffU & ((IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode)
                                                ? (IData)(vlTOPp->top__DOT__ALU__DOT__g)
                                                : (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                   >> 0x10U)));
    vlTOPp->top__DOT__ALU__DOT__lshift = ((8U & (IData)(vlTOPp->top__DOT__aluParams))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                       << 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
    vlTOPp->top__DOT__ALU__DOT__rshift = ((8U & (IData)(vlTOPp->top__DOT__aluParams))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                       >> 8U)))))
                                           : ((4U & (IData)(vlTOPp->top__DOT__aluParams))
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
                                                    : (IData)(vlTOPp->top__DOT__ALU__DOT__operand1)))));
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

VL_INLINE_OPT void Vtop::_combo__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__9\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
                                                 (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
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
    vlTOPp->D4 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 4U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
    vlTOPp->D5 = (((((IData)(vlTOPp->top__DOT__ramWrite) 
                     & ((IData)(vlTOPp->top__DOT__bus) 
                        >> 5U)) & (IData)(vlTOPp->top__DOT__ramWrite)) 
                   & (IData)(vlTOPp->top__DOT__ramWrite)) 
                  & (IData)(vlTOPp->top__DOT__ramWrite));
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
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock)) 
         & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__testClock) 
         ^ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock))) {
        vlTOPp->_multiclk__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x40U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__9(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock 
        = vlTOPp->__VinpClk__TOP__top__DOT__testClock;
    vlTOPp->__VinpClk__TOP__top__DOT__testClock = vlTOPp->top__DOT__testClock;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__testClock 
        = vlTOPp->__VinpClk__TOP__top__DOT__testClock;
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
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->top__DOT__testClock ^ vlTOPp->__Vchglast__TOP__top__DOT__testClock));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__testClock ^ vlTOPp->__Vchglast__TOP__top__DOT__testClock))) VL_DBG_MSGF("        CHANGE: verilog/top.v:84: top.testClock\n"); );
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
    top__DOT__RXbuffer = VL_RAND_RESET_I(8);
    top__DOT__TXbuffer = VL_RAND_RESET_I(8);
    top__DOT__TXstart = VL_RAND_RESET_I(1);
    top__DOT__RXready = VL_RAND_RESET_I(1);
    top__DOT__testClock = VL_RAND_RESET_I(1);
    top__DOT__busState = VL_RAND_RESET_I(4);
    top__DOT__aluOperand1 = VL_RAND_RESET_I(3);
    top__DOT__aluOperand2 = VL_RAND_RESET_I(3);
    top__DOT__aluResults = VL_RAND_RESET_I(3);
    top__DOT__aluOperation = VL_RAND_RESET_I(6);
    top__DOT__aluParams = VL_RAND_RESET_I(4);
    top__DOT__aluReadBus = VL_RAND_RESET_I(1);
    top__DOT__ramWrite = VL_RAND_RESET_I(1);
    top__DOT__hreg = VL_RAND_RESET_I(16);
    top__DOT__ramAddress = VL_RAND_RESET_I(16);
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
    top__DOT__CONTROL__DOT__increment = VL_RAND_RESET_I(2);
    top__DOT__CONTROL__DOT__ramAddMode = VL_RAND_RESET_I(1);
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
    __VinpClk__TOP__top__DOT__testClock = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__testClock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
