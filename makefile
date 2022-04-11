PROJ=genny

CC=clang
CFLAGS=-ggdb3 -Og -Wall -Wextra -pedantic-errors -fstrict-aliasing -pipe -std=c11
LFLAGS=-lbsd

SRC_PATH=src
OBJ_PATH=.obj
SRC=$(wildcard $(SRC_PATH)/*.c)
OBJ=$(patsubst $(SRC_PATH)/%,$(OBJ_PATH)/%,$(SRC:.c=.o))

all: debug

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $< $(CFLAGS) 

debug: $(OBJ)
	$(CC) -o $(PROJ) $^ $(LFLAGS)
	
install:
	install -Dm 755 $(PROJ) "/usr/bin/$(PROJ)" 

uninstall:
	rm -f /usr/bin/$(PROJ)

clean: 
	rm -rf $(OBJ)
	rm -f $(PROJ)