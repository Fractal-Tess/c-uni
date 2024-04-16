#include "Header.h"

void my_line_flush() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}
void maxmin(FILE *f1) {
  int i = 0;
  float num;
  float min, max;
  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // Chetene na chisla
  {
    if (i == 0) {
      max = num;
      min = num;
      i++;
    } else {
      if (num < min)
        min = num;
      if (num > max)
        max = num;
      i++;
    }
  }
  printf("max = %.2f\n", max);
  printf("min = %.2f\n", min);
  printf("Broi chisla vav faila = %d\n", i);
}

void interval(FILE *f1) {
  int i = 0;
  float num;
  FILE *f2;
  char fname[40];
  float left, right;
  printf("Dolna granica:");
  scanf("%f", &left);
  printf("Gorna granica:");
  scanf("%f", &right);
  puts("Ime na fail:");
  my_line_flush();
  fgets(fname, sizeof(fname), stdin);
  fname[strlen(fname) - 1] = '\0';
  if (!(f2 = fopen(fname, "wt"))) {
    fprintf(stderr, "input file not found\n");
    exit(1);
  }
  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // chetene na chisla

  {
    if (num >= left && num <= right)

    {
      fprintf(f2, "%.2f ", num);
      i++;
    }
  }
  printf("Noviat fail e sazdaden!\n");
  printf("Broi chisla v intervala = %d\n", i);
  fclose(f2);
}

void av(FILE *f1) {
  int i = 0;
  float num;
  float s = 0;
  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // chetene na chisla

  {
    s = s + num;
    i++;
  }
  if (!i)
    printf("Vav faila niama chisla!\n");
  else
    printf("Sredna stojnost = %.2f", s / i);
}

void change(FILE *f1) {
  int i = 0;
  float num;
  FILE *f2;
  char fname[40];
  puts("Ime na fajl:");
  my_line_flush();
  fgets(fname, sizeof(fname), stdin);
  fname[strlen(fname) - 1] = '\0';
  if (!(f2 = fopen(fname, "wt"))) {
    fprintf(stderr, "input file not found\n");
    exit(1);
  }
  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // chetene na chisla
  {
    if (num < 0) {
      fprintf(f2, "%.2f ", 0);
      i++;
    } else
      fprintf(f2, "%.2f ", num);
  }
  printf("Noviat fail e sazdaden!\n");
  printf("Broi otricatelni chisla = %d\n", i);
  fclose(f2);
}

int sumNumbersInInterval(FILE *f1, float left, float right) {
  int i = 0;
  float num;
  int sum = 0;
  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // chetene na chisla
  {
    if (num >= left && num <= right) {
      sum += num;
      i++;
    }
  }
  return sum;
}
