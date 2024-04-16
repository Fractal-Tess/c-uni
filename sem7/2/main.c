#include "Header.h"

char *txt_menu_g[] = {
    "MENU:",
    "Vavejdane na danni",
    "Polovitelni tochki",
    "Otricatelni tochki",
    "Namirane na tochki s edna polojitelna i edna otricatelna koordinata",
    "Izhod",
    NULL};
int main() {
  int choice;
  int total = 0;
  char fname[40]; // imeto na faila za chetene
  FILE *f1;

  puts("Vavedete ime na fail:");
  fgets(fname, sizeof(fname), stdin);
  fname[strlen(fname) - 1] = '\0';
  do {
    choice = menu(txt_menu_g);
    switch (choice) {
    case 1:
      if (!(f1 = fopen(fname, "wb"))) {
        fprintf(stderr, "input file not found\n");
        exit(1);
      }
      f1 = input(f1);
      getchar();
      break;
    case 2:
      if (!(f1 = fopen(fname, "rb"))) {
        fprintf(stderr, "input file not found\n");
        exit(1);
      }
      positiv(f1);
      getchar();
      break;
    case 3:
      if (!(f1 = fopen(fname, "rb"))) {
        fprintf(stderr, "input file not found\n");
        exit(1);
      }
      negativ(f1);
      getchar();
      break;
    case 4:
      if (!(f1 = fopen(fname, "rb"))) {
        fprintf(stderr, "input file not found\n");
        exit(1);
      }
      posneg(f1);
      break;
    case 5:
      exit(1);
      break;
    default:
      getchar();
    }
  } while (1);
  return 0;
}
