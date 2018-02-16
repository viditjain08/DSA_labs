compileAll : ex1.o ex2.o ex2driver.o
	gcc ex1.o ex2.o ex2driver.o -o exe
ex1.o : ex1.c info.h
	gcc -c ex1.c
ex2.o : ex2.c info.h
	gcc -c ex2.c
ex2driver.o : ex2driver.c info.h
	gcc -c ex2driver.c
