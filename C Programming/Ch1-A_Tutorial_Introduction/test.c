#include<stdio.h>

int main(){
	int c;
	int prevWasBlank = 0;
	while ((c = getchar()) != EOF){
		if (c != ' '){
			putchar(c);
			prevWasBlank = 0;
		}
		else{
			if (prevWasBlank){
				continue;
			}
			putchar(' ');
			prevWasBlank = 1;
		}

	}
}
