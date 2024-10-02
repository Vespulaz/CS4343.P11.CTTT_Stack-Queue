//STT: 8
//Full Name: Tran Duy Hai Dang
//In-Class Exercise - Part 2
//Notes or Remarks: ......

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void initialize() {
        front = nullptr;
        rear = nullptr;
    }


    bool isEmpty() {
        return front == nullptr;
    }

    bool isFull() {
        return false;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear != nullptr) {
            rear->next = newNode;
        }
        rear = newNode;

        if (front == nullptr) {
            front = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return -1;
        }
        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    int getFront() {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue queue;
    queue.initialize();
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Check if queue is empty\n";
        cout << "2. Check if queue is full\n";
        cout << "3. Enqueue an element into the queue\n";
        cout << "4. Dequeue an element from the queue\n";
        cout << "5. Print the front element of the queue\n";
        cout << "6. Print the rear element of the queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 2:
                cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;
                break;
            case 3:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 4:
                cout << "Dequeued element: " << queue.dequeue() << endl;
                break;
            case 5:
                cout << "Front element: " << queue.getFront() << endl;
                break;
            case 6:
                cout << "Rear element: " << queue.getRear() << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}