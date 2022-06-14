/*#include <stdio.h>*/

#define		MAXLINE		1000
#define		EOF		-1

int getline(char s[], int lim){
	int c, i;

	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int main(){
	char line[MAXLINE];
	int len;

	while ((len = getline(line, MAXLINE)) > 0){
		if (len > 80){
			for (int j = 0; j < len-1; ++j)
				putchar(line[j]);
			putchar('\n');
				
		}
	}
}
