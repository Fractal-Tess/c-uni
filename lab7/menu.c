#include "Header.h"

int menu(char *t[]) {
  int k;
  int ch;
  printf("\n%s\n", t[0]);
  for (int i = 0; (t[i]); i++) {
    printf("\n<%d> - %s", i, t[i]);
  }
  printf("\n\nIzberete : ");
  scanf("%d", &ch);
  return ch;
}
