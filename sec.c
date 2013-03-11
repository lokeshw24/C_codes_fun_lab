/*See all, for everything about "const" & "const *"
 */

#include<stdio.h>

int main(){
	int const i = 5 ;

	//i=6;
	/*this is not allowed, it gives error saying 'i' is 'read-only' variable */

	//printf("%d \n", ++i );
	/* even this is not allowed */

/***************************************************************/

	int j=2;
	int * const temp=&j;
	//const * int t1=&j;

	printf("%d \n", ++(*temp) );
	//printf("%d \n", ++(*t1) );

	//temp=&i;
	/* this is not allowed, as the pointer is now a 'constant' */


	int const *t = &j;
	//now the 'value' is 'constant', not the pointer	
	
	
	const int *t1=&j;
	printf("%d \n", ++(*t1) );
	//again , 'value' is 'constant'



return 0;

}
