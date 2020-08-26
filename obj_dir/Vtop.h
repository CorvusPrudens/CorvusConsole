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
    VL_OUT8(CE,0,0);
    VL_OUT8(OE,0,0);
    VL_OUT8(WR,0,0);
    VL_OUT8(UB,0,0);
    VL_OUT8(LB,0,0);
    VL_OUT8(A0,0,0);
    VL_OUT8(A1,0,0);
    VL_OUT8(A2,0,0);
    VL_OUT8(A3,0,0);
    VL_OUT8(A4,0,0);
    VL_OUT8(A5,0,0);
    VL_OUT8(A6,0,0);
    VL_OUT8(A7,0,0);
    VL_OUT8(A8,0,0);
    VL_OUT8(A9,0,0);
    VL_OUT8(A10,0,0);
    VL_OUT8(A11,0,0);
    VL_OUT8(A12,0,0);
    VL_OUT8(A13,0,0);
    VL_OUT8(A14,0,0);
    VL_OUT8(A15,0,0);
    VL_OUT8(D0,0,0);
    VL_OUT8(D1,0,0);
    VL_OUT8(D2,0,0);
    VL_OUT8(D3,0,0);
    VL_OUT8(D4,0,0);
    VL_OUT8(D5,0,0);
    VL_OUT8(D6,0,0);
    VL_OUT8(D7,0,0);
    VL_OUT8(D8,0,0);
    VL_OUT8(D9,0,0);
    VL_OUT8(D10,0,0);
    VL_OUT8(D11,0,0);
    VL_OUT8(D12,0,0);
    VL_OUT8(D13,0,0);
    VL_OUT8(D14,0,0);
    VL_OUT8(D15,0,0);
    VL_IN8(D0_in,0,0);
    VL_IN8(D1_in,0,0);
    VL_IN8(D2_in,0,0);
    VL_IN8(D3_in,0,0);
    VL_IN8(D4_in,0,0);
    VL_IN8(D5_in,0,0);
    VL_IN8(D6_in,0,0);
    VL_IN8(D7_in,0,0);
    VL_IN8(D8_in,0,0);
    VL_IN8(D9_in,0,0);
    VL_IN8(D10_in,0,0);
    VL_IN8(D11_in,0,0);
    VL_IN8(D12_in,0,0);
    VL_IN8(D13_in,0,0);
    VL_IN8(D14_in,0,0);
    VL_IN8(D15_in,0,0);
    
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
    CData/*0:0*/ top__DOT__ramWrite;
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
    CData/*1:0*/ top__DOT__CONTROL__DOT__increment;
    CData/*0:0*/ top__DOT__CONTROL__DOT__ramAddMode;
    SData/*15:0*/ top__DOT__hreg;
    SData/*15:0*/ top__DOT__ramAddress;
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
    IData/*24:0*/ top__DOT__clkdiv;
    IData/*31:0*/ top__DOT__ROM__DOT__ROMDATA__DOT__dintern;
    IData/*16:0*/ top__DOT__ALU__DOT__addsub;
    IData/*16:0*/ top__DOT__ALU__DOT__mult;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __VinpClk__TOP__top__DOT__testClock;
    CData/*0:0*/ __Vclklast__TOP__CLK;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__testClock;
    CData/*0:0*/ __Vchglast__TOP__top__DOT__testClock;
    IData/*31:0*/ __Vm_traceActivity;
    
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
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__9(Vtop__Syms* __restrict vlSymsp);
  private:
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
    static void _multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
