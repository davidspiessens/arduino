PKG=main
BIN=${PKG}
OBJS=${PKG}.o
MCU=atmega328p

CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Os -DF_CPU=16000000UL -mmcu=${MCU} -Wall
PORT=/dev/cu.usbmodem1411

${BIN}.hex: ${BIN}.elf
	${OBJCOPY} -O ihex $< $@

${BIN}.elf: ${OBJS}
	${CC} -mmcu=${MCU} -o $@ $^

install: ${BIN}.hex
	avrdude -v -c arduino -p ${MCU} -P ${PORT} -b 115200 -U flash:w:$<

clean:
	rm -f ${BIN}.elf ${BIN}.hex ${OBJS}