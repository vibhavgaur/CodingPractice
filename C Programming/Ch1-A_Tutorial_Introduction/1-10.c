#include <stdio.h>

#define		YES	1
#define		NO	0

int main(){
	int c, prevWasBlank;
	prevWasBlank = NO;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			if (prevWasBlank == NO)
				putchar('\n');
			prevWasBlank = YES;	// last char on output was blank
		}
		else{
			putchar(c);
			prevWasBlank = NO;	// last char on output was not blank
		}
	}
}
