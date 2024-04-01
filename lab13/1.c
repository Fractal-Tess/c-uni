
#include <ctype.h> // Включваме библиотеката ctype.h за да използваме функцията ispunct()
#include <stdio.h>

FILE *writeFile(char *fname);
int readFile(FILE *fp, char *fname);
void replacePunctuation(FILE *fp, char *fname); // Декларираме новата функция

int main() {
  FILE *text;
  int symbols = 0;
  text = writeFile("Test.txt"); // Отваряне на текстов файл
  if (text == NULL) {
    printf("Failat ne moje da bade otvoren!");
    return 0;
  }
  symbols = readFile(text, "Test.txt");
  if (symbols >= 0)
    printf("\nbroi simvoli %d\n", symbols);
  else
    printf("Failat ne moje da bade otvoren!\n");

  replacePunctuation(
      text, "Test.txt"); // Извикваме функцията за замяна на препинателни знаци

  symbols = readFile(text, "Test.txt"); // Прочитаме отново файла след замяната
  if (symbols >= 0)
    printf("\nbroi simvoli %d\n", symbols);
  else
    printf("Failat ne moje da bade otvoren!\n");

  return 0;
}

FILE *writeFile(char *fname) {
  FILE *fp;
  int ch;
  fp = fopen(fname, "w");
  if (!fp)
    return NULL;
  printf("Vavedaite simvoli. Za krai vavedete: # + Enter.\n");
  fflush(stdin);
  while ((ch = getchar()) != '#')
    fputc(ch, fp);
  fclose(fp);
  return fp;
}

int readFile(FILE *fp, char *fname) {
  int ch, n = 0;
  fp = fopen(fname, "r");
  if (!fp)
    return -1;
  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
    n++;
  }
  fclose(fp);
  return n;
}

void replacePunctuation(FILE *fp, char *fname) {
  FILE *temp;
  int ch;
  temp = fopen("temp.txt", "w"); // Отваряме временен файл за запис
  fp = fopen(fname, "r"); // Отваряме оригиналния файл за четене
  if (!fp || !temp) {
    printf("Greshka pri otvarqne na failove!");
    return;
  }
  while ((ch = fgetc(fp)) != EOF) {
    if (ispunct(ch)) // Проверяваме дали символът е препинателен знак
      fputc('x', temp); // Ако е, записваме 'x' вместо него във временния файл
    else
      fputc(ch, temp); // Ако не е, записваме същия символ
  }
  fclose(fp);
  fclose(temp);

  remove(fname); // Изтриваме оригиналния файл
  rename("temp.txt", fname); // Преименуваме временния файл като оригиналния
}
