# comment
# so the files following a target (i.e. all) are
# the prerequisites,
# meaning they must be present for the script to execute

COM = g++
VSRC = top
CSRC = driver
OUT = run
INCL = ~/verilator/include

all: clean src sim

.PHONY: clean all sim src

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

clean:
	@ if [ -d "./obj_dir" ]; then rm -r ./obj_dir; fi
