// Initialize a stack instance
// PARAM: stack * s - the stack to initialize
void initialize(stack * s) {
  stack->topIndex = -1;
  stack->list = (float *)malloc(sizeof(float) * MAX_HOLD);
}

// Checks if a stack is empty
// PARAM: stack * s - the stack to check
// RETURN: 1 - empty, 0 - not empty
int isStackEmpty(stack * s) {
  return (stack->topIndex == -1);
}

// Checks if a stack is full
// PARAM: stack * s - the stack to check
// RETURN: 1 - full, 0 - not full
int isStackFull(stack * s) {
  return (stack->topIndex == MAX_HOLD-1);
}

// push / insert an item into the stack, LIFO
// PARAM: stack * s - the stack to add to
// PARAM: float value - the value to add
// RETURN: 1 for success, 0 for exception
int push(stack * s, float value) {
  // check if the stack is full
  if (!isStackFull(s)) {
    stack->topIndex++;
    stack->list[stack->topIndex] = value;
    return TRUE;
  } else return FALSE;
}

// get the last value from stack
// PARAM: stack * s - the stack to check
// RETURN: the value of the last item from stack
//         return NULL if stack is empty
int peek(stack * s) {
  // checking if the stack is empty first
  if (!isStackEmpty(s)) return stack->list[stack->topIndex];
  else return NULL;
}

// get the last value from stack AND delete it
// PARAM: stack * s - the stack to check
// RETURN: the value of the last item from stack
//         return NULL if stack is empty
int pop(stack * s) {
  int value = peek(s);

  // if the stack is empty
  if (value == NULL) {

    // increment down topIndex
    s->topIndex--;

    return value;
  } else {
    return NULL;
  }
}
