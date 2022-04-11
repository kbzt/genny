#include <stdio.h>
#include <getopt.h>
#include <bsd/stdlib.h>

#define default_length 14

static uint8_t symbols[70];

void 
errorMsg(const char * msg) {
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}

uint8_t
initSymbols(const uint8_t useNum, const uint8_t useSpecChar, const uint8_t useAlpha) {
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

    return 0;
}

int 
main(int argc, char ** argv) {

    u_int8_t useNum = 1, useSpecChars = 1, useAlpha = 1, length;

    int8_t opt;
    char *length_str = NULL;
    
    while ((opt = getopt(argc, argv, "nsal:")) != -1) {
        switch (opt) {
            case 'n':
                useNum = 0;
                break;
            case 's':
                useSpecChars = 0;
                break;
            case 'a':
                useAlpha = 0;
                break;
            case 'l': 
                length_str = optarg;
                break;
            default:
                errorMsg("error: input options are invalid\n");
                break;
        }
    }

    uint8_t size = initSymbols(useNum, useSpecChars, useAlpha);  
    
    length = strtol(length_str, NULL, 10);
    
    if (length <= 0)
        length = default_length;

    int8_t i = 0;
    while (i < length) {
        uint8_t n = arc4random_uniform(69);
        fprintf(stdout, "%c", symbols[n]);
        i++;
    }
    
    putc('\n', stdout);
    exit(EXIT_SUCCESS);
}
