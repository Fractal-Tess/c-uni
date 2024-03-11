#include <stdio.h>

void input(float a[100], int n);
void output(float a[100], int n);
void sort(float a[100], int n);
void bublesort(float a[100], int size);

int main() {
  int n;
  float a[100];

  printf("n=");
  scanf("%d", &n);
  input(a, n);

  // sort(a, n);
  bublesort(a, n);

  output(a, n);
  return 0;
}

void input(float a[100], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("a[%d]=", i);
    scanf("%f", &a[i]);
  }
}

void output(float a[100], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("a[%d]=%.2f\t", i, a[i]);
  }
}

// Original
void sort(float a[100], int n) {
  int i, j;
  float x;
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        x = a[j];
        a[j] = a[j - 1];
        a[j - 1] = x;
      }
    }
  }
}

void bublesort(float arr[], int size) {
  int i, j;
  float temp;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
