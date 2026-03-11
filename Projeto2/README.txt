Lorena Silveira dos Santos, 2312667 3WC

This C function cria_func generates x86-64 machine code at runtime to dynamically call a target function with given parameters (integers or pointers). It handles fixed and indirect values, writes the assembly instructions into a buffer, and allows dynamic function invocation at runtime.

Overview:
The program worked as expected during the tests performed, correctly translating and executing the functions provided on the assignment website.

Tests performed:
No parameters sent in the function call
1, 2, and 3 parameters sent in the function call

	(PARAM, IND, FIX)
	(PARAM, FIX, IND)
	(PARAM, IND, IND)
	(PARAM, FIX, FIX)
	(PARAM, PARAM)
	(PARAM, FIX)
	(PARAM, IND)
	(IND, IND)
	(FIX, IND)
	(FIX, FIX)
	(IND, FIX):
	(IND, PARAM):
	(FIX, PARAM):
	(PARAM)
