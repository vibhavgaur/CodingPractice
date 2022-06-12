#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
/*#include <math.h>*/

int main(){
	int arr[3] = {3,-7,0};
	int minabsdiff = INT_MAX;
	/*printf("size arr: %ld\nsize*arr: %ld", sizeof arr, sizeof *arr);*/
	for(int i = 0; i < sizeof arr/sizeof *arr; i++){
		/*printf("i = %d\n", i);*/
		for(int j = i + 1; j < sizeof arr/sizeof *arr; j++){
			printf("i = %d, j = %d\n", i, j);
			if (minabsdiff > abs(arr[i]-arr[j]))
				minabsdiff = abs(arr[i]-arr[j]);
		}
	}
	printf("Min abs diff: %d\n", minabsdiff);
}
