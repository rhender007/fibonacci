/*Robert Henderson
Rutgers University
Project 3 formula
cs211 Computer Arc TA: Binh Pham
*/
#include <stdio.h>
#include <stdlib.h>
#include "nCr.h"
#include "formula.h"
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {

	struct timeval timev;
	time_t startTime;
	time_t startTimeInSeconds;
	time_t finishedTime;
	time_t finishedTimeInSeconds;

	gettimeofday(&timev, NULL);
	startTime = timev.tv_usec;/*time value in microseconds..Always less that 1 million*/
	startTimeInSeconds = timev.tv_sec;/*Time value in seconds*/

	
	if (argc == 2)/*attempt to execute calculation*/
	{
		if (!strcmp(argv[1], "-h"))/*help*/
		{
			fprintf(stderr,"Usage: formula <positive integer>\n");
		}
		else
		{		
			long int n;
			char* ptr;
			n = strtol(argv[1], &ptr, 0);

			if ((!strcmp("", ptr) ==0)||(n<0))/*bad input, dont even bother to go in*/
				fprintf(stderr,"Invalid input...type -h for help\n");
			else
				PrintBinomialTheorum(n);
		}

	} else/*Incorrect parameters case*/
	{
		fprintf(stderr,"ERROR...Incorrect number of parameters.. type -h for help\n");
	}

	gettimeofday(&timev, NULL);
	finishedTime = timev.tv_usec;
	finishedTimeInSeconds = timev.tv_sec;

	finishedTime = (finishedTime - startTime) + (1000000
			* (finishedTimeInSeconds - startTimeInSeconds));
	printf("%s%ld%s\n", "Time Required = ", finishedTime, " microseconds");

	return 0;
}

int PrintBinomialTheorum(int n)/*Prints out the binomial theorum*/
{

	int r;/*r value in n choose r*/
	int nChooseR;
	for (r = 0; r <= n; r++) {
		nChooseR = nCr(n, r);

		if (nChooseR == 0) {
			fprintf(stderr,"ERROR...Overflow\n");
			return 0;
		}

		if (r > 0)
			printf(" + ");
		printf("%d", nChooseR);
		if (r > 0)
			printf("*X^%d", r);
	}
	printf("\n");
	return 1;
}
