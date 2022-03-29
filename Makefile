cc = gcc
cflags = -O2 -Wextra -Wall -lbsd -std=c11

genny: main.o
	gcc $(cflags) -o genny main.o

install:
	install -Dm 755 "genny" "/usr/bin/genny" 

uninstall:
	rm /usr/bin/genny

clean: 
	rm genny *.o