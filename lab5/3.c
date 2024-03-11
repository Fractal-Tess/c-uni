#include <stdio.h>
#include <string.h>

int main() {
  char s1[100], s2[100];
  
  printf("Input s1: ");
  fgets(s1, sizeof(s1), stdin);

  printf("Before copy:\n");
  printf("s1 = %s", s1);
  printf("s2 = %s\n", s2);

  // Copy
  strcpy(s2, s1);

  printf("After copy:\n");
  printf("s1 = %s", s1);
  printf("s2 = %s\n", s2);

  return 0;
}
