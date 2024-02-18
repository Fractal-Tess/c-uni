#include "Header.h"
#include "Menu.h"

char *txt_menu_g[] = {"MENU:",
                      "Minimum i maksimum",
                      "Chisla v interval",
                      "Sredno aritmetichna stoinost",
                      "Zamiana na otricatelnite chisla",
                      "Izhod",
                      NULL};

int main(void) {
  int choice;
  int total = 0;
  char fname[40]; // imeto na faila za chetene
  FILE *f1;

  puts("Vavedete ime na fail:");
  fgets(fname, sizeof(fname), stdin);
  fname[strlen(fname) - 1] = '\0';

  if (!(f1 = fopen(fname, "rt"))) {
    fprintf(stderr, "input file not found\n");
    exit(1);
  }

  do {
    choice = menu(txt_menu_g);
    switch (choice) {
    case 1:
      maxmin(f1);
      getchar();
      break;
    case 2:
      interval(f1);
      getchar();
      break;
    case 3:
      av(f1);
      getchar();
      break;
    case 4:
      change(f1);
      getchar();
      break;
    case 5:
      exit(1);
      break;
    default:
      getchar();
    }
    system("cls");
  } while (1);
  fclose(f1);
  return 0;
}
