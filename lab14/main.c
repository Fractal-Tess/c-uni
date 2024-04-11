#include "funcs.h"
#include "head.h"
#include "masiv.h"

int main() {
  int arrayCount = 0;
  float s;

  do {
    printf("How many numbers in the array (0-10):");
    scanf("%d", &arrayCount);
  } while ((arrayCount > 10) || (arrayCount < 0));

  input(arrayCount);
  printf("You inputed the following data: ");
  output(arrayCount);

  s = sum(arrayCount);
  printf("\nSum:%.3f\n", s);

  printf("The average value:%.3f\n", s / arrayCount);
  printf("The count of the numbers above the average value: %d\n",
         countAboveAverage(arrayCount));

  return 0;
}
