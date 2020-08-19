void newExp(regex_t *compiled, const char* exp) {
  int status = regcomp(compiled, exp, 0);
  if (status != 0) {
    printf("Error in compiling regex \"%s\"!\n", exp);
    exit(0);
  }
}

int longestLine(FILE* input) {
  int longest = 0;
  int current = 0;
  char c;
  while ((c = fgetc(input)) != EOF) {
    if (c == '\n') {
      if (current > longest) {
        longest = current;
      }
      current = 0;
    } else {
      current++;
    }
  }
  rewind(input);
  return longest;
}

int lenFile(FILE* input, int maxLen) {
  regex_t anychar;
  regex_t comment;
  char line[maxLen];
  rewind(input);
  newExp(&anychar, "[A-z_0-9{},]");
  newExp(&comment, "^ *//");
  int len = 0;

  while (fgets(line, maxLen, input) != NULL) {
    if (regexec(&anychar, line, 0, NULL, 0) == 0 &&
        regexec(&comment, line, 0, NULL, 0) != 0){
      len++;
    }
  }
  rewind(input);
  return len;
}

void extractLines(FILE* input, char** lines, int maxLen) {
  int currentLine = 0;
  regex_t anychar;
  regex_t comment;
  char line[maxLen];
  rewind(input);
  newExp(&anychar, "[A-z_0-9{},]");
  newExp(&comment, "^ *//");

  while (fgets(line, maxLen, input) != NULL) {
    if (regexec(&anychar, line, 0, NULL, 0) == 0 &&
        regexec(&comment, line, 0, NULL, 0) != 0){
      lines[currentLine] = malloc((strlen(line) + 1)*sizeof(char));
      strcpy(lines[currentLine++], line);
    }
  }
  rewind(input);
}

void clean(char** lines) {

}

int tokCmd(char** dest, char* src) {

  int len = strlen(src);

  char* copy = malloc(sizeof(char)*len);
  strcpy(copy, src);

  int index = 0;
  char* token = strtok(copy, ", \n");
  while (token != NULL) {
    len = strlen(token);
    dest[index] = malloc(len*sizeof(char));
    strcpy(dest[index], token);
    index += 1;
    token = strtok(NULL, ", \n");
  }
  free(copy);
  return index;
}

void free2d(char** arr, int len) {
  for (int i = 0; i < len; i++){
    free(arr[i]);
  }
  free(arr);
}
