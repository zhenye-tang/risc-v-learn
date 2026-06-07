CROSS_COMPILE ?= riscv64-zephyr-elf-

objs := startup_gcc.o main.o uart.o irq.o trap.o vsnprintf.o irq.o plic.o clint.o board.o interrupt_gcc.o

riscv32.bin:$(objs)
	$(CROSS_COMPILE)g++ -Wl,-Map=riscv32.map -nostartfiles -lstdc++ -std=c++11 -Tlink.lds -o riscv32.elf $^
	$(CROSS_COMPILE)objcopy -O binary -S riscv32.elf $@
	$(CROSS_COMPILE)objdump -D riscv32.elf > riscv32.s

%.o:%.S
	$(CROSS_COMPILE)gcc -fPIE -march=rv32imazicsr -mabi=ilp32 -Wall -nostdlib -c -O0 -g -o $@ $<

%.o:%.c
	$(CROSS_COMPILE)gcc -fPIE -march=rv32imazicsr -mabi=ilp32 -Wall -nostdlib -c -O0 -g -o $@ $<

%.o:%.cpp
	$(CROSS_COMPILE)g++ -fPIE -march=rv32imazicsr -mabi=ilp32 -Wall -nostdlib -fno-exceptions -fno-rtti -c -O0 -g -o $@ $<

clean:
	rm -rf *.o riscv32.bin riscv32.elf riscv32.s riscv32.map