// omegasars
#include <stdlib.h>
#include <stdio.h>

void sort(int*);
void print_arr(int*);

int main() {
	int array_n[1000];
	int array_m[1000];
	int array_nm_diff[1000];
	
	FILE* file;
	file = fopen("input.txt", "r");
	
	// fill arrays with the right values
	// left column array_n, right array_m right array_m. 
	char buffer[16];
	int n = 0;
	int m = 0;
	int i = 0;
	while(fgets(buffer, sizeof(buffer), file)) {
		// 1st number of line
		n += (((int)buffer[0]) - 48) * 10000;
		n += (((int)buffer[1]) - 48) * 1000;
		n += (((int)buffer[2]) - 48) * 100;
		n += (((int)buffer[3]) - 48) * 10;
		n += (((int)buffer[4]) - 48) * 1;

		// 2nd number of line
		m += (((int)buffer[8])  - 48) * 10000;
		m += (((int)buffer[9])  - 48) * 1000;
		m += (((int)buffer[10]) - 48) * 100;
		m += (((int)buffer[11]) - 48) * 10;
		m += (((int)buffer[12]) - 48) * 1;

		// put n and m into arrays
		array_n[i] = n;
		array_m[i] = m;

		printf("n: %d \t m: %d\n", n, m);

		// reset for next iteration
		n = 0;
		m = 0;
		i++;
	}

	// sort the arrays
	sort(array_n);
	sort(array_m);

	// print arrays	
	// print_arr(array_n);
	// printf("\n");
	// print_arr(array_m);

	// calc diff
	for(int i = 0; i < 1000; i++) {
		if((array_n[i] - array_m[i]) < 0)
			array_nm_diff[i] = (-1) * (array_n[i] - array_m[i]);
		else
			array_nm_diff[i] = array_n[i] - array_m[i];
	}

	// print diff array
	//print_arr(array_nm_diff);	

	// calc sum of diff array
	int sum = 0;
	for(int i = 0; i < 1000; i++)
		sum += array_nm_diff[i];

	printf("sum: %d\n", sum);
	return sum;
}

void print_arr(int* array) {
	for(int i = 0; i < 1000; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void sort(int* array) {
	int i, j, temp;
	for(i = 0; i < 1000; i++) {
		for(j = i; j < 1000; j++) {
			if(array[j] < array[i]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
