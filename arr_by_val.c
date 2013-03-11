/*WHAT PROG DOES :
 * 	In C, u can never pass array by "value". The prog confirms/affirms this fact.
 *
 * NOTES :
 * 	BUT, u can "forcefully" pass array by value by wrapping it around a struct !!
 * 	TRY THIS AT HOME ONLY ,NOT AT WORK !! ;)
 *
 */

#include<stdio.h>

typedef struct abc{
	int arr[10];
}arr_val;
/*forcefully pass array by value */

/*************************************************/
void fun( arr_val a ){

	printf("Size passed : %d %d %d \n", (int)sizeof(a) , (int)sizeof(a.arr) );

}
/*************************************************/
void fun2( int array[10] ){
	printf("NO , Im still a pointer baba , my size is : %d \n" , (int)( sizeof(array)) );

}
/*************************************************/
int main(){
	arr_val a;
	int array[10];

	fun( a );
	fun2( array );

return 0;

}

