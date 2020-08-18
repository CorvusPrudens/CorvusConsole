// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(RX,0,0);
    VL_OUT8(TX,0,0);
    VL_OUT8(GPIO3,0,0);
    VL_OUT8(GPIO9,0,0);
    VL_OUT8(GPIO11,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top__DOT__testClock;
    CData/*7:0*/ top__DOT__RXbuffer;
    CData/*7:0*/ top__DOT__TXbuffer;
    CData/*0:0*/ top__DOT__TXstart;
    CData/*0:0*/ top__DOT__RXready;
    CData/*3:0*/ top__DOT__busState;
    CData/*2:0*/ top__DOT__aluOperand1;
    CData/*2:0*/ top__DOT__aluOperand2;
    CData/*2:0*/ top__DOT__aluResults;
    CData/*5:0*/ top__DOT__aluOperation;
    CData/*3:0*/ top__DOT__aluParams;
    CData/*0:0*/ top__DOT__aluReadBus;
    CData/*0:0*/ top__DOT__overflow;
    CData/*3:0*/ top__DOT__testState;
    CData/*2:0*/ top__DOT__FTDI__DOT__baudAcc;
    CData/*0:0*/ top__DOT__FTDI__DOT__baudTick;
    CData/*3:0*/ top__DOT__FTDI__DOT__TXstate;
    CData/*0:0*/ top__DOT__FTDI__DOT__TXready;
    CData/*7:0*/ top__DOT__FTDI__DOT__TXshift;
    CData/*3:0*/ top__DOT__FTDI__DOT__RXstate;
    CData/*2:0*/ top__DOT__FTDI__DOT__gap;
    CData/*0:0*/ top__DOT__FTDI__DOT__nextBit;
    CData/*0:0*/ top__DOT__CONTROL__DOT__increment;
    SData/*15:0*/ top__DOT__hreg;
    SData/*15:0*/ top__DOT__romAddress;
    SData/*15:0*/ top__DOT__ramOut;
    SData/*15:0*/ top__DOT__romOut;
    SData/*15:0*/ top__DOT__gpuOut;
    SData/*15:0*/ top__DOT__apuOut;
    SData/*15:0*/ top__DOT__clkOut;
    SData/*15:0*/ top__DOT__bus;
    SData/*15:0*/ top__DOT__din;
    SData/*15:0*/ top__DOT__dout;
    SData/*15:0*/ top__DOT__CONTROL__DOT__programCounter;
    SData/*15:0*/ top__DOT__ALU__DOT__a;
    SData/*15:0*/ top__DOT__ALU__DOT__b;
    SData/*15:0*/ top__DOT__ALU__DOT__c;
    SData/*15:0*/ top__DOT__ALU__DOT__d;
    SData/*15:0*/ top__DOT__ALU__DOT__e;
    SData/*15:0*/ top__DOT__ALU__DOT__f;
    SData/*15:0*/ top__DOT__ALU__DOT__g;
    SData/*15:0*/ top__DOT__ALU__DOT__h;
    SData/*15:0*/ top__DOT__ALU__DOT__log;
    SData/*15:0*/ top__DOT__ALU__DOT__lshift;
    SData/*15:0*/ top__DOT__ALU__DOT__rshift;
    SData/*15:0*/ top__DOT__ALU__DOT__operand1;
    SData/*15:0*/ top__DOT__ALU__DOT__operand2;
    SData/*15:0*/ top__DOT__ALU__DOT__combOperand2;
    IData/*31:0*/ top__DOT__testWord;
    IData/*24:0*/ top__DOT__clkdiv;
    IData/*16:0*/ top__DOT__ALU__DOT__addsub;
    IData/*16:0*/ top__DOT__ALU__DOT__mult;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __VinpClk__TOP__top__DOT__testClock;
    CData/*0:0*/ __Vclklast__TOP__CLK;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__testClock;
    CData/*0:0*/ __Vchglast__TOP__top__DOT__testClock;
    CData/*0:0*/ __Vm_traceActivity[7];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
