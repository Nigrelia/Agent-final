agent2:agent2.o main2.o
	gcc agent2.o main2.o -o agent2
agent2.o:agent2.c
	gcc -c agent2.c
main2.o:main2.c
	gcc -c main2.c
