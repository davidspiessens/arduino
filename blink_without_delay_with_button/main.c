#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define INITIAL_DELAY 2000;

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

	// pin 0 = input
	DDRB &= ~_BV(0);
	// enable pullup resistor for pin 1
	PORTB |= _BV(0);

	// pin 5 = output
	DDRB |= _BV(5);

	unsigned long previousMillis = 0;
	// variable blink delay
	unsigned int delay = INITIAL_DELAY;
	// previous button state
	unsigned int btn = 0;

	while (1) {
		if (millis - previousMillis > delay) {
			if (PORTB & _BV(5)) {
				// turn off led
				PORTB &= ~_BV(5);
			} else {
				// turn on led
				PORTB |= _BV(5);
			}
			previousMillis = millis;
		}
		if (PINB & _BV(0)) {
			// not pressed, set previous button state to false
			btn = 0;
		} else {
			// pressed, check if the state changed
			if (!btn) {
				if (delay > 100) {
					delay /= 2;
				} else {
					delay = INITIAL_DELAY;
				}
				// set previous button state to true
				btn = 1;
			}
		}

		// avoid debounce from the button
		_delay_ms(50);
	}
	
	return 0;
}