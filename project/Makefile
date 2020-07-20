# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS}main.o p2_interrupt_handler.o led.o switches.o  ./timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

buttonA.elf: ${COMMON_OBJECTS} main.o p2_interrupt_handler.o led.o switches.o ./timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

loadA: buttonA.elf
	mspdebug rf2500 "prog buttonA.elf"

load: button.elf
	mspdebug rf2500 "prog button.elf"

clean:
	rm -f *.o *.elf

main.o: switches.h led.h 
led.o: switches.h led.h
switches.o: switches.h led.h
p2_interrupt_handler.o: switches.h



