#include <stdio.h>

#define MAX 100 // максимално възможен брой на елементите от масива
//
int findMaxElem(int x[MAX], int n); // функция за търсене на max
int findSum(int x[MAX], int n); // функция за търсене на сума
int main() {
  int arr1[MAX]; // едномерен целочислен масив
  int mxelem, i, n, sum = 0;
  printf(" n= "); // определяне на размера на масива
  scanf("%d", &n);
  printf(" Vavedete %d elementa v masiva :\n", n);
  for (i = 0; i < n; i++) // въвеждане на масива
  {
    printf(" element - %d : ", i);
    scanf("%d", &arr1[i]);
  }
  sum = findSum(arr1, n); // викане на функция за определяне на сума
  mxelem = findMaxElem(arr1, n); // викане на функция за определяне на max
  printf(" The sum is : %d\n", sum); // извеждане на резултат за сума
  printf(" The max is : %d\n", mxelem); // извеждане на резултат за max
  return 0;
}
int findSum(int arr1[MAX], int n) {
  int i = 0, s = 0; // Алгоритъм за сумиране
  while (i < n) {
    s = s + arr1[i];
    i++;
  }
  return s;
}
int findMaxElem(int arr1[MAX], int n) {
  int i = 1, mxelem; // Алгоритъм за последователно търсене
  mxelem = arr1[0];
  while (i < n) {
    if (mxelem < arr1[i])
      mxelem = arr1[i];
    i++;
  }
  return mxelem;
}
