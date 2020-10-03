
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67
#include <stdio.h>
#include <stdlib.h>

    int mutex = 1,
        full = 0, empty = 3, x = 0;

int main() {
  int n;
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  printf("\n1.Producer\n2.Consumer\n3.Exit");
  while (1) {
    printf("\nEnter your choice:");
    scanf("%d", &n);
    switch (n) {
    case 1:
      if ((mutex == 1) && (empty != 0))
        producer();
      else
        printf("Buffer is full!!");
      break;
    case 2:
      if ((mutex == 1) && (full != 0))
        consumer();
      else
        printf("Buffer is empty!!");
      break;
    case 3:
      exit(0);
      break;
    }
  }

  return 0;
}

int wait(int s) { return (--s); }

int signal(int s) { return (++s); }

void producer() {
  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  x++;
  printf("\nProducer produces the item %d", x);
  mutex = signal(mutex);
}

void consumer() {
  mutex = wait(mutex);
  full = wait(full);
  empty = signal(empty);
  printf("\nConsumer consumes item %d", x);
  x--;
  mutex = signal(mutex);
}
