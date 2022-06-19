/*#include <stdio.h>*/

# define	MAXLINE		1000	// max size of input line
# define	EOF		-1

int getline(char s[], int lim){
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char s1[], char s2[]){
	int i = 0;
	while ((s2[i] = s1[i]) != '\0')
		++i;
}

int main(){
	int len;		// current line length
	int max;		// max line length seen so far
	char line[MAXLINE];	// current input line
	char save[MAXLINE];	// longest line, to be saved

	max = 0;
}
