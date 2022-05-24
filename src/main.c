#include <stdio.h>
#include <getopt.h>
#include <bsd/stdlib.h>

#define default_length 14

static uint8_t symbols[70];
static u_int8_t tracker = 0;

void
printUsage() {
    puts("\nusage: genny [args] [value]\n");

    puts("  -h \tshow this help and exit.");
    puts("  -n \tdisable numbers (0-9)");
    puts("  -a \tdisable alphas (A-Z, a-z)");
    puts("  -s \tdisable special characters (!#$%&*@^)");
    puts("  -l \tspecify a length (default: 14)");

    puts("\nexamples:\n  genny -al 22");
    puts("  genny -l 30 -a -s\n");
}
void 
errorMsg(const char * msg) {
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}

void
addToArr(const uint8_t c) {
    symbols[tracker] = c;
    tracker++;
}

uint8_t
initSymbols(const uint8_t useNum, const uint8_t useSpecChar, const uint8_t useAlpha) {
    
    uint8_t size = 0;

    // A-Z, a-z
    if (useAlpha){
        for (unsigned i = 0; i <= 25; i++) {
            addToArr(i + 65);
        }

        for (unsigned i = 0; i <= 25; i++) {
            addToArr(i + 97);
        }

        size += 52;
    }

    // 0-9
    if (useNum) {
        for (unsigned i = 48; i <= 57; i++) {
            addToArr(i);
        }

        size += 10;
    }

    if (useSpecChar){
        addToArr(33); //!
        addToArr(35); //#
        addToArr(36); //$
        addToArr(37); //%
        addToArr(38); //&
        addToArr(42); //*
        addToArr(64); //@
        addToArr(94); //^

        size += 8;
    }

    return size;
}

int 
main(int argc, char ** argv) {

    u_int8_t useNum = 1, useSpecChars = 1, useAlpha = 1;
    int64_t length, i = 0, n;
    int8_t opt;
    char *length_str = NULL;
    
    while ((opt = getopt(argc, argv, "nsahl:")) != -1) {
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
            case 'h':
                printUsage();
                exit(EXIT_SUCCESS);
            case 'l': 
                length_str = optarg;
                break;
            default:
                errorMsg("use genny -h for usage\n");
                break;
        }
    }

    uint8_t size = initSymbols(useNum, useSpecChars, useAlpha);  
    length = strtol(length_str, NULL, 10);
    
    if (length <= 0)
        length = default_length;

    while (i < length) {
        n = arc4random_uniform(size);
        fprintf(stdout, "%c", symbols[n]);
        i++;
    }

    putc('\n', stdout);
    exit(EXIT_SUCCESS);
}
