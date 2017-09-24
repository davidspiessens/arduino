#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	// pin 0 = input
	DDRB &= ~_BV(0);
	// enable pullup resistor for pin 1
	PORTB |= _BV(0);
	// pin 5 = output
	DDRB |= _BV(5);
	
	// turn on led
	PORTB |= _BV(5);

	// previous button state
	bool btn = 0;

	while(1) { 	
		// check if the button is pressed
		// remember: it's a pullup resistor, the not-pressed state of the button is high
		if (PINB & _BV(0)) {
			// not pressed, set previous button state to false
			btn = 0;
		} else {
			// pressed, check if the state changed
			if (!btn) {
				if (PORTB & _BV(5)) {
					// turn off led
					PORTB &= ~_BV(5);
				} else {
					// turn on led
					PORTB |= _BV(5);
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