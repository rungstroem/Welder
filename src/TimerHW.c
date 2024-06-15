#include "TimerHW.h"

unsigned int *timers[3] = {NULL};

/* Timer 0 setup
 * 
 * 
*/
void init_timer0(){
}

/* Timer 1 setup
 * 125KHz
 * 10bit resolution
 * Non-inverting, phase-correct PWM
*/
void init_timer1(){
	timers[1] = OCR1A;
	
	TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);	//Non-inverting 10bit Phase correct PWM
	TCCR1B |= (1<<CS11);	//Timer frequency = CLK/8	-> use (1<<CS10) instead for non prescaling

}

/* Timer 2 setup
 * 125KHz
 * 10bit resolution
 * Non-inverting, phase-correct PWM
*/
void init_timer2(){
	timers[2] = OCR2;
}

/* Set timer duty-cycle
*/
void set_duty_cycle(int duty, int timer){
	timers[timer] = duty;	
}
