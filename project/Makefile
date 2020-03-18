# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blinkyBuzzy.elf 

#additional rules for files
blinkyBuzzy.elf: ${COMMON_OBJECTS} main.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} $^ $(LDFLAGS) -o $@ $^

load: blinkyBuzzy.elf
	msp430loader.sh blinkyBuzzy.elf

clean:
	rm -f *.o *.elf

main.o: main.c


