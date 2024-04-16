
#include <stdio.h>

struct Books {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};

void printBooks(struct Books books[], int size);
void inputBooks(struct Books books[], int size);

int main() {
  struct Books library[5]; // декларация на масив от 5 структури Books

  /* въвеждане на данните за книгите */
  inputBooks(library, 5);

  /* извеждане на данните за книгите */
  printf("Books in the library:\n");
  printBooks(library, 5);

  return 0;
}

void printBooks(struct Books books[], int size) {
  for (int i = 0; i < size; i++) {
    printf("Book %d:\n", i + 1);
    printf("Title: %s\n", books[i].title);
    printf("Author: %s\n", books[i].author);
    printf("Subject: %s\n", books[i].subject);
    printf("Book ID: %d\n", books[i].book_id);
    printf("\n");
  }
}

void inputBooks(struct Books books[], int size) {
  for (int i = 0; i < size; i++) {
    printf("Enter details for Book %d:\n", i + 1);
    printf("Title: ");
    scanf("%s", books[i].title);
    printf("Author: ");
    scanf("%s", books[i].author);
    printf("Subject: ");
    scanf("%s", books[i].subject);
    printf("Book ID: ");
    scanf("%d", &books[i].book_id);
  }
}
