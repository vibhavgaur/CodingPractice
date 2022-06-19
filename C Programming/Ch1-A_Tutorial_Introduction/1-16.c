/*1-16: Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.*/

#include <stdio.h>

#define		MAXLINE		1000
/*#define		EOF		-1*/
#define		YES		1
#define		NO		0

int getl(char s[], int lim){
	printf("In getl\n");
	int c, i;

	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	printf("Exiting getl\n");
	return i;
}

int main(){
	char line[MAXLINE];
	int i = 0;
	int j; 
	int prevWasBlank = 0;
	while (getl(line, MAXLINE) > 0){
		printf("%i -- %s\n", i, line);
		printf("End of line\n");
		++i;
	}
}
