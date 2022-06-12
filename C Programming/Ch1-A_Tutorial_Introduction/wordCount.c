#include<stdio.h>

#define		YES 	1
#define		NO	0

int main(){
	int c, n_lines, n_words, n_chars, inword;

	inword = NO;
	n_lines = n_words = n_chars = 0;

	while ((c = getchar()) != EOF){
		++n_chars;
		if (c == '\n')
			++n_lines;
		if (c == ' ' || c == '\n' || c == '\t')
			inword = NO;
		else if (inword == NO){
			inword = YES;
			++n_words;
		}
	}
	printf("Lines: %d, Words: %d, Characters: %d\n", n_lines, n_words, n_chars);
}
