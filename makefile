# comment
# so the files following a target (i.e. all) are
# the prerequisites,
# meaning they must be present for the script to execute

COM = g++
VSRC = top
CSRC = display
OUT = run
PROG = program
PROGOUT = out
PROGROM = promdata
DATROM = dromdata
PYCOMP = assembler.py
PHONEPATH = /data/data/com.termux/files/usr
SRCEX = verilator -Wall -cc
SRCEX_W_TRACE = verilator -Wall --trace -cc

UNAME = $(shell uname)
PHONETEST = $(shell $PREFIX)
THREADED =
EXEC_THREADED = ./$(OUT)

ifeq ($(PREFIX), $(PHONEPATH))
INCL = ~/verilator/include
SRCOPT = ./verilog/${VSRC}.v -I./verilog/
else ifeq ($(UNAME), Linux)
LIB = /usr/share/verilatore/
INCL = /usr/share/verilator/include
SRCOPT = -O3 --x-assign fast --x-initial fast --noassert ./verilog/${VSRC}.v -I./verilog/
SRCOPT_THREAD = --threads 4 -O3 --x-assign fast --x-initial fast --noassert ./verilog/${VSRC}.v -I./verilog/
THREADED = -DVL_THREADED
EXEC_THREADED = numactl -m 0 -C 0,1,2,3 -- $(OUT)
else
INCL = ~/verilator/include
SRCOPT = ./verilog/${VSRC}.v -I./verilog/
endif

ifeq ($(UNAME), Linux)
PYVAR = python3
else
PYVAR = py
endif

all: clean prog src sim execute


.PHONY: clean all sim src prog reset execute trace src_w_trace sim_w_trace thread

src: ./verilog/${VSRC}.v ./env/${CSRC}.cpp
	${SRCEX} ${SRCOPT}
	make -f V${VSRC}.mk -C ./obj_dir/

src_w_thread: ./verilog/${VSRC}.v ./env/${CSRC}.cpp
	${SRCEX} ${SRCOPT_THREAD}
	make -f V${VSRC}.mk -C ./obj_dir/

sim: ./env/${CSRC}.cpp
	${COM} -c ./env/${CSRC}.cpp -I ./env/ \
  -I ${INCL} -I ./obj_dir/ ${INCL}/verilated.cpp \
	${INCL}/verilated_vcd_c.cpp
	@ # ./obj_dir/V${VSRC}__ALL.a
	${COM} ${CSRC}.o -o ${OUT} \
	-lglfw -lGLEW -lGL -pthread \
	-I ${INCL} -I ./obj_dir/ ${INCL}/verilated.cpp \
	${INCL}/verilated_vcd_c.cpp \
	./obj_dir/V${VSRC}__ALL.a

sim_w_thread: ./env/${CSRC}.cpp
	${COM} -c ./env/${CSRC}.cpp -D THREAD ${THREADED} -I ./env/ \
  -I ${INCL} -I ./obj_dir/ ${INCL}/verilated.cpp \
	${INCL}/verilated_vcd_c.cpp ${INCL}/verilated_threads.cpp
	@ # ./obj_dir/V${VSRC}__ALL.a
	${COM} ${CSRC}.o -o ${OUT} ${THREADED} \
	-lglfw -lGLEW -lGL -pthread \
	-I ${INCL} -I ./obj_dir/ ${INCL}/verilated.cpp \
	${INCL}/verilated_vcd_c.cpp \
	./obj_dir/V${VSRC}__ALL.a ${INCL}/verilated_threads.cpp

prog: ./programs/${PROG}.cor ./programs/${PYCOMP}
	${PYVAR} ./programs/${PYCOMP} ./programs/${PROG}.cor \
	./programs/${PROGOUT}.vus ./verilog/${PROGROM}.v \
	./verilog/${DATROM}.v

clean:
	@ if [ -d "./obj_dir" ]; then rm -r ./obj_dir; fi

reset:
	git fetch
	git reset --hard origin/master

execute:
	./${OUT}

execut_threaded:
	${EXEC_THREADED}

src_w_trace:
	${SRCEX_W_TRACE} ${SRCOPT}
	make -f V${VSRC}.mk -C ./obj_dir/

sim_w_trace:
	${COM} -c ./env/${CSRC}.cpp -D TRACE -I ./env/ \
  -I ${INCL} -I ./obj_dir/ ${INCL}/verilated.cpp \
	${INCL}/verilated_vcd_c.cpp
	@ # ./obj_dir/V${VSRC}__ALL.a
	${COM} ${CSRC}.o -o ${OUT} -lglfw -lGLEW -lGL \
	-I ${INCL} -I ./obj_dir/ ${INCL}/verilated.cpp \
	${INCL}/verilated_vcd_c.cpp \
	./obj_dir/V${VSRC}__ALL.a

trace: clean prog src_w_trace sim_w_trace execute

thread: clean prog src_w_thread sim_w_thread execute
