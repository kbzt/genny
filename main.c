#include <stdio.h>
#include <bsd/stdlib.h>

static uint8_t symbols[70];

void initSymbols() {
    for (unsigned i = 0; i <= 25; i++) {
        symbols[i] = (i + 65);
        symbols[i + 26] = (i + 97);
    }
    
    for (unsigned i = 52; i <= 63; i++) {
        symbols[i] = (i - 4);
    }

    symbols[62] = 33;
    symbols[63] = 35;
    symbols[64] = 36;
    symbols[65] = 37;
    symbols[66] = 38;
    symbols[67] = 42;
    symbols[68] = 64;
    symbols[69] = 94;  
}

int main(int argc, char const *argv[]) {
    initSymbols();  

    unsigned i = 0;
    while (i < 32) {
        uint8_t n = arc4random_uniform(69);
        fprintf(stdout, "%c", symbols[n]);
        i++;
    }
    
    putc('\n', stdout);
    return 0;
}