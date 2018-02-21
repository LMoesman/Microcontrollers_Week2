/*
 * Microcontrollers_Week2.c
 *
 * Created: 8-2-2018 16:21:46
 * Author : Lars Moesman & Rick Verstraten
 */ 

#include "main.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <time.h>

int exercise;
int digitIndex = 0;

/******************************************************************/
void ExecuteB2(){
/* 
short:			Initilises interreupts and io
inputs:			
outputs:	
notes:			
Version :    	1.0
Author	:		Lars Moesman & Rick Verstraten
*******************************************************************/
exercise = 2;
	DDRC = 0xFF;
	DDRD = 0x00;
	
	PORTC = 0x01;
	
	EICRA |= 0x3C;
	EIMSK |= 0x06;
	
	sei();
}

/******************************************************************/
ISR(INT1_vect) {
/*
short:			ISR INT1
inputs:
outputs:
notes:			Set PORTC
Version :    	1.0
Author	:		Lars Moesman & Rick Verstraten
*******************************************************************/
	if(2 == exercise){
		if (PORTC == 0x80)
		{
			PORTC = 0x01;
		}else {
			PORTC <<= 1;
		}
	}else if(3 == exercise){
		if(PIND == 0x06){
			digitIndex = 0;
			display(digitIndex);
			return;
		}
		if(digitIndex < 14){
			digitIndex++;
		}
		display(digitIndex);
	}
}

/******************************************************************/
ISR(INT2_vect) {
/*
short:			ISR INT2
inputs:
outputs:
notes:			Set PORTC
Version :    	1.0
Author	:		Lars Moesman & Rick Verstraten
*******************************************************************/
	if(2 == exercise){
		if (PORTC == 0x00)
		{
			PORTC = 0x80;
		}else {
			PORTC >>= 1;
		}
	
	}else if(3 == exercise){
		if(PIND == 0x06){
			digitIndex = 0;
			display(digitIndex);
			return;
		}
		if(digitIndex > 0){
			digitIndex--;
		}
		display(digitIndex);
	}
}
/******************************************************************/
void ExecuteB3(){
	/*
	short:			Initilises interreupts and io
	inputs:
	outputs:
	notes:
	Version :    	1.0
	Author	:		Lars Moesman & Rick Verstraten
	*******************************************************************/
	exercise =3;
	DDRC = 0xFF;
	DDRD = 0x00;
	
	EICRA |= 0x3C;
	EIMSK |= 0x06;
	
	sei();
	display(0);
}
/******************************************************************/
void display (int digit){
	/*
	short:			search in the NUMBERS array for an binair value to assign
	inputs:			int digit is number
	outputs:
	notes:
	Version :    	1.0
	Author	:		Lars Moesman & Rick Verstraten
	*******************************************************************/
	if(digit >=0 && digit <=15){
		PORTC = NUMBERS[digit];
	}
}
/******************************************************************/
void ExecuteB4(){
	/*
	short:			executes segmentdisplay animation
	inputs:			
	outputs:
	notes:
	Version :    	1.0
	Author	:		Lars Moesman & Rick Verstraten
	*******************************************************************/
	int i = 0;
	for(i = 0;i < 16;i++){
		DDRC = 0xFF;
		PORTC = NUMBER_ANIMATION[i];
		wait(200);
	}
	
}
/******************************************************************/
int main(void)
/*
short:			main() loop, entry point of executable
inputs:
outputs:
notes:			Looping forever, flipping bits on PORTD
Version :    	DMK, Initial code
*******************************************************************/
{
	//ExecuteB2();
//	ExecuteB3();

    while (1) 
    {
		ExecuteB4();
    }
}

/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
Author	:		dkroeske@gmail.com
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

