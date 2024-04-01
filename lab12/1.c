
#include <stdio.h>

#define N 20 // максимален брой студенти
typedef struct {
  char ime[30];
  long fnum;
  int grup;
  float ocenka;
} STD; // потребителски тип структура студент

void my_line_flush(); // функция за изчистване на входния поток
STD inputStd(void);  // функция за въвеждане
void outputStd(STD); // функция за извеждане
void uspeh(STD s[N], int br); // функция за търсене на средна оценка
void excellentStudents(
    STD s[N],
    int br); // функция за изготвяне на списък на студентите с отличен успех
void menu(); // функция за извеждане на менюто

int main() {
  int i, num = 0, sum = 0;
  STD s[N]; // масив от структури
  int choice;

  do {
    menu();
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      do {
        printf("Vedete broi studenti (maksimum do %d):", N);
        scanf("%d", &num); // въвеждане на броя на студентите в групата
      } while ((num > N) || (num <= 0));
      for (i = 0; i < num; i++)
        s[i] = inputStd();
      break;
    case 2:
      printf("\nSpisak na studenti:\n");
      for (i = 0; i < num; i++)
        outputStd(s[i]);
      break;
    case 3:
      uspeh(s, num);
      break;
    case 4:
      excellentStudents(s, num);
      break;
    case 0:
      printf("Izhod ot programa.\n");
      break;
    default:
      printf("Nevaliden izbor. Molq, opitajte otnovo.\n");
    }
  } while (choice != 0);

  return 0;
}

void menu() {
  printf("\n----- MENIU -----\n");
  printf("1. Vavedete studenti\n");
  printf("2. Izvezhdane na spisak na studentite\n");
  printf("3. Tursene na sreden uspeh po grupa\n");
  printf("4. Spisak na studentite s otlichen uspeh\n");
  printf("0. Izhod\n");
  printf("Izberete opcija: ");
}

void my_line_flush() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

STD inputStd(void) {
  STD a;
  printf("Ime: ");
  my_line_flush();
  fgets(a.ime, 30, stdin);
  printf("Nomer: ");
  scanf("%ld", &a.fnum);
  printf("Grupa: ");
  scanf("%d", &a.grup);
  printf("Ocenka: ");
  scanf("%f", &a.ocenka);
  return (a);
}

void outputStd(STD a) {
  printf("Ime:%s", a.ime);
  printf("\nNomer:%ld\n", a.fnum);
  printf("Grupa:%d\n", a.grup);
  printf("Ocenka:%.2f\n", a.ocenka);
}

void uspeh(STD s[N], int br) {
  float sum = 0.0;
  int gr = 0, key;
  printf("Vavedete nomer na grupa: ");
  scanf("%d", &key);
  for (int i = 0; i < br; i++)
    if (s[i].grup == key) {
      sum += s[i].ocenka;
      gr++;
    }
  if (gr > 0) // проверка за деление на 0
    printf("Sreden uspeh na studenti ot %d grupa: %.2f\n", key, sum / gr);
  else
    printf("Niama studenti ot grupa %d!\n", key);
}

void excellentStudents(STD s[N], int br) {
  printf("\nSpisak na studentite s otlichen uspeh:\n");
  for (int i = 0; i < br; i++) {
    if (s[i].ocenka >= 5.50) {
      outputStd(s[i]);
    }
  }
}
