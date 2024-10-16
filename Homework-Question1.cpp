// STT: 8
// Full Name: Tran Duy Hai Dang
// Homework - Exercise 01
// Notes: Implementation of Tower of Hanoi using Stack

#include <iostream>

using namespace std;

#define MAX_SIZE 100

// Stack implementation
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Push an element to stack
void push(struct Stack* s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

// Pop an element from stack
int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; // Error value
}

// Function to move a disk from one tower to another
void moveDisk(struct Stack* source, struct Stack* destination, char s, char d) {
    int disk = pop(source);
    push(destination, disk);
    printf("%c -> %c\n", s, d);
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, struct Stack* source, struct Stack* auxiliary, struct Stack* destination,
                  char s, char a, char d) {
    if (n == 1) {
        // Base case: move a single disk from source to destination
        moveDisk(source, destination, s, d);
        return;
    }

    // Move n-1 disks from source to auxiliary peg using destination as temporary
    towerOfHanoi(n - 1, source, destination, auxiliary, s, d, a);

    // Move the nth disk from source to destination
    moveDisk(source, destination, s, d);

    // Move n-1 disks from auxiliary to destination using source as temporary
    towerOfHanoi(n - 1, auxiliary, source, destination, a, s, d);
}

int main() {
    int n;
    cout << "Please type the number of disks: ";
    cin >> n;

    // Initialize three stacks to represent the towers
    struct Stack source, auxiliary, destination;
    initStack(&source);
    initStack(&auxiliary);
    initStack(&destination);

    // Push disks onto the source tower
    for (int i = n; i > 0; --i) {
        push(&source, i);
    }

    cout << "The answer:" << endl;

    // Solve Tower of Hanoi
    towerOfHanoi(n, &source, &auxiliary, &destination, 'A', 'B', 'C');

    return 0;
}
