#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include "assutils.c"

FILE* txt;
FILE* bin;

int main(int argc, char** argv) {

  if (argc < 3){
    printf("Error: not enough files provided!\n");
    return 1;
  } else {
    txt = fopen(argv[1], "r");
    if (txt == NULL) {
      printf("Error: unable to open \"%s\"!\n", argv[1]);
      return 2;
    }
    bin = fopen(argv[2], "wb");
    if (bin == NULL) {
      printf("Error: unable to create or open \"%s\"!\n", argv[2]);
      return 3;
    }
  }

  int maxlen = longestLine(txt);
  printf("Max line length: %d\n", maxlen);

  int numLines = lenFile(txt, maxlen);
  printf("Number of lines: %d\n", numLines);

  char** lines = malloc(numLines*sizeof(char*));
  extractLines(txt, lines, maxlen);
  clean(lines, numLines);

  for (int i = 0; i < numLines; i++){
    printf("%s", lines[i]);
  }

  char** tokens = malloc(10*sizeof(char*));
  int numTokens = tokCmd(tokens, lines[0]);

  for (int i = 0; i < numTokens; i++){
    printf("%s\n", tokens[i]);
  }

  free2d(tokens, 10);
  //free(bigg);
  fclose(txt);
  fclose(bin);
  return 0;
}
