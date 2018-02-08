/*
 * Microcontrollers_Week2.c
 *
 * Created: 8-2-2018 16:21:46
 * Author : Lars Moesman & Rick Verstraten
 */ 

#include "main.h"
#include <avr/io.h>
#include <avr/interrupt.h>

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
	if (PORTC == 0x80)
	{
		PORTC = 0x01;
	}else {
			PORTC <<= 1;
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
	if (PORTC == 0x00)
	{
		PORTC = 0x80;
	}else {
		PORTC >>= 1;
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
	ExecuteB2();
	
    while (1) 
    {
	
    }
}

