ex3: ex3.o compRecMS ex3driver.o
	gcc -pg ex3.o merge.o mergeRec.o ex3driver.o -o prog

compRecMS : merge.o mergeRec.o

compIterMS : merge.o mergeIter.o

runRecMS : merge.o mergeRec.o driverRec.o
	gcc merge.o mergeRec.o driverRec.o -o prog

runIterMS : merge.o mergeIter.o driverIter.o
	gcc merge.o mergeIter.o driverIter.o -o prog

ex3driver.o: ex3driver.c ex1.h ex3.h
	gcc -c -g ex3driver.c
ex3.o: ex3.c ex3.h ex1.h
	gcc -c -g ex3.c
merge.o : merge.c ex1.h
	gcc -c -g merge.c
mergeRec.o : mergeRec.c ex1.h
	gcc -c -g mergeRec.c
mergeIter.o : mergeIter.c ex1.h
	gcc -c -g mergeIter.c
driverRec.o : driverRec.c ex1.h
	gcc -c -g driverRec.c
driverIter.o : driverIter.c ex1.h
	gcc -c -g driverIter.c
