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

int exponent(int input) {
  return (int)log2(input);
}

int charToIndex(char input, char* chars, int len){
  int ret = 0;
  for (int i = 0; i < len; i++){
    if (input == chars[i]){
      ret = i;
      break;
    }
  }
  return ret;
}

int equals(char* str1, char* str2) {
  int len1 = 0;
  int len2 = 0;
  while (str1[len1++] != 0);
  while (str2[len2++] != 0);

  if (len1 != len2) {
    return false;
  }
  for (int i = 0; i < len1; i++) {
    if (str1[i] != str2[i] && str1[i] + 32 != str2[i]) {
      return false;
    }
  }
  return true;
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
  char inputChar;

  int testState = 0;

  for (int i = 0; i < 3; i++){
    tick(tb, tfp, ++logicStep);
  }

  int out = 0;
  int data[6] = {0};
  int inbuff[2] = {0};
  char inputString[6] = {0};

  char instCap[32][5] = {
    "NOP", "LDR", "STR", "ADD",
    "SUB", "MUL", "DIV", "MOD",
    "LDI", "ADI", "SBI", "MLI",
    "DVI", "MDI", "AND", "OR",
    "XOR", "NOT", "ANI", "ORI",
    "XRI", "LSL", "LSR", "PSH",
    "POP", "PEK", "JMP", "JZ",
    "JC",  "JSR", "RTS"
  };

  char regCap[8][2] = {
    "A", "B", "C", "D",
    "E", "F", "G", "H"
  };

  beginloop:
  printf("Instruction:\n");
  scanf("%s", &inputString);
  int match = 0;
  int instr = 0;
  for (int i = 0; i < 32; i++){
    if (equals(instCap[i], inputString)) {
      instr = i;
      match = 1;
      break;
    }
  }
  if (match == 0){
    printf("Please provide a valid opcode!\n");
    goto beginloop;
  }
  data[0] = instr*2;

  arg1loop:
  printf("Argument 1:\n");
  scanf("%s", inputString);
  int reg = 0;
  match = 0;
  for (int i = 0; i < 32; i++){
    if (equals(regCap[i], inputString)) {
      reg = i;
      match = 1;
      break;
    }
  }
  if (match == 0){
    printf("Please provide a valid register!\n");
    goto arg1loop;
  }
  data[1] = reg;
  int isNum = 0;

  arg2loop:

  printf("Argument 2:\n");
  scanf("%s", inputString);
  reg = 0;
  match = 0;
  if (inputString[0] > 47 && inputString[0] < 58) {
    isNum = true;
  }
  if (isNum) {
    data[2] = atoi(inputString);
  } else {
    for (int i = 0; i < 32; i++){
      if (equals(regCap[i], inputString)) {
        reg = i;
        match = 1;
        break;
      }
    }
    data[2] = reg;
  }

  printf("Results destination:\n");
  scanf("%s", inputString);
  reg = 0;
  match = 0;
  if (inputString[0] > 47 && inputString[0] < 58) {
    isNum = true;
  }
  if (isNum) {
    data[3] = atoi(inputString);
  } else {
    for (int i = 0; i < 32; i++){
      if (equals(regCap[i], inputString)) {
        reg = i;
        match = 1;
        break;
      }
    }
    data[3] = reg;
  }

  printf("Word 2 data:\n");
  scanf("%d", &input);
  data[4] = input;



  // int out = 0;
  // int data[9] = {0};
  // int inbuff[20] = {0};
  // int innum = 0;
  //
  // printf("ALU mode (1 = add/sub, 2 = mult, 4 = logic, 8 = lshift, 16 = rshift)\n");
  // scanf("%d", &input);
  // data[0] = input & 255;
  //
  // char strs[5][40] = {
  //   "0 = add, 1 = sub\n",
  //   "0 = mult, 1 = div (TODO)\n",
  //   "0 = AND, 1 = OR, 2 = XOR, 3 = NOT\n",
  //   "register << param\n",
  //   "register >> param\n"
  // };
  //
  // char registers[8] = {
  //   'a',
  //   'b',
  //   'c',
  //   'd',
  //   'e',
  //   'f',
  //   'g',
  //   'h'
  // };

  // printf("Opertion param\n");
  // printf("%s", strs[exponent(data[0])]);
  // scanf("%d", &input);
  // data[1] = input & 255;
  //
  // printf("Operand 1\n");
  // scanf("%s", &inputChar);
  // data[2] = charToIndex(inputChar, registers, 8);
  //
  // printf("Operand 2\n");
  // scanf("%s", &inputChar);
  // data[3] = charToIndex(inputChar, registers, 8);
  //
  // printf("Results register\n");
  // scanf("%s", &inputChar);
  // data[4] = charToIndex(inputChar, registers, 8);
  //
  // printf("Value 1\n");
  // scanf("%d", &input);
  // data[5] = input & 255;
  // data[6] = input >> 8;
  //
  // printf("Value 2\n");
  // scanf("%d", &input);
  // data[7] = input & 255;
  // data[8] = input >> 8;
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
  //     if (sendState == 6){
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
