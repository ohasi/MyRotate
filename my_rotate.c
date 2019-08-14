#include <stdio.h>

unsigned short my_rotate(unsigned short a, char b); 
unsigned short rotateRight(unsigned short a, char b);
unsigned short rotateLeft(unsigned short a, char b);
void print_short_bin(unsigned short toConvert);

int main() {
	unsigned short int a; /*the number to be rotated*/
	unsigned short c; /*the amount & direction to rotate to*/
	unsigned short d; /*the number to convert to binary*/
	unsigned short result; /*the rotated number*/
	char b; /*the amount & direction to rotate to char form*/
	scanf("%hu %hu", &a, &c); /*get the number to rotate and the amount to rotate*/
	b = c; /*convert the amount to rotate from int to char*/
	result = my_rotate(a, b); /*rotate the number and save the result*/
	printf("The number that was modified: %hu\n\
			It was moved to the %s.\n\
			It was moved %d bits.\n\
			The result is: %hu\n", a, (b > 0) ? "left" : "right", (b > 0) ? b : b * -1 , result); /*print the number, direction of rotation, amount of rotation, and the rotated number*/
	printf("\nPlease input a number to be converted to binary: "); /*asks to input a number to be converted to binary*/
	scanf("%hu", &d); /*gets the number to be converted to binary*/
	printf("\nYour Input: %hu\n", d);
	print_short_bin(d); /*prints the number in binary form*/
	return 0;
} /*end of main*/

unsigned short my_rotate(unsigned short a, char b) { /*a: the number to rotate, b: the amount to rotate*/
	if (b < 0)						/*if direction is smaller then 0*/
		a = rotateRight(a, b * -1); /*rotates to the right*/
	else if (b > 0)				/*if b is bigger then 0*/
		a = rotateLeft(a, b);   /*rotates to the left*/
	return a; /*returns the rotated number*/
} /*end of my_rotate*/

unsigned short rotateRight(unsigned short a, char b) { /*rotates a b bits to the right*/
	int tmp = 0; /*stores the rightmost bit*/
	unsigned short x1 = 0; 
	x1 = ~x1;
	x1 = x1 >> 1;
	x1 = ~x1; /*x1 helps set the leftmost bit to 1*/
	for (; b > 0; b--) { /*loops b times*/
		tmp = a % 2; /*gets the rightmost bit*/
		a = a >> 1; /*moves a 1 bit to the right*/
		if(tmp == 1)    /*if the rightmost bit is 1 */
			a = a | x1; /*sets the leftmost bit to 1*/
	} /*end of for*/
	return a; /*returns the rotated number*/
} /*end of rotateRight*/

unsigned short rotateLeft(unsigned short a, char b) { /*rotates a b bits to the left*/
	int tmp = 0; /*stores the leftmost bit*/
	unsigned short x1 = 0; 
	x1 = ~x1;
	x1 = x1 >> 1;
	x1 = ~x1; /*x1 helps get the leftmost bit*/
	for (; b > 0; b--) { /*loops b times*/
		tmp = a & x1; /*gets the leftmost bit*/
		a = a << 1; /*moves a 1 bit to the left*/
		if (tmp > 0) /*if the leftmost bit is 1*/
			a++;	 /*sets the rightmost bit to 1*/
	} /*end of for*/
	return a; /*returns the rotated number*/
} /*end of rotateLeft*/

void print_short_bin(unsigned short toConvert){ /*prints toConvert in binary form*/
	unsigned short x1 = 0; /*helps get the length of unsigned short and get the current bit*/
	unsigned short tmp; /*holds the current bit;*/
	x1 = ~x1;
	x1 = x1 >> 1;
	x1 = ~x1; /*sets x1 to binary 10000000000...*/
	for (; x1 > 0; x1 = x1 >> 1){ /*prints 1 char until it reaches a string in the length of unsigned short*/
		tmp = x1 & toConvert; /*gets the current bit*/
		putchar(tmp > 0 ? '1' : '0'); /*prints the current bit*/
	} /*end of for*/
} /*end of print_short_bin*/