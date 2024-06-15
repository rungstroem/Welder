#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main (void) {
	DDRD |= (1<<PD7);
	DDRD |= (1<<PD4);
	
	PORTD |= (1<<PD7);
	PORTD |= (1<<PD4);

	DDRC |= (1<<PC0);
	PORTC |= (1<<PC0);
    
	DDRB |= (1<<PB2);
	PORTB |= (1<<PB2);

	DDRB &= ~(1<<PB0);	//Input

    while(1){
	
		PORTD ^= (1<<PD7);
		PORTD ^= (1<<PD4);
		PORTC ^= (1<<PC0);
		PORTB ^= (1<<PB2);
		_delay_ms(2000);
    }
}
