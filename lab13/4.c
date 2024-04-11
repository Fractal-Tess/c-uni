
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[30];
  long nmbr;
  int group;
  float mark;
} student;

student inputStudent(void);
void outputStudent(student);
FILE *writeFile(char *filename);
void readFile(FILE *fp, char *filename);
float avMark(FILE *fp, char *filename, int searchGroup);
void searchByNumber(FILE *fp, char *filename, long searchNumber);

int main() {
  FILE *fp;
  char filename[30];
  int searchGroup;
  long searchNumber;
  float averageMark;

  printf("Vavedete ime za faila: ");
  fgets(filename, 30, stdin);
  filename[strcspn(filename, "\n")] = '\0';
  fp = writeFile(filename);

  printf("\nDanni za vsichki studeni:\n");
  readFile(fp, filename);

  printf("\nVavedete nomer na grupa: ");
  scanf("%d", &searchGroup);
  averageMark = avMark(fp, filename, searchGroup);
  if (!averageMark)
    printf("\nNqma vavedeni studenti ot grupa %d!", searchGroup);
  else
    printf("Srednia uspeh ha grupa %d e: %f\n", searchGroup, averageMark);

  printf("\nVavedete fakulteten nomer za tursene: ");
  scanf("%ld", &searchNumber);
  searchByNumber(fp, filename, searchNumber);

  return 0;
}

student inputStudent(void) {
  student a;
  printf("\nName: ");
  fflush(stdin);
  fgets(a.name, 30, stdin);
  a.name[strcspn(a.name, "\n")] = '\0';

  printf("Number: ");
  scanf("%ld", &a.nmbr);
  printf("Group: ");
  scanf("%d", &a.group);
  printf("Mark: ");
  scanf("%f", &a.mark);
  fflush(stdin);
  return (a);
}

void outputStudent(student st) {
  printf("\nName: %s\n", st.name);
  printf("Number: %ld\n", st.nmbr);
  printf("Group: %d\n", st.group);
  printf("Mark: %.2f\n", st.mark);
}

FILE *writeFile(char *filename) {
  FILE *fp;
  student s;
  if ((fp = fopen(filename, "ab")) ==
      NULL) { /* Отваряне на двоичен файл за запис*/
    printf("Fail %s ne moje da bade otvoren.\n ", filename);
    exit(1);
  }
  do {
    s = inputStudent();
    fwrite(&s, sizeof(s), 1, fp); /*Запис на една структура-студент във файла*/
    printf("Nov student? Y/N: ");

    int ch;
    while (ch == '\n')
      ch = getchar();
  } while (toupper(getchar()) == 'Y');
  fclose(fp);
  printf("\nFailat e sazdaden! \n");
  return (fp);
}

void readFile(FILE *fp, char *filename) {
  student s;
  int flag = 0;
  if ((fp = fopen(filename, "rb")) ==
      NULL) { /* Отваряне на двоичен файл за четене*/
    printf("Fail %s ne moje da bade otvoren.\n ", filename);
    exit(1);
  }
  while (fread(&s, sizeof(s), 1, fp) == 1) /*Четене на една структура от файла*/
    outputStudent(s);
  fclose(fp);
}

float avMark(FILE *fp, char *filename, int searchGroup) {
  student s;
  float avr = 0.0;
  int count = 0;
  if ((fp = fopen(filename, "rb")) ==
      NULL) { /*Отваряне на двоичен файл за четене*/
    printf("Fail %s ne moje da bade otvoren.\n ", filename);
    exit(1);
  }
  while (fread(&s, sizeof(student), 1, fp) == 1)
    if (s.group == searchGroup) {
      count++;
      avr += s.mark;
    }
  fclose(fp);
  if (count == 0)
    return 0.0;
  else
    return (avr / count);
}

void searchByNumber(FILE *fp, char *filename, long searchNumber) {
  student s;
  int found = 0;
  if ((fp = fopen(filename, "rb")) ==
      NULL) { /*Отваряне на двоичен файл за четене*/
    printf("Fail %s ne moje da bade otvoren.\n ", filename);
    exit(1);
  }
  while (fread(&s, sizeof(student), 1, fp) == 1) {
    if (s.nmbr == searchNumber) {
      printf("\nStudent found with the following details:\n");
      outputStudent(s);
      found = 1;
      break;
    }
  }
  fclose(fp);
  if (!found)
    printf("\nStudent s fakulteten nomer %ld ne e nameren!\n", searchNumber);
}
