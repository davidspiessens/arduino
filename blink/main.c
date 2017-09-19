#include <avr/io.h>
#include <util/delay.h>

// delay = 1 second
#define BLINK_DELAY_MS 1000

int main (void)
{
	// pin 5 = output
	DDRB |= _BV(DDB5);

	while(1) {
		// turn on led
		PORTB |= _BV(PORTB5);
		// wait 1 second
		_delay_ms(BLINK_DELAY_MS);
		// turn off led
		PORTB &= ~_BV(PORTB5);
		// wait 1 second
		_delay_ms(BLINK_DELAY_MS);
	}
}