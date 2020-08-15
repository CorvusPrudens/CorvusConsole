#include <stdio.h>
#include <stdlib.h>
#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#define CYCLE_REDUCTION 1024
#define CLOCK_NS (1000.0/12.0)*10.0 // 12 MHz to period w/ 100ps precision

int uart(Vtop *tb, int tr, int send, int* rec) {
  // 3 Mbaud uart
  static int transmitTick = 0;
  static int recieveTick = 0;
  static int recieveState = 0;
  static int transmitState = 0;
  static int transmitting = 0;
  static int recieving = 0;
  int just_recieved = 0;
  int just_sent = 0;

  if (tr == 1){
    transmitting = 1;
  }

  if (transmitting){
    if (transmitTick++ == 3){
      transmitTick = 0;

      if (transmitState == 0) {
        tb->RX = 0;
        transmitState++;
      } else if (transmitState == 9) {
        tb->RX = 1;
        transmitState = 0;
        transmitting = 0;
        just_sent = 1;
      }else {
        tb->RX = (send >> (transmitState - 1)) & 1;
        transmitState++;
      }
    }
  }


  if (!recieving && tb->TX == 0){
    recieving = 1;
    *rec = 0;
  }
  if (recieving){
    if (recieveTick++ == 3){
      recieveTick = 0;
      if (recieveState < 9 && recieveState > 0){
        *rec |= (tb->TX == 1) << (recieveState - 1);
        recieveState++;
      }else if (recieveState == 9){
        recieveState = 0;
        recieving = 0;
        just_recieved = 1;
      }else{
        recieveState++;
      }
    }
  }

  return transmitting | (just_recieved << 1) | (just_sent << 2);
}

// This tick assumes positive edge clocking only!!
void tick(Vtop *tb, VerilatedVcdC *tfp, unsigned logicStep) {
  tb->eval();
  if (tfp) tfp->dump(logicStep * CLOCK_NS - CLOCK_NS*0.2);
  tb->CLK = 1;
  tb->eval();
  if (tfp) tfp->dump(logicStep * CLOCK_NS);
  tb->CLK = 0;
  tb->eval();
  if (tfp){
    tfp->dump(logicStep * CLOCK_NS + CLOCK_NS*0.5);
    tfp->flush();
  }
}

void init(Vtop *tb){
  static int toggle = 0;
  if (!toggle) {
    tb->RX = 1;
    toggle = 1;
  }
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  Vtop *tb = new Vtop;
  VerilatedVcdC* tfp = new VerilatedVcdC;
  tb->trace(tfp, 99);
  tfp->open("trace.vcd");

  init(tb);
  unsigned logicStep = 0;
  int prevVal = 0;
  int input = 0;

  int testState = 0;

  for (int i = 0; i < 128; i++){
    tick(tb, tfp, ++logicStep);
  }

  // for (int i = 0; i < 200; i++){
  //
  //   tick(tb, tfp, ++logicStep);
  //
  //
  // }
  // int out = 0;
  // int data[6] = {0};
  // int inbuff[20] = {0};
  // int innum = 0;
  //
  // printf("ALU mode (0 = add, 1 = sub, 2 = mult)\n");
  // scanf("%d", &input);
  // data[0] = input & 255;
  //
  // printf("Value 1\n");
  // scanf("%d", &input);
  // data[1] = input & 255;
  // data[2] = input >> 8;
  //
  // printf("Value 2\n");
  // scanf("%d", &input);
  // data[3] = input & 255;
  // data[4] = input >> 8;
  //
  // int sendState = 0;
  // int go = 1;
  //
  // //initialization tick
  // tick(tb, tfp, ++logicStep);
  // // Shouldn't need more than 10000 cycles
  // while (logicStep < 10000){
  //   int status = uart(tb, go, data[sendState], &out);
  //   tick(tb, tfp, ++logicStep);
  //   if ((status & 4) > 0){
  //     sendState++;
  //     if (sendState == 5){
  //       go = 0;
  //       //sendState = 0;
  //     }
  //   }
  //   if ((status & 2) > 0){
  //     inbuff[innum] = out;
  //     innum += 1;
  //     if (innum == 3){
  //       break;
  //     }
  //   }
  // }
  //
  // printf("Recieved: %d, flag: %d\n", inbuff[0] | (inbuff[1] << 8), inbuff[2]);
}
