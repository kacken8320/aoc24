// omegasars
#include <stdlib.h>
#include <stdio.h>

int main() {
	int array1[890];
	int array2[890];

	// open file
	FILE* sars;
	sars = fopen("input.txt", "r");

	// read file
	char line[13];
	fgets(line, 13, sars);

	// fill arrays
	
