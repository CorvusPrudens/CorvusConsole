#include <stdio.h>
#include <stdlib.h>
#include <vector>

// We need to use openGL directly to avoid
// this library's costly overhead
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Graphics.hpp>

# include <ctime>

#ifdef THREAD
# include <atomic>
# include <thread>
#include "verilated_threads.h"
#endif

#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"


#define CYCLE_REDUCTION 1024
#define CLOCK_NS (1000.0/12.0)*10.0 // 12 MHz to period w/ 100ps precision
#define SCALE 5
#define WIDTH 240
#define HEIGHT 135
#define XOFFSET 8
#define YOFFSET 8
#define COLOR_TABLE (153 << 8)
#define CLOCKS_PER_FRAME 10000

void updatePixels(uint16_t* framebuffer, sf::RenderWindow* window){
  sf::RectangleShape pixel(sf::Vector2f(SCALE, SCALE));
  for (int y = 0; y < HEIGHT; y++){
    for (int x = 0; x < WIDTH; x++){
      int index = framebuffer[(x + 8) + (y + 8)*(WIDTH + 16)]*2;
      int colLSB = framebuffer[index + COLOR_TABLE];
      int colMSB = framebuffer[index + COLOR_TABLE + 1];
      pixel.setFillColor(
        sf::Color(colLSB & 255, (colLSB >> 8) & 255, (colMSB >> 0) & 255)
      );
      pixel.setPosition(x*SCALE, y*SCALE);
      window->draw(pixel);
      // if (framebuffer[(x + 8) + (y + 8)*(WIDTH + 16)] != 0){
      //   pixel.setFillColor(sf::Color(255, 255, 255));
      //   pixel.setPosition(x*SCALE, y*SCALE);
      //   window->draw(pixel);
      // }
    }
  }
}

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

int ram(uint16_t* buff, int address, int data, int write) {
  if (write == 0){
    buff[address] = data;
    return -1;
  }
  return buff[address];
}

int getAddress(Vtop *tb){
  return tb->A0 | (tb->A1 << 1) | (tb->A2 << 2) | (tb->A3 << 3) |
        (tb->A4 << 4) | (tb->A5 << 5) | (tb->A6 << 6) | (tb->A7 << 7) |
        (tb->A8 << 8) | (tb->A9 << 9) | (tb->A10 << 10) | (tb->A11 << 11) |
        (tb->A12 << 12) | (tb->A13 << 13) | (tb->A14 << 14) | (tb->A15 << 15);
}
int getData(Vtop *tb) {
  return tb->D0 | (tb->D1 << 1) | (tb->D2 << 2) | (tb->D3 << 3) |
         (tb->D4 << 4) | (tb->D5 << 5) | (tb->D6 << 6) | (tb->D7 << 7) |
         (tb->D8 << 8) | (tb->D9 << 9) | (tb->D10 << 10) | (tb->D11 << 11) |
         (tb->D12 << 12) | (tb->D13 << 13) | (tb->D14 << 14) | (tb->D15 << 15);
}
void setData(Vtop *tb, int out) {
  if (out != -1) {
    tb->D0_in = (out & 1) > 0;
    tb->D1_in = (out & 2) > 0;
    tb->D2_in = (out & 4) > 0;
    tb->D3_in = (out & 8) > 0;
    tb->D4_in = (out & 16) > 0;
    tb->D5_in = (out & 32) > 0;
    tb->D6_in = (out & 64) > 0;
    tb->D7_in = (out & 128) > 0;
    tb->D8_in = (out & 256) > 0;
    tb->D9_in = (out & 512) > 0;
    tb->D10_in = (out & 1024) > 0;
    tb->D11_in = (out & 2048) > 0;
    tb->D12_in = (out & 4096) > 0;
    tb->D13_in = (out & 8192) > 0;
    tb->D14_in = (out & 16384) > 0;
    tb->D15_in = (out & 32768) > 0;
  }
}

int getGpuAddress(Vtop* tb){
  return tb->BUFFER_ADDRESS;
}
int getGpuData(Vtop* tb) {
  return tb->BUFFER_DATA_OUT;
}
void setGpuData(Vtop* tb, int out) {
  tb->BUFFER_DATA_IN = out & 65535;
}

int gpu(uint16_t* buff, int address, int data, int write) {
  if (write == 0){
    // printf("WROTE %d", data);
    buff[address] = data;
    return -1;
  }
  return buff[address];
}

// This tick assumes positive edge clocking only!!
void tick(Vtop *tb, VerilatedVcdC *tfp, unsigned logicStep, uint16_t* buff, uint16_t* gpubuff) {
  tb->eval();

  #ifdef TRACE
    if (tfp) tfp->dump(logicStep * CLOCK_NS - CLOCK_NS*0.2);
  #endif

  tb->CLK = 1;
  tb->eval();

  int address = getAddress(tb);
  int data = getData(tb);
  int out = ram(buff, address, data, tb->WR);
  setData(tb, out);

  address = getGpuAddress(tb);
  data = getGpuData(tb);
  out = gpu(gpubuff, address, data, tb->B_WR);
  setGpuData(tb, out);

  #ifdef TRACE
    if (tfp) tfp->dump(logicStep * CLOCK_NS);
  #endif
  tb->CLK = 0;
  tb->eval();

  address = getAddress(tb);
  data = getData(tb);
  out = ram(buff, address, data, tb->WR);
  setData(tb, out);

  address = getGpuAddress(tb);
  data = getGpuData(tb);
  out = gpu(gpubuff, address, data, tb->B_WR);
  setGpuData(tb, out);

  #ifdef TRACE
    if (tfp){
      tfp->dump(logicStep * CLOCK_NS + CLOCK_NS*0.5);
      tfp->flush();
    }
  #endif
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

  // char* ops = NULL;
  // char buff[512];
  // // char ops[512];
  //
  // if (argc != 2) {
  //   printf("Please provide exactly one input file!\n");
  //   exit(0);
  // }
  // FILE* infile = fopen(argv[1], "rb");
  // if (infile == NULL) {
  //   printf("Unable to open file %s!\n", argv[1]);
  //   exit(0);
  // }
  //
  // int lenOps = 0;
  // int done = 0;
  // while (!done){
  //   int numby = fread(buff, sizeof(char), 512, infile);
  //   if (numby == 0){
  //     break;
  //   }
  //   lenOps += numby;
  //   ops = (char*)realloc(ops, sizeof(char)*lenOps);
  //   for (int i = 0; i < numby; i++){
  //     ops[i + lenOps - numby] = buff[i];
  //   }
  //   if (numby < 512){
  //     break;
  //   }
  // }
  // fclose(infile);

  // for (int i = 0; i < lenOps; i++){
    // printf("%d\n", ops[i]);
  // }

  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  Vtop *tb = new Vtop;
  VerilatedVcdC* tfp = new VerilatedVcdC;
  #ifdef TRACE
    tb->trace(tfp, 99);
    tfp->open("trace.vcd");
  #endif

  init(tb);
  unsigned logicStep = 0;
  int prevVal = 0;
  int input = 0;
  char inputChar;

  int testState = 0;

  // for (int i = 0; i < 3; i++){
  //   tick(tb, tfp, ++logicStep);
  // }

  int out = 0;
  int data[6] = {0};
  int inbuff[2] = {0};
  char inputString[6] = {0};

  char instCap[32][5] = {
    "NOP", "LDR", "STR", "LPT",
    "SPT", "CMP", "ADD", "SUB",
    "MUL", "DIV", "MOD", "AND",
    "OR",  "XOR", "NOT", "LSL",
    "LSR", "PSH", "POP", "PEK",
    "JMP", "JSR", "RTS", "JC",
    "JSC", "RSC"
  };

  char regCap[8][2] = {
    "A", "B", "C", "D",
    "E", "F", "G", "H"
  };

  uint16_t rambuff[65536];
  uint16_t gpubuff[65536];

  tick(tb, tfp, ++logicStep, rambuff, gpubuff);
  int sendState = 0;
  int go = 0;
  int innum = 0;
  int messnum = 0;


  sf::RenderWindow window(sf::VideoMode(240*SCALE, 135*SCALE), "Display");

  // for now, we'll say that the new frame is determined
  // by a memory mapped register at FFFF of gpu ram

  clock_t period = std::clock();
  float frametime = 0.016;
  float avg[30];
  int secCount = 0;
  while (window.isOpen())
  {
      if (float(std::clock() - period)/CLOCKS_PER_SEC > 0.016667){
        frametime = float(std::clock() - period)/CLOCKS_PER_SEC;
        period = std::clock();
        gpubuff[0xffff] = 1;

        for (int i = 0; i < CLOCKS_PER_FRAME; i++){
          int status = uart(tb, go, 0, &out);
          tick(tb, tfp, ++logicStep, rambuff, gpubuff);
          if ((status & 2) > 0){
            if (innum == 0){
              inbuff[0] = out;
              innum = 1;
            } else {
              innum = 0;
              printf("\nMessage %d:\n", messnum++);
              printf("A register: %d\n", inbuff[0] | (out << 8));
            }
          }
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

          updatePixels(gpubuff, &window);
          window.display();
          for (int i = 1; i < 30; i++){
            avg[i] = avg[i - 1];
          }
          // avg[0] = float(std::clock() - period)/CLOCKS_PER_SEC;
          avg[0] = frametime;
          if (secCount++ == 60){
            secCount = 0;
            float total = 0;
            for (int i = 0; i < 30; i++){
              total += avg[i];
            }
            total /= 30.0;
            printf("Avg fps: %.2f\n", 1.0/total);
            printf("frametime: %.4f\n\n", float(std::clock() - period)/CLOCKS_PER_SEC);
          }
          // printf("frametime: %.4f\n", float(std::clock() - period)/CLOCKS_PER_SEC);
      }
  }
  return 0;
}
