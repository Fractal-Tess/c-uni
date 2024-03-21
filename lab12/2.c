#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[30];
  long id;
  int group;
  float grade;
} STD;

void flushInput();
STD *inputStd(int b, STD *s);
void outputStd(int b, STD *s);
void success(int b, STD *s);
void print_students_from_group(int b, STD *s);

int main() {
  int i, num = 0, sum = 0;
  STD *s;
  printf("Enter number of students:");
  scanf("%d", &num);
  s = (STD *)malloc(num * sizeof(STD));
  if (s == NULL) {
    printf("ERROR!\n");
    exit(1);
  }
  s = inputStd(num, s);
  printf("\nList of students:\n");
  outputStd(num, s);
  success(num, s);

  print_students_from_group(num, s);
  return 0;
}

void flushInput() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

STD *inputStd(int b, STD *s) {
  for (int i = 0; i < b; i++) {
    printf("\nInput for student number %d:\n", i + 1);
    printf("Name: ");
    flushInput();
    fgets((s + i)->name, 30, stdin);
    printf("ID: ");
    scanf("%ld", &(s + i)->id);
    printf("Group number: ");
    scanf("%d", &(s + i)->group);
    printf("Grade: ");
    scanf("%f", &(s + i)->grade);
  }
  return s;
}

void outputStd(int b, STD *s) {
  for (int i = 0; i < b; i++) {
    printf("\nName: %s", (s + i)->name);
    printf("\nID: %ld\n", (s + i)->id);
    printf("Group: %d\n", (s + i)->group);
    printf("Grade: %.2f\n", (s + i)->grade);
  }
}

void success(int b, STD *s) {
  float sum = 0.0;
  int gr = 0, key;
  flushInput();
  printf("Enter group number: ");
  scanf("%d", &key);
  for (int i = 0; i < b; i++)
    if ((s + i)->group == key) {
      sum += (s + i)->grade;
      gr++;
    }
  if (gr > 0)
    printf("Average grade of students from group %d: %.2f\n", key, sum / gr);
  else
    printf("No students from group %d!\n", key);
}

void print_students_from_group(int b, STD *s) {
  int group;
  printf("\n\nPrint students from group: ");
  printf("\nEnter group number: ");
  scanf("%d", &group);
  for (int i = 0; i < b; i++)
    if ((s + i)->group == group) {
      printf("Name: %s", (s + i)->name);
      printf("ID: %ld\n", (s + i)->id);
      printf("Group: %d\n", (s + i)->group);
      printf("Grade: %.2f\n", (s + i)->grade);
      printf("\n");
    }
}
