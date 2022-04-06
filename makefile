CC=clang
PROJ=genny

SRC_PATH=src
OBJ_PATH=.obj
SRC=$(wildcard $(SRC_PATH)/*.c)
OBJ=$(patsubst $(SRC_PATH)/%,$(OBJ_PATH)/%,$(SRC:.c=.o))

CFLAGS=-ggdb3 -Og -Wall -Wextra -pedantic-errors -fstrict-aliasing -std=c99
LFLAGS=-lbsd

all: debug

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $< $(CFLAGS) 

debug: $(OBJ)
	$(CC) -o $(PROJ) $^ $(LFLAGS)
	
install:
	install -Dm 755 $(PROJ) "/usr/bin/genny" 

uninstall:
	rm -f /usr/bin/genny

clean: 
	rm -rf $(OBJ)
	rm -f $(PROJ)