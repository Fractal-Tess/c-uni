#include "Header.h"

void my_line_flush() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}
void sum_in_inerval(FILE *f1) {
  int i = 0;
  float num;
  float sum = 0;
  float low, high;
  printf("Lower interval cut-off:");
  scanf("%f", &low);
  printf("Upper interval cut-off:");
  scanf("%f", &high);
  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // Reading of numbers
  {
    if (num >= low && num <= high) {
      sum += num;
      i++;
    }
  }
  if (!i)
    printf("No numbers in file!\n");
  else
    printf("Sum of numbers in interval = %.2f", sum);
}

void maxmin(FILE *f1) {
  int count = 0;
  float num, min, max;

  // Go to beggining of file cursor
  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // Read numbers
  {
    if (count == 0) {
      max = num;
      min = num;
    } else {
      if (num < min)
        min = num;
      if (num > max)
        max = num;
    }
    count++;
  }
  printf("max = %.2f\n", max);
  printf("min = %.2f\n", min);
  printf("Numbers in file = %d\n", count);
}

void interval(FILE *f1) {
  int i = 0;
  float num;
  FILE *f2;
  char fname[40];
  float low, high;

  printf("Lower interval cut-off:");
  scanf("%f", &low);

  printf("Upper interval cut-off:");
  scanf("%f", &high);

  puts("Name of file:");
  my_line_flush();
  fgets(fname, sizeof(fname), stdin);
  fname[strlen(fname) - 1] = '\0';

  if (!(f2 = fopen(fname, "wt"))) {
    fprintf(stderr, "Input file not found\n");
    exit(1);
  }

  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // Reading of numbers
  {
    if (num >= low && num <= high) {
      fprintf(f2, "%.2f ", num);
      i++;
    }
  }
  printf("The new file is created\n");
  printf("Count of numbers in interval = %d\n", i);
  fclose(f2);
}

void average(FILE *f1) {
  int i = 0;
  float num;
  float sum = 0;

  rewind(f1);
  while (fscanf(f1, "%f", &num) != EOF) // Reading of numbers
  {
    sum += num;
    i++;
  }
  if (!i)
    printf("No numbers in file!\n");
  else
    printf("Average value = %.2f", sum / i);
}

void change(FILE *f1) {
  int count = 0;
  float num;
  FILE *f2;
  char fname[40];

  puts("File name:");
  my_line_flush();

  fgets(fname, sizeof(fname), stdin);
  fname[strlen(fname) - 1] = '\0';
  if (!(f2 = fopen(fname, "wt"))) {
    fprintf(stderr, "Input file not found\n");
    exit(1);
  }
  rewind(f1);

  while (fscanf(f1, "%f", &num) != EOF) // Reading of numbers
  {
    if (num < 0) {
      // If negative number
      fprintf(f2, "%.2f ", -num);
      count++;
    } else
      fprintf(f2, "%.2f ", num);
  }
  printf("The new file is created!\n");
  printf("Count of negative numbers = %d\n", count);
}
