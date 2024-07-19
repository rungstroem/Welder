#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


void adc_setup(){
	//Setup ADC for 10bit input on PC5, ie. ADC in 5
}

void timer1_setup(){
	//Setup timer 1 output B for phase-correct PWM
	DDRB |= (1<<PB2);	//Set pin for outout -> enale output driver
	TCCR1A |= (1 << COM1B1) | (1 << WGM11) | (1 << WGM10); // PWM phase correct 10bit mode
	TCCR1B |= (1 << CS11);	// Prescaler = 8

	ICR1 = 73;

	//OCR1BH and OCR1BL are 8bit registers forming the high and low byte of the 16bit timer value
	//OCR1BL = 0x00;	// <-- always read low byte first, then high byte, for read operations on 16bit registers
	//OCR1BH = 0x00;	// <-- always write high byte first, then low byte, for write operations on 16bit registers
	OCR1B = 0x0000;
		
}

int adc_read_value(){
	//Return ADC converted value
	return 100;
}

void set_wirefeed_speed(int pwm){
	OCR1B = 0xFFFF - (pwm & 0x0FFF);
}

int main (void) {
	// I'm alive led - digital output
	DDRD |= (1<<PD7);
	PORTD |= (1<<PD7);

	// Gas solenoid - digital output
	DDRD |= (1<<PD4);
	PORTD |= (1<<PD4);
	
	// Wire feed speed - ADC input
	DDRC |= (1<<PC5);
	PORTC |= (1<<PC5);
	
	// Relay enable - digital output
	DDRC |= (1<<PC0);
	PORTC |= (1<<PC0);

	// Wire feed motor - PWM output
	//DDRB |= (1<<PB2);
	//PORTB |= (1<<PB2);

	// Trigger input - digital output
	DDRB &= ~(1<<PB0);

	
	//Test timer 1 ch B
	timer1_setup();
	set_wirefeed_speed(0xFF00);

    while(1){
	
		PORTD ^= (1<<PD7);
		PORTD ^= (1<<PD4);
		PORTC ^= (1<<PC0);
		//PORTB ^= (1<<PB2);
		_delay_ms(2000);
    }
}
