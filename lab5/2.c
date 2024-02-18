#include "stdio.h"
#include <string.h>

#define EXIT_SUCCESS 1

int main() {
  char str[5][50], temp[50];
  printf("Vavedete 5 dumi: ");
  // Въвеждане на думи
  for (int i = 0; i < 5; ++i) {
    fgets(str[i], sizeof(str[i]), stdin);
  }
  // Сортиране на думи по метода на мехурчето
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      if (strcmp(str[i], str[j]) > 0) {
        strcpy(temp, str[i]);
        strcpy(str[i], str[j]);
        strcpy(str[j], temp);
      }
    }
  }
  printf("\nPodredeni dumi: \n");
  for (int i = 0; i < 5; ++i) {
    fputs(str[i], stdout);
    printf(" - Has length of %zu\n", strlen(str[i]) - 1);
  }
}
