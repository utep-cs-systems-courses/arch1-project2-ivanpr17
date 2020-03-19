# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = ../project/lib/libTimer.a -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blinkyBuzzy.elf 

#additional rules for files
blinkyBuzzy.elf: ${COMMON_OBJECTS} main.o p1_interrupt_handler.o switches.o led.o buzzer.o ../project/lib/libTimer.a
	${CC} ${CFLAGS} $^ $(LDFLAGS) -o $@

load: blinkyBuzzy.elf
	msp430loader.sh blinkyBuzzy.elf

clean:
	rm -f *.o *.elf

main.c: buzzer.h led.h switches.h
switches.c: switches.c
led.c: led.h
buzzer.c: buzzer.h
p1_interrupt_handler.c: switches.h
wdInterruptHandler.c: buzzer.h led.h


