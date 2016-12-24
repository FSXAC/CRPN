#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
  char in;
  while (1) {
    in = _getch();
    printf(">>> %d\n", in);
  }
}
