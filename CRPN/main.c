/* RPN Simulator using shell window
 * by Muchen He
 * i@mansurhe.com
 */

// header file
#include "CRPN.h"

// global variables
struct stack * mainStack;

// main function
int main(void) {
  // current character input
  char charin;
  double * trash;

  // first initialize the main stack
  mainStack = createNewStack();
  initialize(mainStack);

  // test
  push(mainStack, 123.456);
  push(mainStack, 2.56);
  push(mainStack, 3.14159);
  push(mainStack, 7.12);
  push(mainStack, 5);
  push(mainStack, 0.3300);
  printStack(mainStack);
  
  do {
    charin = getch();

    // inputs
    switch (charin) {
    case '+': asmd(mainStack, 0); break;
    case '-': asmd(mainStack, 1); break;
    case '*': asmd(mainStack, 2); break;
    case '/': asmd(mainStack, 3); break;
    case ' ': push(mainStack, 6.66); break;
    case '\b': pop(mainStack, &trash); break;
    case '\n': peek(mainStack, &trash); push(mainStack, *trash); break;
    default: break;
    }

    // display
    printStack(mainStack);
  } while (charin != 'q');

  return 0;
}

// cretes a new stack
// RETURN: pointer to the new stack
struct stack * createNewStack() {
  struct stack * newStack = (struct stack *)malloc(sizeof(struct stack));
  return newStack;
}

// prints the stack out in a formatted manner
void printStack(struct stack * s) {
  int i = 0;
  double value_i;

  system("cls");

  for (; i < MAX_HOLD; i++) {
    // get the number from the stack array first
    value_i = s->list[i - (MAX_HOLD - s->topIndex - 1)];

    printf("%d: ", MAX_HOLD - i);

    // if the value from the array is not an emty value,
    if (MAX_HOLD - i - 1 <= s->topIndex) printf("%.4f\n", value_i);
    else printf("\n");
  }
}