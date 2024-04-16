#include "Header.h"
#include <stdio.h>

char *txt_menu_g[] = {"MENU:",
                      "Minimum i maksimum",
                      "Chisla v interval",
                      "Sredno aritmetichna stoinost",
                      "Zamiana na otricatelnite chisla",
                      "Sum ot chisla v interval",
                      "Izhod",
                      NULL};

int main() {
  int choice;
  int total = 0;
  char fname[40]; // imeto na faila za chetene
  FILE *f1;

  int sum;
  float left, right;

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
      printf("Dolna granica: ");
      scanf("%f", &left);
      printf("Gorna granica: ");
      scanf("%f", &right);
      sum = sumNumbersInInterval(f1, left, right);
      printf("Sumata e :%d", sum);
      break;
    case 6:
      exit(1);
      break;
    default:
      getchar();
    }
  } while (1);
  fclose(f1);
  return 0;
}
