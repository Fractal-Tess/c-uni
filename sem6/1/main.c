#include <stdio.h>
#include <string.h>

struct Books {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};

void printBook(struct Books book);
void inputBook(struct Books *book);

int main() {
  struct Books Book1; /* деклариране на структура Book1 */
  struct Books Book2; /* деклариране на структура Book2 */

  /* въвеждане на данните за book 1 */
  printf("Enter data for Book1:\n");
  inputBook(&Book1);

  /* въвеждане на данните за book 2 */
  printf("Enter data for Book2:\n");
  inputBook(&Book2);

  printBook(Book1);
  printBook(Book2);

  return 0;
}

void printBook(struct Books book) {
  printf("Book title : %s\n", book.title);
  printf("Book author : %s\n", book.author);
  printf("Book subject : %s\n", book.subject);
  printf("Book book_id : %d\n", book.book_id);
}

void inputBook(struct Books *book) {
  printf("Enter title: ");
  scanf("%s", book->title);

  printf("Enter author: ");
  scanf("%s", book->author);

  printf("Enter subject: ");
  scanf("%s", book->subject);

  printf("Enter book_id: ");
  scanf("%d", &book->book_id);
}
