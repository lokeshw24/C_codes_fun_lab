/*Watch out the output */

#include<stdio.h>

int main(){

	char *p;
	p="Hello";

	printf("%c \n", *&*p );

return 0;

}
