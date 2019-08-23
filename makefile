CHAIN=arm-none-eabi
CFLAGS=-mcpu=cortex-a8 -march=armv7-a -mfpu=vfp -mfloat-abi=softfp
AFLAGS=-mfpu=neon -mcpu=cortex-a8
IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/

all: app

app: start.o main.o gpioFunctions.o interrupt.o cpu.o
	$(CHAIN)-ld $(OBJ)start.o $(OBJ)main.o $(OBJ)gpioFunctions.o $(OBJ)interrupt.o $(OBJ)cpu.o -T $(SRC)memmap.ld -o $(OBJ)main.elf
	$(CHAIN)-objcopy $(OBJ)main.elf $(BIN)spl.boot -O binary
	cp $(BIN)spl.boot /tftpboot/appGpio.bin

start.o: $(SRC)start.s
	$(CHAIN)-as $(IPATH) $(SRC)start.s -o $(OBJ)start.o

main.o: $(SRC)main.c
	$(CHAIN)-gcc $(CFLAGS) $(IPATH) -c $(SRC)main.c -o $(OBJ)main.o

gpioFunctions.o: $(SRC)gpioFunctions.c
	$(CHAIN)-gcc $(CFLAGS) $(IPATH) -c $(SRC)gpioFunctions.c -o $(OBJ)gpioFunctions.o

interrupt.o: $(SRC)interrupt.c
	$(CHAIN)-gcc $(CFLAGS) $(IPATH) -c $(SRC)interrupt.c -o $(OBJ)interrupt.o

cpu.o: $(SRC)cpu.c
	$(CHAIN)-gcc $(AFLAGS) $(IPATH) -c $(SRC)cpu.c -o $(OBJ)cpu.o
                                        
copy:
	cp $(BIN)spl.boot /tftpboot/appGpio.bin

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(OBJ)*.elf
	rm -rf $(BIN)*.boot

dump:
	$(CHAIN)-objdump -D $(OBJ)main.elf
