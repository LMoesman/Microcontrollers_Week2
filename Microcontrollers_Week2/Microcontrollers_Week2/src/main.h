/*
 * main.h
 *
 * Created: 8-2-2018 16:19:23
 *  Author: Lars Moesman
 */ 


#ifndef MAIN_H_
#define MAIN_H_
#define F_CPU 8000000

const unsigned char 	NUMBERS[15] =
{
	0b00111111,		// 0
	0b00000110,		// 1
	0b01011011,		// 2
	0b01001111,		// 3
	0b01100110,		// 4
	0b01101101,		// 5
	0b01111101,		// 6
	0b00000111,		// 7
	0b01111111,		// 8
	0b01101111,		// 9
	0b01110111,		// A
	0b01111111,		// B
	0b00111001,		// C
	0b01011110,		// D
	0b01111001		// E
	
};
const unsigned char NUMBER_ANIMATION[16] = {
	0b01000000,
	0b01010000,
	0b01011000,
	0b01011100,
	0b01011110,
	0b01011111,
	0b01011111,
	0b01111111,
	0b00111111,
	0b00101111,
	0b00100111,
	0b00100011,
	0b00100001,
	0b00100000,
	0b00100000,
	0b00000000

};
void ExecuteB2(void);
void ExecuteB3(void);
void display(int);
void wait(int);

#endif /* MAIN_H_ */