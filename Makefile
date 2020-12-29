CC=gcc
AR=ar
FLAGS= -Wall -g


all: isort txtfind

isort: mainSort.o isort.o
	$(CC) $(FLAGS) mainSort.o isort.o -o isort


txtfind: mainTxt.o txtfind.o
	$(CC) $(FLAGS) mainTxt.o txtfind.o -o txtfind


mainSort.o: mainSort.c  isort.h
	$(CC) $(FLAGS) -c mainSort.c


isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c


mainTxt.o: mainTxt.c txtfind.h 
	$(CC) $(FLAGS) -c mainTxt.c


txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c



.PHONY: clean all isort txtfind

clean: 
	rm -f isort txtfind *.o