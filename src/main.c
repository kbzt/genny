#include <stdio.h>
#include <getopt.h>
#include <bsd/stdlib.h>

#include "types.h"

static u8 symbols[70];
static u8 tracker = 0;

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
addToArr(const u8 c) {
  symbols[tracker] = c;
  tracker++;
}

u8 
initSymbols(const u8 useNum, const u8 useSpecChar, const u8 useAlpha) {
  u8 size = 0;

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
  u8 useNum = 1, useSpecChars = 1, useAlpha = 1;
  i64 length = 14, i = 0, n;
  i8 opt;
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

  u8 size = initSymbols(useNum, useSpecChars, useAlpha);

  if (length_str != NULL)
      length = strtol(length_str, NULL, 10);

  if (length <= 0)
    length = 14;

  while (i < length) {
    n = arc4random_uniform(size);
    fprintf(stdout, "%c", symbols[n]);
    i++;
  }

  putc('\n', stdout);
  exit(EXIT_SUCCESS);
}