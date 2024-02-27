CC = gcc
CFLAGS = -Wall -Wextra

build: main.c
	$(CC) $(CFLAGS) -o main main.c

run:
	./main $(INPUT) $(OUTPUT)

check:
	../checker/checker.sh
