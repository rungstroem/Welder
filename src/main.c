#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//_delay_ms(2000);


ISR(TIMER0_OVF_vect){
	PORTD ^= (1<<PD7);

}

void adc_setup(){
	//Setup ADC for 10bit input on PC5, ie. ADC in 5
	ADMUX |= (1 << REFS0) | (1 << MUX2) | (1 << MUX0);
	//ADMUX=0x05;	//PC5.. ?
	//Writing 1 to ADATE enables auto trigger
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);// | (1 << ADPS0);
	//Start ADC
	ADCSRA |= (1 << ADSC);
}

void timer1_setup(){
	//Setup timer 1 output B for phase-correct PWM
	DDRB |= (1<<PB2);	//Set pin for outout -> enale output driver
	TCCR1A |= (1 << COM1B1) | (1 << WGM11) | (1 << WGM10); // PWM phase correct 10bit mode
	TCCR1B |= (1 << CS11);	// Prescaler = 8

	//ICR1 = 73;	<< Don't know..?

	//OCR1BH and OCR1BL are 8bit registers forming the high and low byte of the 16bit timer value
	//OCR1BL = 0x00;	// <-- always read low byte first, then high byte, for read operations on 16bit registers
	//OCR1BH = 0x00;	// <-- always write high byte first, then low byte, for write operations on 16bit registers
	OCR1B = 0x0000;
		
}

void timer0_setup(){
	TCCR0 |= (1 << CS02) | (1 << CS00);	//Presc. 1024
	TIMSK |= (1 << TOIE0);	//Timer overflow interrupt enabled
}

int adc_read_value(){
	//Return ADC converted value
	ADCSRA |= (1 << ADSC);
	while(!(ADCSRA & (1 << ADIF)));
	return ADC;
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
	//DDRC |= (1<<PC5);
	//PORTC |= (1<<PC5);
	
	// Relay enable - digital output
	DDRC |= (1<<PC0);
	PORTC |= (1<<PC0);

	// Wire feed motor - PWM output
	//DDRB |= (1<<PB2);
	//PORTB |= (1<<PB2);

	// Trigger input - digital input
	DDRB &= ~(1<<PB0);

	
	//Test timer 1 ch B
	timer0_setup();
	timer1_setup();
	adc_setup();
	set_wirefeed_speed(0x0000);

	sei();

    while(1){
	
		//PORTD ^= (1<<PD7);
		//PORTD ^= (1<<PD4);
		//PORTC ^= (1<<PC0);
		//PORTB ^= (1<<PB2);
		if( (PINB & (1 << PB0)) ){
			PORTD |= (1 << PD4);	//Disable gas solenoid
			PORTC |= (1 << PC0);	//Disable transformer
			set_wirefeed_speed(0x0000);	//Set wirefeed = 0
		}else{
			PORTC &= ~(1 << PC0);	//Enable transformer
			PORTD &= ~(1 << PD4);	//Enable gas solenoid
			_delay_ms(600);
			set_wirefeed_speed(adc_read_value());
		}
    }
}
