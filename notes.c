>Diff between executable file & object file.
Both are binary files but the differences between those are:-
1. we can execute an executable file while we cannot execute an object file.

2. An object file is a file where compiler has not yet linked to the libraries, so you get an object file just before linking to the libraries, so still some of the symbols or function definitions are not yet resolved which are actually present in the libraries, and that's why we cannot execute it.
Once an object file is linked with the library by the compiler, then all the symbols are resolved and we get an executable file which can be executed on the appropriate platform.
So basically the difference is that we get an object file when we don't link with library while executable file is with the linking phase.
In gcc we can direct compiler not to link with library and so it will prepare the object file :-
gcc -c test.c
It will automatically create test.o object file
when you try to execute it like:-
./test.o
cannot execute binary file
/********************************************************************/

>Use/Need of "static" data type : 
In the C programming language, static is used with global variables and functions to set their scope to the containing file. Is used widely as an "access control" feature. If you have a .c file implementing some functionality, it usually exposes only a few "public" functions to users. The rest of its functions should be made static, so that the user won't be able to access them. This is encapsulation, a good practice.
	>By default, all function are "extern" type, ie all other codes can directly call them.

In local variables, static is used to store the variable in the statically allocated memory instead of the automatically allocated memory. While the language does not dictate the implementation of either type of memory, statically allocated memory is typically reserved in data segment of the program at compile time, while the automatically allocated memory is normally implemented as a transient call stack.


/********************************************************************/
>Declaration vs Definition: In Summary

A declaration provides basic attributes of a symbol: its type and its name. A definition provides all of the details of that symbol--if it's a function, what it does; if it's a class, what fields and methods it has; if it's a variable, where that variable is stored. Often, the compiler only needs to have a declaration for something in order to compile a file into an object file, expecting that the linker can find the definition from another file. If no source file ever defines a symbol, but it is declared, you will get errors at link time complaining about undefined symbols.
Common Cases

If you want to use a function across multiple source files, you should declare the function in one header file (.h) and then put the function definition in one source file (.c or .cpp). All code that uses the function should include just the .h file, and you should link the resulting object files with the object file from compiling the source file.

If you want to use a class in multiple files, you should put the class definition in a header file and define the class methods in a corresponding source file. (You an also use inline functions for the methods.)

	If you want to use a variable in multiple files, you should put the declaration of the variable using the extern keyword in one header file, and then include that header file in all source files that need that variable. Then you should put the definition of that variable in one source file that is linked with all the object files that use that variable.


	>cc -c third.c -o third ( produces object file "third" , usually named as "third.o" )
	cc third fourth -o exec ( combines 2 object files third & fourth to produces final "executable" file )

	>Watch this out : 
	$$ file third exec 
	third: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
	exec:  ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0xb02a1cd2b9ca6d14c293a6e398ebc37913e60f04, not stripped
/********************************************************************/
>On doing : $file a.out  , it says (not stripped ) , so what is it ??

Ans1 :
There are two sets of symbols that gdb uses.
The -g set are debugging symbols, which make things a lot easier as they allow you to see your code and look at variables while debugging.
Another set of symbols is included by default when you compile. These are the linking symbols and live in the ELF (executable linkable format) symbol table. This contains a lot less info than the debug symbols, but contain the most important stuff, such as the addresses of the things in your executable (or library or object file). Without this information gdb won't even know where main is, so (gdb) break main would fail.
If you don't have the debugging symbols ( -g ) then you will still be able to (gdb) break main but you gdb will not have any concept of the lines of code in your source file. When you try to step through the code you will only advance 1 machine instruction at a time, rather than a line at a time.
The strip command is often used to strip off symbols from an executable (or other object file). This is often used if you don't want someone to be able to see the symbols or if you want to save space in the file. Symbol tables can get big. Strip removes both the debug symbols and the linker symbols, but it has several command line switches which can limit what it removes.
If you run the file command on your program one of the things it will tell you is weather or not the executable is has been stripped.

Ans2 :
The symbol table contains debugging information that tells a debugger what memory locations correspond to which symbols (like function names and variable names) in the original source code file. The symbol table is usually stored inside the executable, yes.
gdb is telling you that it can't find that table. If you compiled with gcc, unless you used the -g flag, it will not include the symbol table in the file. The easiest method is probably to recompile your file with -g. gdb should then automatically find the symbol table information.
Either add the -g flag to the command line arguments of gcc or to the Makefile that you used to compile the program. (A lot of times, there will be a variable called CFLAGS or similar inside the Makefile).
If you are trying to debug an arbitrary third-party program, a lot of times the information will have been "stripped" out of it. This is done to make reverse engineering harder and to make the size of the executable file smaller. Unless you have access to the source code and can compile the program yourself, you will have a very hard time using gdb on it.


	>after doing : $strip a.out , check out with : $nm a.out , ALL symbols are GONE !!

