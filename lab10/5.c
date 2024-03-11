#include <stdio.h>
#include <string.h>

int main() {
  char str[100], choice1, choice2;
  int i, ctr1 = 0, ctr2 = 0;
  printf("Input string : ");
  fgets(str, sizeof str, stdin);
  str[strlen(str) - 1] = '\0';

  printf("Search character 1:");
  scanf("%c", &choice1);
  printf("Search character 2:");
  scanf(" %c", &choice2);

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == choice1) {
      ctr1++;
    }
    if (str[i] == choice2) {
      ctr2++;
    }
  }

  printf("Character 1 %c appears %d times\n", choice1, ctr1);
  printf("Character 2 %c appears %d times\n", choice2, ctr2);
  return 0;
}
