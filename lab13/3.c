
#include <stdio.h>
#include <stdlib.h>

FILE *writeFile(char *fname);
void readFile(FILE *fp, char *fname);
int countNumbers(FILE *fp, char *fname); // Декларираме новата функция

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

  int numbers = countNumbers(
      text, fname); // Извикваме функцията за преброяване на числата
  if (numbers >= 0)
    printf("\nBroi chisla: %d\n", numbers);
  else
    printf("Failat ne moje da bade otvoren!\n");

  return 0;
}

FILE *writeFile(char *fname) {
  FILE *fp;
  int a = 0;
  fp = fopen(fname, "w");
  if (!fp)
    return NULL;
  printf("Vaejdaite celi chisla. Za krai natisnete: Ctrl+Z.\n");
  while (scanf("%d", &a) == 1)
    fprintf(fp, "%d ", a);
  fclose(fp);
  return fp;
}

void readFile(FILE *fp, char *fname) {
  int a = 0;
  fp = fopen(fname, "r");
  if (!fp)
    exit(1);
  while (fscanf(fp, "%d", &a) == 1)
    printf("%d ", a);
  fclose(fp);
}

int countNumbers(FILE *fp, char *fname) {
  int numbers = 0;
  int a;
  fp = fopen(fname, "r");
  if (!fp)
    return -1;
  while (fscanf(fp, "%d", &a) == 1) {
    numbers++; // Увеличаваме броя на числата с всеки успешно прочетено число
  }
  fclose(fp);
  return numbers;
}
