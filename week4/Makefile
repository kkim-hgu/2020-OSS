main : main.c members.o
	gcc -o main main.c members.o

members.o : members.c members.h
	gcc -c members.c -o members.o

clean :
	rm *.o main
