# comment
# so the files following a target (i.e. all) are
# the prerequisites,
# meaning they must be present for the script to execute

COM = g++
VSRC = top
CSRC = driver
OUT = run
PROG = program
PROGOUT = out
PROGROM = romdata
PYCOMP = assembler.py

UNAME = $(shell uname)
PHONETEST = $(shell $PREFIX)

ifeq ($(UNAME), Linux)
INCL = /usr/share/verilator/include
else ifeq ($(PHONETEST), /data/data/com.termux/files/usr)
INCL = ~/verilator/include
else
INCL = ~/verilator/include
endif
ifeq ($(UNAME), Linux)
PYVAR = python3
else
PYVAR = py
endif

all: clean prog src sim

.PHONY: clean all sim src prog

src: ./verilog/${VSRC}.v ./env/${CSRC}.c
	@ # consider using trace threads to improve performance
	@ # i.e. --trace-threads <number of threads>
	@ # trace depth will also improve performance
	@ # a level of 1 limits tracing to merely top level signals!
	@ # i.e. --trace-depth <depth>
	verilator -Wall --trace -cc ./verilog/${VSRC}.v -I./verilog/
	make -f V${VSRC}.mk -C ./obj_dir/

sim: ./env/${CSRC}.c
	${COM} ./env/${CSRC}.c \
	-I ./env/ \
	-I ${INCL} \
	-I ./obj_dir/ \
	${INCL}/verilated.cpp \
	${INCL}/verilated_vcd_c.cpp \
	./obj_dir/V${VSRC}__ALL.a -o ${OUT}


prog: ./programs/${PROG}.cor ./programs/${PYCOMP}
	${PYVAR} ./programs/${PYCOMP} ./programs/${PROG}.cor \
	./programs/${PROGOUT}.vus ./verilog/${PROGROM}.v

clean:
	@ if [ -d "./obj_dir" ]; then rm -r ./obj_dir; fi
