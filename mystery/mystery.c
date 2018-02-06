/*Rob Henderson
Rutgers University
cs211 Computer Arc TA: Binh Pham
mystery.c
Somewhat optimized version from literal translation and temp vars
gedit*/
#include <stdlib.h>
#include <stdio.h>
#include "mystery.h"
/*cached_nums array*/
int cached_nums[200];

int main(int argc, char** argv) {
	int inputNumber = atoi(argv[1]);/*Our input number to call mystery with*/
	int returnValue;/*What main will return*/

	/*less than equal to 199=less than 200*/
	/*auto-fill our cached_nums array to -1*/
	int i;
	for (i = 0; i < 200; i++) {
		cached_nums[i] = -1;
	}

	returnValue = mystery(inputNumber);
	printf("Value:   %d\n", returnValue);

	return 0;
}

int mystery(int num) {
	int returnValue;
	int fibonacciNumValue;
	fibonacciNumValue = cached_nums[num];

	if (fibonacciNumValue == -1)/*hasnt been filled yet*/
	{

		if (num == 0 || num == 1)/*fib(0)=0, fib(1)=1*/
		{
			returnValue = num;
		}

		else {
			int n1 = mystery(num - 1);
			/*int n2=cached_nums[num-2];*//*More efficient, but w/e thats not in the assembly*/
			int n2 = mystery(num - 2);
			returnValue = n1 + n2;
		}

		/*if(fibonacciNumValue==-1)*//*Will always be -1..that is why we are calculating it..*/
		cached_nums[num] = returnValue;

	}

	else/*not -1, dont bother to calculate, already in the cache from 1 calculation before*/
	{
		returnValue = fibonacciNumValue;
	}

	return returnValue;
}

