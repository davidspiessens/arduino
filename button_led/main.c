#include <avr/io.h>
#include <util/delay.h>

typedef int bool;
#define true 1
#define false 0

int main (void)
{
	// pin 0 = input
	DDRB &= ~_BV(DDB0);
	// enable pullup resistor for pin 1
	PORTB |= _BV(PORTB0);
	// pin 5 = output
	DDRB |= _BV(DDB5);
	
	// turn on led
	PORTB |= _BV(PORTB5);

	// previous button state
	bool btn = false;

	while(1) { 	
		// check if the button is pressed
		// remember: it's a pullup resistor, the not-pressed state of the button is high
		if (PINB & _BV(PINB0)) {
			// not pressed, set previous button state to false
			btn = false;
		} else {
			// pressed, check if the state changed
			if (!btn) {
				if (PORTB & _BV(PORTB5)) {
					// turn off led
					PORTB &= ~_BV(PORTB5);
				} else {
					// turn on led
					PORTB |= _BV(PORTB5);
				}
				// set previous button state to true
				btn = true;
			}
		}

		// avoid debounce from the button
		_delay_ms(50);
	}
}