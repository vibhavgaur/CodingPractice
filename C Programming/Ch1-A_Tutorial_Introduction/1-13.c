#include <stdio.h>

int lower(int c){
	if (c >= 65 && c <= 90){// c is an uppercase alphabet
		return (c + 32);
	}		
	else{
		return (c);
	}
}

int main(){
	int c;
	while ((c = getchar()) != EOF)
		putchar(lower(c));
	putchar('\n');
}

