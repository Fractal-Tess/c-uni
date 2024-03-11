#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define STEP 5

char *M[SIZE] = {"1-Input", "2-Output", "3-Sort", "4-Sum in interval",
                 "5-Exit"};

int *input(int *br, int *mas);
void out(int br, int *mas);
void sort(int br, int *mas);
void sum_in_inerval(int br, int *mas);

int main() {
  int cod, n = 0, *p = NULL, flag = 0;
  do {
    for (int i = 0; i < SIZE; i++) {
      puts(M[i]);
    }

    printf("Chose menu option:");
    scanf("%d", &cod);

    switch (cod) {
    case 1:
      p = input(&n, p);
      flag = 1;
      break;
    case 2:
      if (flag == 1)
        out(n, p);
      else
        printf("Fill the array first!\n");
      break;
    case 3:
      if (flag == 1) {
        printf("Starting array:\n");
        out(n, p);
        sort(n, p);
      } else
        printf("Fill the array first!\n");
      getchar();
      break;
    case 4:
      if (flag == 1) {
        sum_in_inerval(n, p);
      } else
        printf("Fill the array first!\n");
      getchar();
      break;
    case 5:
      if (p != NULL) {
        free(p);
        printf("Freeing memory ( array )\n");
        p = NULL;
      }
      exit(1);
      break;
    default:
      printf("Incorrect choice!\n");
      getchar();
    }
  } while (1);
  return 0;
}

int *input(int *br, int *mas) {
  int n = 5, i = 0, *p1 = NULL;
  mas = (int *)calloc(n, sizeof(int));
  if (mas == NULL) {
    printf("Not enough memory!");
    exit(1);
  }
  printf("Inputing array. Press 0 for end!\n");
  do {
    if (i < n) {
      printf("[%d]=", i);
      scanf("%d", (mas + i));
      i++;
      getchar();
    } else {
      n = n + STEP;
      p1 = (int *)realloc(mas, n * sizeof(int));
      if (p1 == NULL) {
        printf("Not enough memory!");
        exit(1);
      } else {
        mas = p1;
        p1 = NULL;
      }
      printf("[%d]=", i);
      scanf("%d", (mas + i));
      i++;
    }
  } while (*(mas + (i - 1)) != 0);
  n = i - 1;
  *br = n;
  return mas;
}

void out(int br, int *mas) {
  int i;
  for (i = 0; i < br; i++) {
    printf("[%d]=%d\n", i, *(mas + i));
  }
}

void sort(int br, int *mas) {
  int i, j;
  float x;
  for (i = 1; i < br; i++) {
    x = *(mas + i);
    for (j = i - 1; j >= 0; j--) {
      if (x < *(mas + j))
        *(mas + j + 1) = *(mas + j);
      else
        break;
    }
    *(mas + j + 1) = x;
  }
  printf("Sorted array:\n");
  out(br, mas);
}

void sum_in_inerval(int br, int *mas) {
  int min, max, sum = 0;
  printf("Input min value for interval sum:");
  scanf("%d", &min);
  printf("Input max value for interval sum:");
  scanf("%d", &max);
  for (int i = 0; i < br; i++) {
    if (*(mas + i) >= min && *(mas + i) <= max) {
      sum += *(mas + i);
    }
  }
  printf("Sum of elements in interval [%d, %d] is %d\n", min, max, sum);
}
