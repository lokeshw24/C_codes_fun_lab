/*Playing with "extern" type 
 *How to compile: cc third.c fourth.c
 If we do only : cc third.c , then we get "linker" error , not "compiler" error.
 * */

#include<stdio.h>

int main(){
	extern i;
	extern char c ;
	/* NOTE: "extern" is just 'declaring' a variable, not 'defining'( allocate storage ) it !! 
	 * >Basically, the type 'extern' says, that the variable is 'defined' somewhere else, find out !
	 * It might be in same file, at bottom , or in other header file etc
	 *
	 * >By default, function 'declartion' are of type 'extern' 
	 * 	This is the reason, we 'declare' the function in 'header'( stack.h ) file & 'define' it in other file( stack.c ) .
	 *
	 */

	/*scanf("%d" ,&i );
	i=23;
	*/

	/*We _can_ do scanf() on extern variables, no issues !! 
	 */

	printf("%d %c\n" , i , c);

return 0;

}

//int i=22;

/*If u uncomment above line, then u can do "cc third.c" & it will not give error.
 * Basically, 'extern' tells compiler that the "definition" of the variable is somewhere else. So it happily compiles
 * the variable  in the object file, & leaves it to the "linker" to link that variable's info later.
 *
 */

/*For more, see code examples here : http://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
 * Short & simple & easy.
 */
