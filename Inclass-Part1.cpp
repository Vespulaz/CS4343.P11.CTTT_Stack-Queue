//STT: 8
//Full Name: Tran Duy Hai Dang
//In-Class Exercise - Part 1
//Notes or Remarks: ......

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void initialize() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }


    bool isFull() {
        return false;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Stack is empty!" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cerr << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    stack.initialize();
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Check if stack is empty\n";
        cout << "2. Check if stack is full\n";
        cout << "3. Push an element onto the stack\n";
        cout << "4. Pop an element from the stack\n";
        cout << "5. Print the top element of the stack\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 2:
                cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;
                break;
            case 3:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 4:
                cout << "Popped element: " << stack.pop() << endl;
                break;
            case 5:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}