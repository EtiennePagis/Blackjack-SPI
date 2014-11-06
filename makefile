Prog: carte.o mains.o score.o projet.o
	gcc -o Prog carte.o mains.o score.o projet.o -Wall
carte.o: carte.c
	gcc -o carte.o -c carte.c -Wall
mains.o: mains.c
	gcc -o mains.o -c mains.c -Wall
score.o: score.c
	gcc -o score.o -c score.c -Wall
projet.o: projet.c carte.h mains.h score.h
	gcc -o projet.o -c projet.c -Wall
