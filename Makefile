CC=gcc
CFLAGS=-g -Wall -lpthread
EXEC=jeu


all:$(EXEC)

jeu: main.o function.o joueurVJoueur.o joueurVComputer.o computerVComputer.o essai.o
			$(CC) -o jeu main.o function.o joueurVJoueur.o joueurVComputer.o computerVComputer.o essai.o $(CFLAGS)

function.o: function.c
			$(CC) -o function.o -c function.c $(CFLAGS)

joueurVJoueur.o: joueurVJoueur.c
			$(CC) -o joueurVJoueur.o -c joueurVJoueur.c $(CFLAGS)

joueurVComputer.o: joueurVComputer.c
			$(CC) -o joueurVComputer.o -c joueurVComputer.c $(CFLAGS)

computerVComputer.o: computerVComputer.c
			$(CC) -o computerVComputer.o -c computerVComputer.c $(CFLAGS)

essai.o: essai.c
			$(CC) -o essai.o -c essai.c $(CFLAGS)

main.o: main.c function.h joueurVJoueur.h joueurVComputer.h computerVComputer.h essai.h
			$(CC) -o main.o -c main.c $(CFLAGS)

clean:
			rm -rf *.o