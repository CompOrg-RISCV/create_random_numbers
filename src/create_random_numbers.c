#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(void) {
	uint32_t	    temp;
    uint32_t    seed;
	uint32_t	num_of_random_num;
	uint32_t	max_range_random = 1024;
	FILE	*random_file_ptr;

	// Provide statement on the range of random numbers to generate
	printf("This program will create a file named random_numbers.txt to store a user specified\n");
	printf(" number of random numbers whose max number equals %d\n\n", max_range_random - 1);

	// Determine the desired amount of random numbers
	printf("How many random numbers to generate? ");
	scanf("%d",&num_of_random_num);

	// Create seed by using combining first and last initial
	printf("\nInput a number between 10 and 1000 to create the random number generator seed: ");
	scanf("%d",&seed);

	// set random number seed
	srand(seed);

	// open file to write random numbers
	random_file_ptr = fopen("../src/random_numbers.txt","w");
	
	// write random numbers into file
	// random numbers are 0 thru 1023
	for (uint32_t i = 0; i < num_of_random_num; i++) {
		fprintf (random_file_ptr, "%d\n", (rand() & (max_range_random-1)));
	}
	
	// close file
	fclose(random_file_ptr);
}
