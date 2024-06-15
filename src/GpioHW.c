#include "GpioHW.h"


unsigned char pin_to_pin(unsigned char pin){
	if(pin == 1 || pin == PC6){
		return PC6;
	}
	if(pin == 2 || pin == PD0){
		return PD0;
	}
	if(pin == 3 || pin == PD1){
		return PD1;
	}
	if(pin == 4 || pin == PD2){
		return PD2;
	}
	if(pin == 5 || pin == PD3){
		return PD3;
	}
	if(pin == 6 || pin == PD4){
		return PD4;
	}
	if(pin == 9 || pin == PB6){
		return PB6;
	}
	if(pin == 10 || pin ==  PB7){
		return PB7;  
	}
	if(pin == 11 || pin ==  PD5){
		return PD5;  
	}
	if(pin == 12 || pin ==  PD6){
		return PD6;  
	}
	if(pin == 13 || pin ==  PD7){
		return PD7;  
	}
	if(pin == 14 || pin ==  PB0){
		return PB0;  
	}
	if(pin == 15 || pin ==  PB1){
		return PB1;  
	}
	if(pin == 16 || pin ==  PB2){
		return PB2;  
	}
	if(pin == 17 || pin ==  PB3){
		return PB3;  
	}
	if(pin == 18 || pin ==  PB4){
		return PB4;  
	}
	if(pin == 19 || pin ==  PB5){
		return PB5;  
	}
	if(pin == 23 || pin ==  PC0){
		return PC0;  
	}
	if(pin == 24 || pin ==  PC1){
		return PC1;  
	}
	if(pin == 25 || pin ==  PC2){
		return PC2;  
	}
	if(pin == 26 || pin ==  PC3){
		return PC3;  
	}
	if(pin == 27 || pin ==  PC4){
		return PC4;  
	}
	if(pin == 28 || pin ==  PC5){
		return PC5;
	}

	return 255;
}

unsigned char pin_to_port(unsigned char pin){
	if(pin == 1 || pin == PC6){
		return PORTC;             
	}                             
	if(pin == 2 || pin == PD0){
		return PORTD;             
	}                             
	if(pin == 3 || pin == PD1){
		return PORTD;             
	}                             
	if(pin == 4 || pin == PD2){
		return PORTD;             
	}                             
	if(pin == 5 || pin == PD3){
		return PORTD;             
	}                             
	if(pin == 6 || pin == PD4){
		return PORTD;             
	}                             
	if(pin == 9 || pin == PB6){
		return PORTB;             
	}                             
	if(pin == 10 || pin ==  PB7){
		return PORTB;             
	}                             
	if(pin == 11 || pin ==  PD5){
		return PORTD;             
	}                             
	if(pin == 12 || pin ==  PD6){
		return PORTD;             
	}                             
	if(pin == 13 || pin ==  PD7){
		return PORTD;             
	}                             
	if(pin == 14 || pin ==  PB0){
		return PORTB;             
	}                             
	if(pin == 15 || pin ==  PB1){
		return PORTB;             
	}                             
	if(pin == 16 || pin ==  PB2){
		return PORTB;             
	}                             
	if(pin == 17 || pin ==  PB3){
		return PORTB;             
	}                             
	if(pin == 18 || pin ==  PB4){
		return PORTB ;            
	}                             
	if(pin == 19 || pin ==  PB5){
		return PORTB;             
	}                             
	if(pin == 23 || pin ==  PC0){
		return PORTC;             
	}                             
	if(pin == 24 || pin ==  PC1){
		return PORTC;             
	}                             
	if(pin == 25 || pin ==  PC2){
		return PORTC;             
	}                             
	if(pin == 26 || pin ==  PC3){
		return PORTC;             
	}                             
	if(pin == 27 || pin ==  PC4){
		return PORTC;             
	}                             
	if(pin == 28 || pin ==  PC5){
		return PORTC;
	}
	
	return 255;
}

unsigned char pin_to_in(unsigned char pin){
	if(pin == 1 || pin == PC6){
		return PINC;              
	}                             
	if(pin == 2 || pin == PD0){
		return PIND;              
	}                             
	if(pin == 3 || pin == PD1){
		return PIND;              
	}                             
	if(pin == 4 || pin == PD2){
		return PIND;              
	}                             
	if(pin == 5 || pin == PD3){
		return PIND;              
	}                             
	if(pin == 6 || pin == PD4){
		return PIND;              
	}                             
	if(pin == 9 || pin == PB6){
		return PINB;              
	}                             
	if(pin == 10 || pin ==  PB7){
		return PINB;              
	}                             
	if(pin == 11 || pin ==  PD5){
		return PIND;              
	}                             
	if(pin == 12 || pin ==  PD6){
		return PIND;              
	}                             
	if(pin == 13 || pin ==  PD7){
		return PIND;              
	}                             
	if(pin == 14 || pin ==  PB0){
		return PINB;              
	}                             
	if(pin == 15 || pin ==  PB1){
		return PINB;              
	}                             
	if(pin == 16 || pin ==  PB2){
		return PINB;              
	}                             
	if(pin == 17 || pin ==  PB3){
		return PINB;              
	}                             
	if(pin == 18 || pin ==  PB4){
		return PINB;              
	}                             
	if(pin == 19 || pin ==  PB5){
		return PINB;              
	}                             
	if(pin == 23 || pin ==  PC0){
		return PINC;              
	}                             
	if(pin == 24 || pin ==  PC1){
		return PINC;              
	}                             
	if(pin == 25 || pin ==  PC2){
		return PINC;              
	}                             
	if(pin == 26 || pin ==  PC3){
		return PINC;              
	}                             
	if(pin == 27 || pin ==  PC4){
		return PINC;              
	}                             
	if(pin == 28 || pin ==  PC5){
		return PINC;
	}
	
	return 255;
}

unsigned char pin_to_ddr(unsigned char pin){
	if(pin == 1 || pin == PC6){
		return DDRC;              
	}                             
	if(pin == 2 || pin == PD0){
		return DDRD;              
	}                             
	if(pin == 3 || pin == PD1){
		return DDRD;              
	}                             
	if(pin == 4 || pin == PD2){
		return DDRD;              
	}                             
	if(pin == 5 || pin == PD3){
		return DDRD;              
	}                             
	if(pin == 6 || pin == PD4){
		return DDRD;              
	}                             
	if(pin == 9 || pin == PB6){
		return DDRB;              
	}                             
	if(pin == 10 || pin ==  PB7){
		return DDRB;              
	}                             
	if(pin == 11 || pin ==  PD5){
		return DDRD;              
	}                             
	if(pin == 12 || pin ==  PD6){
		return DDRD;              
	}                             
	if(pin == 13 || pin ==  PD7){
		return DDRD;              
	}                             
	if(pin == 14 || pin ==  PB0){
		return DDRB;              
	}                             
	if(pin == 15 || pin ==  PB1){
		return DDRB;              
	}                             
	if(pin == 16 || pin ==  PB2){
		return DDRB;              
	}                             
	if(pin == 17 || pin ==  PB3){
		return DDRB;              
	}                             
	if(pin == 18 || pin ==  PB4){
		return DDRB;              
	}                             
	if(pin == 19 || pin ==  PB5){
		return DDRB;              
	}                             
	if(pin == 23 || pin ==  PC0){
		return DDRC;              
	}                             
	if(pin == 24 || pin ==  PC1){
		return DDRC;              
	}                             
	if(pin == 25 || pin ==  PC2){
		return DDRC;              
	}                             
	if(pin == 26 || pin ==  PC3){
		return DDRC;              
	}                             
	if(pin == 27 || pin ==  PC4){
		return DDRC;              
	}                             
	if(pin == 28 || pin ==  PC5){
		return DDRC;
	}
	
	return 255;

}

void write_pin(unsigned char pin, unsigned char level){
	unsigned char pin_ = pin_to_pin(pin);
	unsigned char port_ = pin_to_port(pin);

	if(level == 0) port_ |=  (1 << pin_);
	if(level == 1) port_ &= ~(1 << pin_);
	//if(level == 0) port_ |= (1 << pin_);
	//if(level == 1) port_ &= ~(1<< pin_);

	return;

	(level > 0) ? ( port_ |= (1<<pin_) ) : ( port_ &= ~(1<<pin_) );
}

int read_pin(unsigned char pin){
	unsigned char pin_ = pin_to_pin(pin);
	unsigned char p_in_ = pin_to_in(pin);

	return (p_in_ & (1 << pin_)) >> pin_;
}

void pin_setup(unsigned char pin, unsigned char IO){
	unsigned char pin_ = pin_to_pin(pin);
	unsigned char ddr_ = pin_to_ddr(pin);

	if(IO == 0) DDRD |= (1 << pin_);
	if(IO == 1) DDRD &= ~(1<< pin_);
	
	return;

	(IO == INPUT) ? ( ddr_ &= ~(1 << pin_) ) : ( ddr_ |=(1 << pin_) );
}
