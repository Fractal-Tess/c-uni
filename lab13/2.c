
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *writeFile(char *fname);
void readFile(FILE *fp, char *fname);
int countLines(FILE *fp, char *fname); // Декларираме новата функция

int main() {
  FILE *text;
  char fname[20];
  printf("Vavedete ime za faila s razshirenie txt:\n");
  scanf("%s", &fname);
  text = writeFile(fname);
  if (text == NULL) {
    printf("Failat ne moje da bade otvoren!");
    return 0;
  }
  readFile(text, fname);

  int lines =
      countLines(text, fname); // Извикваме функцията за преброяване на редовете
  if (lines >= 0)
    printf("\nBroi redove: %d\n", lines);
  else
    printf("Failat ne moje da bade otvoren!\n");

  return 0;
}

FILE *writeFile(char *fname) {
  FILE *fp;
  char s[81];
  fp = fopen(fname, "w");
  if (!fp)
    return NULL;
  printf("Vaejdaite stringove. Za krai natisnete: Ctrl+Z.\n");
  fflush(stdin);
  while (fgets(s, 80, stdin) != NULL)
    fputs(s, fp);
  fclose(fp);
  return fp;
}

void readFile(FILE *fp, char *fname) {
  char s[81];
  fp = fopen(fname, "r");
  if (!fp)
    exit(1);
  while (fgets(s, 80, fp) != NULL)
    fputs(s, stdout);
  fclose(fp);
}

int countLines(FILE *fp, char *fname) {
  int lines = 0;
  char ch;
  fp = fopen(fname, "r");
  if (!fp)
    return -1;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') // Ако символът е нов ред, увеличаваме броя на редовете
      lines++;
  }
  fclose(fp);
  return lines;
}
