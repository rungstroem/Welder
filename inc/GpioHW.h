#include <avr/io.h>

/* Left side */
#define pin1  PC6
#define pin2  PD0
#define pin3  PD1
#define pin4  PD2
#define pin5  PD3
#define pin6  PD4
// Pin 7 and 8 are Vcc and Gnd
#define pin9  PB6
#define pin10 PB7
#define pin11 PD5
#define pin12 PD6
#define pin13 PD7
#define pin14 PB0


/* Right side */
#define pin28 PC5
#define pin27 PC4
#define pin26 PC3
#define pin25 PC2
#define pin24 PC1
#define pin23 PC0
// Pin 22, 21 and 20 are Gnd ARef AVcc
#define pin19 PB5
#define pin18 PB4
#define pin17 PB3
#define pin16 PB2
#define pin15 PB1

#define INPUT  1
#define OUTPUT 0

#define HIGH 1
#define LOW  0

unsigned char pin_to_pin(unsigned char);

unsigned char pin_to_port(unsigned char);

unsigned char pin_to_ddr(unsigned char);

unsigned char pin_to_in(unsigned char);

void write_pin(unsigned char, unsigned char);

int read_pin(unsigned char);

void pin_setup(unsigned char, unsigned char);
