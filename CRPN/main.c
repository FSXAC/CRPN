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
  char * input = (char *)malloc(sizeof(char)* 80);
  int inputPos = 0;

  // temporary storage
  double trash;

  // input to stack
  double inputToStack;

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

  printf("%f\n", stringToDouble("2.22"));
  printf("%f\n", stringToDouble("100"));
  printf("%f\n", stringToDouble("999.666"));
  printf("%f\n", stringToDouble("0"));
  getch();

  do {
    charin = getch();

    // inputs
    switch (charin) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': 
    case '.':
      input[inputPos++] = charin;
      input[inputPos] = '\0';
      break;
    case '+': asmd(mainStack, 0); break;
    case '-': asmd(mainStack, 1); break;
    case '*': asmd(mainStack, 2); break;
    case '/': asmd(mainStack, 3); break;
    case ' ': push(mainStack, 6.66); break;
    case '\b': pop(mainStack, &trash); break;
    case 13:
      if (strlen(input) == 0) {
        peek(mainStack, &trash);
        push(mainStack, trash);
        break;
      } else {
        inputToStack = stringToDouble(input);
        push(mainStack, inputToStack);
        input = "";
        inputPos = 0;
      }
      break;
    case -32: asmd(mainStack, 4); break;
    default: break;
    }

    // display
    printStack(mainStack);
    printf("%s", input);
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

// converts string into double
double stringToDouble(char * string) {
  int index = 0, divideFactor = 1;;
  double value = 0;

  // get the whole numbers bit
  while (string[index] != '\0') {
    if (string[index] == '.') divideFactor = pow(10, strlen(string) - 1 - index);
    else value = value * 10 + string[index] - '0';
    index++;
  }

  return value / divideFactor;
}