// global constants
const int MAX_HOLD = 10;

// stack type
struct stack {
  int topIndex;
  float * list;
}

// function prototypes
void initialize(stack * s);
int isStackEmpty(stack * s);
int isStackFull(stack * s);
int push(stack * s, float value);
int peek(stack * s);
int pop(stack * s);
