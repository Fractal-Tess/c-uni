#include "head.h"
extern float data[N];

void input(int arrayCount) {
  int i;
  for (i = 0; i < arrayCount; i++) {
    printf("data[%d]=", i + 1);
    scanf("%f", &data[i]);
  }
}
void output(int arrayCount) {
  int i;
  for (i = 0; i < arrayCount; i++)
    printf("data[%d]=%.3f ", i + 1, data[i]);
}
float sum(int arrayCount) {
  int i;
  float s = 0.0;
  for (i = 0; i < arrayCount; i++)
    s = s + data[i];
  return (s);
}

int countAboveAverage(int arrayCount) {
  float sum = 0;
  int count = 0;
  for (int i = 0; i < arrayCount; i++) {
    sum += data[i];
  }
  float average = sum / arrayCount;

  for (int i = 0; i < arrayCount; i++) {
    if (data[i] > average) {
      count++;
    }
  }
  printf("\nAverage: %.2f\n", average);
  return count;
}
