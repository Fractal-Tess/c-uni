#include "Header.h"

FILE *input(FILE *f1) {
  int i;
  Point P;
  printf("Vavedete koordinati za 5 tochki:\n");
  for (i = 0; i < 5; i++)

  {
    printf("x = ");
    scanf("%d", &P.x);
    printf("y = ");
    scanf("%d", &P.y);
    fwrite(&P, sizeof(P), 1, f1);
  }
  fclose(f1);
  return f1;
}

void positiv(FILE *f1) {
  int i, flag = 0;
  Point P;
  for (i = 0; i < 5; i++) {
    fread(&P, sizeof(P), 1, f1);
    if ((P.x > 0) && (P.y > 0)) {
      printf("x = %d ", P.x);
      printf("y = %d ", P.y);
      printf("\n");
      flag = 1;
    }
  }
  if (flag == 0)
    printf("Niama tochki s dve polojitelni koordinati!\n");
  fclose(f1);
}

void negativ(FILE *f1) {
  int i, flag = 0;
  Point P;
  for (i = 0; i < 5; i++) {
    fread(&P, sizeof(P), 1, f1);
    if ((P.x < 0) && (P.y < 0)) {
      printf("x = %d ", P.x);
      printf("y = %d ", P.y);
      flag = 1;
    }
  }
  if (flag == 0)
    printf("Niama tochki s dve otricatelni koordinati!\n");
  fclose(f1);
}

void posneg(FILE *f1) {
  int i;
  Point P;
  for (i = 0; i < 5; i++) {
    fread(&P, sizeof(P), 1, f1);
    if ((P.x > 0 && P.y < 0) || (P.x < 0 && P.y > 0)) {
      printf("Point %d has an x  of %d  and y of %d", i, P.x, P.y);
      printf("\n");
    }
  }
  fclose(f1);
}
