#include <stdio.h>
#include <stdlib.h>

#define STACK 0
#define QUEUE 1

// the current mode of the program (default is stack mode)
int mode = STACK;

// the stack and queue data structures
int stack[100], queue[100];

// the top of the stack and front/back of the queue
int stack_top = -1, queue_front = -1, queue_back = -1;

// push a value onto the stack
void stack_push(int value) {
    // increment the top of the stack and set the value
    stack_top++;
    stack[stack_top] = value;
}

// pop a value from the stack
int stack_pop() {
    // get the value at the top of the stack
    int value = stack[stack_top];

    // decrement the top of the stack
    stack_top--;

    // return the value
    return value;
}

// enqueue a value in the queue
void queue_enqueue(int value) {
    // if the queue is empty, set the front and back to 0
    if (queue_front == -1) {
        queue_front = 0;
        queue_back = 0;
    }

    // otherwise, increment the back of the queue
    else {
        queue_back++;
    }

    // set the value at the back of the queue
    queue[queue_back] = value;
}

// dequeue a value from the queue
int queue_dequeue() {
    // get the value at the front of the queue
    int value = queue[queue_front];

    // if the front and back are at the same position,
    // this indicates that the queue is empty, so reset
    // the front and back to -1
    if (queue_front == queue_back) {
        queue_front = -1;
        queue_back = -1;
    }

    // otherwise, increment the front of the queue
    else {
        queue_front++;
    }

    // return the value
    return value;
}

// switch the mode of the program
void switch_mode() {
    // if the current mode is stack mode, switch to queue mode
    if (mode == STACK) {
        mode = QUEUE;

        // move the values from the stack to the queue
        while (stack_top >= 0) {
            queue_enqueue(stack_pop());
        }
    }

    // otherwise, the current mode is queue mode, so switch to stack mode
    else {
        mode = STACK;

        // move the values from the queue to the stack
        while (queue_front != -1) {
            stack_push(queue_dequeue());
        }
    }
}

// main function
int main() {
    // push some values onto the stack
    stack_push(1);
    stack_push(2);
    stack_push(3);
    stack_push(4);

    // switch to queue mode
    switch_mode();

    // enqueue some values in the queue
    queue_enqueue(5);
    queue_enqueue(6);
    queue_enqueue(7);
    queue_enqueue(8);

    // switch back to stack mode
    switch_mode();

    // pop and print the values from the stack
    printf("%d\n", stack_pop());
    printf("%d\n", stack_pop());
    printf("%d\n", stack_pop());
    printf("%d\n", stack_pop());

    // switch back to queue mode
    switch_mode();

    // dequeue and print the values from the queue
    printf("%d\n", queue_dequeue());
    printf("%d\n", queue_dequeue());
    printf("%d\n", queue_dequeue());
    printf("%d\n", queue_dequeue());

    return 0;
}
