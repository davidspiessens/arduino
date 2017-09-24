#include <avr/interrupt.h>
#include <avr/io.h>

// delay = 1 second
#define BLINK_DELAY_MS 1000

volatile unsigned long millis = 0;

ISR(TIMER0_OVF_vect) {
	millis++;
}

int main(void)
{
	// enable interrupts
	sei();

	// set the prescaler to 64
	TCCR0B = 0x03;

	// enable timer0
	TIMSK0 = 0x01;

	// pin 5 = output
	DDRB |= _BV(5);

	unsigned long previousMillis = 0;

	while (1) {
		if (millis - previousMillis > BLINK_DELAY_MS) {
			if (PORTB & _BV(PORTB5)) {
				// turn off led
				PORTB &= ~_BV(PORTB5);
			} else {
				// turn on led
				PORTB |= _BV(PORTB5);
			}
			previousMillis = millis;
		}
	}
	
	return 0;
}