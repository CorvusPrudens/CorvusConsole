// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->top__DOT__busState),4);
            tracep->chgCData(oldp+1,(vlTOPp->top__DOT__aluOperand1),3);
            tracep->chgCData(oldp+2,(vlTOPp->top__DOT__aluOperand2),3);
            tracep->chgCData(oldp+3,(vlTOPp->top__DOT__aluResults),3);
            tracep->chgCData(oldp+4,(vlTOPp->top__DOT__aluOperation),6);
            tracep->chgCData(oldp+5,(vlTOPp->top__DOT__aluParams),4);
            tracep->chgBit(oldp+6,(vlTOPp->top__DOT__aluReadBus));
            tracep->chgBit(oldp+7,(vlTOPp->top__DOT__ramWrite));
            tracep->chgSData(oldp+8,(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg),16);
            tracep->chgBit(oldp+9,((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
            tracep->chgBit(oldp+10,((3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
            tracep->chgBit(oldp+11,((1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
            tracep->chgBit(oldp+12,((2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
            tracep->chgBit(oldp+13,((4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
            tracep->chgBit(oldp+14,((5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))));
            tracep->chgCData(oldp+15,(vlTOPp->top__DOT__MEMstate),7);
            tracep->chgCData(oldp+16,(vlTOPp->top__DOT__CONTROL__DOT__increment),2);
            tracep->chgBit(oldp+17,(vlTOPp->top__DOT__CONTROL__DOT__ramAddMode));
            tracep->chgBit(oldp+18,(((((((0U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)) 
                                         | (1U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                        | (2U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                       | (3U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                      | (4U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg))) 
                                     | (5U == (IData)(vlTOPp->top__DOT__CONTROL__DOT__ramAddReg)))));
            tracep->chgBit(oldp+19,(vlTOPp->top__DOT____Vcellinp__UART__write));
            tracep->chgCData(oldp+20,(vlTOPp->top__DOT__UART__DOT__uartout),8);
            tracep->chgBit(oldp+21,(vlTOPp->top__DOT__UART__DOT__uartoutwrite));
            tracep->chgBit(oldp+22,((0U != (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))));
            tracep->chgCData(oldp+23,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0prev),8);
            tracep->chgCData(oldp+24,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxnprev),8);
            tracep->chgCData(oldp+25,(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc),3);
            tracep->chgBit(oldp+26,((1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__baudAcc) 
                                           >> 2U))));
            tracep->chgCData(oldp+27,(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate),4);
            tracep->chgBit(oldp+28,((0U == (IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXstate))));
            tracep->chgCData(oldp+29,(vlTOPp->top__DOT__UART__DOT__UART__DOT__TXshift),8);
            tracep->chgCData(oldp+30,(vlTOPp->top__DOT__UART__DOT__UART__DOT__RXstate),4);
            tracep->chgCData(oldp+31,(vlTOPp->top__DOT__UART__DOT__UART__DOT__gap),3);
            tracep->chgBit(oldp+32,((1U & ((IData)(vlTOPp->top__DOT__UART__DOT__UART__DOT__gap) 
                                           >> 2U))));
            tracep->chgCData(oldp+33,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0prev),8);
            tracep->chgCData(oldp+34,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxnprev),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgSData(oldp+35,(vlTOPp->top__DOT__ALU__DOT__g),16);
            tracep->chgSData(oldp+36,(vlTOPp->top__DOT__CONTROL__DOT__programCounter),16);
            tracep->chgSData(oldp+37,((0xffffU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                  >> 0x10U))),16);
            tracep->chgIData(oldp+38,(vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern),32);
            tracep->chgSData(oldp+39,((((IData)(vlTOPp->top__DOT__UART__DOT__empty) 
                                        << 9U) | ((
                                                   (1U 
                                                    == 
                                                    (0xffU 
                                                     & ((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                                        - (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn)))) 
                                                   << 8U) 
                                                  | (IData)(vlTOPp->top__DOT__UART__DOT__dataOutReg)))),16);
            tracep->chgBit(oldp+40,(vlTOPp->top__DOT__overflow));
            tracep->chgIData(oldp+41,(vlTOPp->top__DOT__clkdiv),25);
            tracep->chgSData(oldp+42,(vlTOPp->top__DOT__ALU__DOT__h),16);
            tracep->chgCData(oldp+43,((3U & vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern)),2);
            tracep->chgCData(oldp+44,((0x1fU & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                                >> 2U))),5);
            tracep->chgCData(oldp+45,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                             >> 7U))),3);
            tracep->chgCData(oldp+46,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xaU))),3);
            tracep->chgCData(oldp+47,((7U & (vlTOPp->top__DOT__ROM__DOT__ROMDATA__DOT__dintern 
                                             >> 0xdU))),3);
            tracep->chgSData(oldp+48,(vlTOPp->top__DOT__ALU__DOT__a),16);
            tracep->chgSData(oldp+49,(vlTOPp->top__DOT__ALU__DOT__b),16);
            tracep->chgSData(oldp+50,(vlTOPp->top__DOT__ALU__DOT__c),16);
            tracep->chgSData(oldp+51,(vlTOPp->top__DOT__ALU__DOT__d),16);
            tracep->chgSData(oldp+52,(vlTOPp->top__DOT__ALU__DOT__e),16);
            tracep->chgSData(oldp+53,(vlTOPp->top__DOT__ALU__DOT__f),16);
            tracep->chgCData(oldp+54,(vlTOPp->top__DOT__UART__DOT__dataOutReg),8);
            tracep->chgBit(oldp+55,(((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                     == (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn))));
            tracep->chgCData(oldp+56,(vlTOPp->top__DOT__UART__DOT__uartin),8);
            tracep->chgBit(oldp+57,((1U == (0xffU & 
                                            ((IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0) 
                                             - (IData)(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn))))));
            tracep->chgBit(oldp+58,((1U == (0xffU & 
                                            ((IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0) 
                                             - (IData)(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn))))));
            tracep->chgBit(oldp+59,(vlTOPp->top__DOT__UART__DOT__empty));
            tracep->chgBit(oldp+60,(vlTOPp->top__DOT__UART__DOT__sendState));
            tracep->chgBit(oldp+61,(vlTOPp->top__DOT__UART__DOT__sendRead));
            tracep->chgBit(oldp+62,(vlTOPp->top__DOT__UART__DOT__TXstart));
            tracep->chgCData(oldp+63,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idx0),8);
            tracep->chgCData(oldp+64,(vlTOPp->top__DOT__UART__DOT__INFIFO__DOT__idxn),8);
            tracep->chgCData(oldp+65,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idx0),8);
            tracep->chgCData(oldp+66,(vlTOPp->top__DOT__UART__DOT__OUTFIFO__DOT__idxn),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgSData(oldp+67,(vlTOPp->top__DOT__bus),16);
            tracep->chgSData(oldp+68,(vlTOPp->top__DOT__MEMbus),16);
            tracep->chgIData(oldp+69,(vlTOPp->top__DOT__ALU__DOT__addsub),17);
            tracep->chgIData(oldp+70,(vlTOPp->top__DOT__ALU__DOT__mult),17);
            tracep->chgSData(oldp+71,(vlTOPp->top__DOT__ALU__DOT__log),16);
            tracep->chgSData(oldp+72,(vlTOPp->top__DOT__ALU__DOT__combOperand2),16);
            tracep->chgCData(oldp+73,((0xffU & (IData)(vlTOPp->top__DOT__MEMbus))),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgSData(oldp+74,(vlTOPp->top__DOT__ALU__DOT__operand1),16);
            tracep->chgSData(oldp+75,(vlTOPp->top__DOT__ALU__DOT__lshift),16);
            tracep->chgSData(oldp+76,(vlTOPp->top__DOT__ALU__DOT__rshift),16);
            tracep->chgSData(oldp+77,(vlTOPp->top__DOT__ALU__DOT__operand2),16);
            tracep->chgBit(oldp+78,(vlTOPp->top__DOT__UART__DOT____Vcellinp__OUTFIFO__read));
        }
        tracep->chgBit(oldp+79,(vlTOPp->CLK));
        tracep->chgBit(oldp+80,(vlTOPp->RX));
        tracep->chgBit(oldp+81,(vlTOPp->TX));
        tracep->chgBit(oldp+82,(vlTOPp->GPIO3));
        tracep->chgBit(oldp+83,(vlTOPp->GPIO9));
        tracep->chgBit(oldp+84,(vlTOPp->GPIO11));
        tracep->chgBit(oldp+85,(vlTOPp->CE));
        tracep->chgBit(oldp+86,(vlTOPp->OE));
        tracep->chgBit(oldp+87,(vlTOPp->WR));
        tracep->chgBit(oldp+88,(vlTOPp->UB));
        tracep->chgBit(oldp+89,(vlTOPp->LB));
        tracep->chgBit(oldp+90,(vlTOPp->A0));
        tracep->chgBit(oldp+91,(vlTOPp->A1));
        tracep->chgBit(oldp+92,(vlTOPp->A2));
        tracep->chgBit(oldp+93,(vlTOPp->A3));
        tracep->chgBit(oldp+94,(vlTOPp->A4));
        tracep->chgBit(oldp+95,(vlTOPp->A5));
        tracep->chgBit(oldp+96,(vlTOPp->A6));
        tracep->chgBit(oldp+97,(vlTOPp->A7));
        tracep->chgBit(oldp+98,(vlTOPp->A8));
        tracep->chgBit(oldp+99,(vlTOPp->A9));
        tracep->chgBit(oldp+100,(vlTOPp->A10));
        tracep->chgBit(oldp+101,(vlTOPp->A11));
        tracep->chgBit(oldp+102,(vlTOPp->A12));
        tracep->chgBit(oldp+103,(vlTOPp->A13));
        tracep->chgBit(oldp+104,(vlTOPp->A14));
        tracep->chgBit(oldp+105,(vlTOPp->A15));
        tracep->chgBit(oldp+106,(vlTOPp->D0));
        tracep->chgBit(oldp+107,(vlTOPp->D1));
        tracep->chgBit(oldp+108,(vlTOPp->D2));
        tracep->chgBit(oldp+109,(vlTOPp->D3));
        tracep->chgBit(oldp+110,(vlTOPp->D4));
        tracep->chgBit(oldp+111,(vlTOPp->D5));
        tracep->chgBit(oldp+112,(vlTOPp->D6));
        tracep->chgBit(oldp+113,(vlTOPp->D7));
        tracep->chgBit(oldp+114,(vlTOPp->D8));
        tracep->chgBit(oldp+115,(vlTOPp->D9));
        tracep->chgBit(oldp+116,(vlTOPp->D10));
        tracep->chgBit(oldp+117,(vlTOPp->D11));
        tracep->chgBit(oldp+118,(vlTOPp->D12));
        tracep->chgBit(oldp+119,(vlTOPp->D13));
        tracep->chgBit(oldp+120,(vlTOPp->D14));
        tracep->chgBit(oldp+121,(vlTOPp->D15));
        tracep->chgBit(oldp+122,(vlTOPp->D0_in));
        tracep->chgBit(oldp+123,(vlTOPp->D1_in));
        tracep->chgBit(oldp+124,(vlTOPp->D2_in));
        tracep->chgBit(oldp+125,(vlTOPp->D3_in));
        tracep->chgBit(oldp+126,(vlTOPp->D4_in));
        tracep->chgBit(oldp+127,(vlTOPp->D5_in));
        tracep->chgBit(oldp+128,(vlTOPp->D6_in));
        tracep->chgBit(oldp+129,(vlTOPp->D7_in));
        tracep->chgBit(oldp+130,(vlTOPp->D8_in));
        tracep->chgBit(oldp+131,(vlTOPp->D9_in));
        tracep->chgBit(oldp+132,(vlTOPp->D10_in));
        tracep->chgBit(oldp+133,(vlTOPp->D11_in));
        tracep->chgBit(oldp+134,(vlTOPp->D12_in));
        tracep->chgBit(oldp+135,(vlTOPp->D13_in));
        tracep->chgBit(oldp+136,(vlTOPp->D14_in));
        tracep->chgBit(oldp+137,(vlTOPp->D15_in));
        tracep->chgSData(oldp+138,((((IData)(vlTOPp->D15_in) 
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
                                                                                | (IData)(vlTOPp->D0_in))))))))))))))))),16);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
    }
}
