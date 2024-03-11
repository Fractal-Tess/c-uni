#include "Header.h"
#include "Menu.h"

char *txt_menu_g[] = {"MENU:",
                      "Min and max",
                      "Numbers in interval",
                      "Average value",
                      "Replace negative numbers",
                      "Sum in interval",
                      "Exit",
                      NULL};

int main(void) {
  int choice;
  int total = 0;
  char fname[40]; // File for reading
  FILE *f1;

  puts("Input file name:");
  fgets(fname, sizeof(fname), stdin);
  fname[strlen(fname) - 1] = '\0';

  if (!(f1 = fopen(fname, "rt"))) {
    fprintf(stderr, "Input file not found\n");
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
      average(f1);
      getchar();
      break;

    case 4:
      change(f1);
      getchar();
      break;

    case 5:
      sum_in_inerval(f1);
      break;
    case 6:
      goto loop_end;
      break;

    default:
      getchar();
    }
  } while (1);

loop_end:
  // Close file
  fclose(f1);
  return 0;
}
