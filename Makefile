CC = gcc
CFLAGS = -Wall

all: jeopardy

jeopardy: main.o questions.o players.o jeopardy.o
    $(CC) $(CFLAGS) -o jeopardy main.o questions.o players.o jeopardy.o

main.o: main.c jeopardy.h
    $(CC) $(CFLAGS) -c main.c

questions.o: questions.c questions.h
    $(CC) $(CFLAGS) -c questions.c

players.o: players.c players.h
    $(CC) $(CFLAGS) -c players.c

jeopardy.o: jeopardy.c jeopardy.h
    $(CC) $(CFLAGS) -c jeopardy.c

clean:
    rm -f *.o jeopardy
