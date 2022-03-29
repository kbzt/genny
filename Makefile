cc = gcc
cflags = -Og -Wextra -Wall -lbsd

genny: main.o
	gcc $(cflags) -o genny main.o

clean: 
	rm genny *.o
