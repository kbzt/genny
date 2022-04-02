CC=clang

SRC_PATH=src
OBJ_PATH=.obj
PROJ_NAME=genny

CFLAGS=-Og -Wextra -Wall -std=c11
LFLAGS=-lbsd

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -o $(CFLAGS) 

genny: main.o
	$(CC) $(CFLAGS) -o genny main.o

install:
	install -Dm 755 "genny" "/usr/bin/genny" 

uninstall:
	rm /usr/bin/genny

clean: 
	rm -rf $(OBJ)
	rm -f genny
