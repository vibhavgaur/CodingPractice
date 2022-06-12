//Histogram of word lengths

#include <stdio.h>

#define 	MAX_WORD_LENGTH		10
#define		HIST_CHAR		'X'

int main(){
	int hist_x[MAX_WORD_LENGTH], prevWasBlank , c, n_chars;
	n_chars = prevWasBlank = 0;
	// initialize array
	for (int i = 0; i < MAX_WORD_LENGTH; ++i)
		hist_x[i] = 0;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			if (n_chars > MAX_WORD_LENGTH)
				n_chars = MAX_WORD_LENGTH;
			if (prevWasBlank == 0)
				++hist_x[n_chars];

			prevWasBlank = 1;
			n_chars = 0;
		}
		else{
			++n_chars;
			prevWasBlank = 0;
		}
	}
	// print the arrays afterwards
	printf("hist_x: ");
	for (int i = 0; i < MAX_WORD_LENGTH; ++i){
		printf("\n");
		printf("Iteration number: %d | ", i);
		printf("%d ", hist_x[i]);
		printf("\n");
	}
	printf("\n");
}
