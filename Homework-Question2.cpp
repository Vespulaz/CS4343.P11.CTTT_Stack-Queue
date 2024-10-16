// STT: 8
// Full Name: Tran Duy Hai Dang
// Homework - Exercise 02
// Notes: Implementation of browser history management using Stack

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// Stack implementation
class Stack {
private:
    string data[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(string value) {
        if (!isFull()) {
            data[++top] = value;
        }
    }

    string pop() {
        if (!isEmpty()) {
            return data[top--];
        }
        return ""; // Empty string for error
    }

    string peek() {
        if (!isEmpty()) {
            return data[top];
        }
        return ""; // Empty string for error
    }
};

class BrowserHistory {
private:
    Stack backStack;
    Stack forwardStack;
    string currentPage;

public:
    void visit(string url) {
        if (!currentPage.empty()) {
            backStack.push(currentPage);
        }
        currentPage = url;
        // Clear forward history when visiting a new page
        while (!forwardStack.isEmpty()) {
            forwardStack.pop();
        }
        cout << currentPage << endl;
    }

    void back() {
        if (!backStack.isEmpty()) {
            forwardStack.push(currentPage);
            currentPage = backStack.pop();
            cout << currentPage << endl;
        } else {
            cout << "Ignored" << endl;
        }
    }

    void forward() {
        if (!forwardStack.isEmpty()) {
            backStack.push(currentPage);
            currentPage = forwardStack.pop();
            cout << currentPage << endl;
        } else {
            cout << "Ignored" << endl;
        }
    }
};

int main() {
    BrowserHistory browser;
    int n;
    cout << "Please enter the number of commands:";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        cout << "Please enter command (visit, back, forward):";
        cin >> command;

        if (command == "visit") {
            string url;
            cout << "Please enter the URL:";
            cin >> url;
            browser.visit(url);
        } else if (command == "back") {
            browser.back();
        } else if (command == "forward") {
            browser.forward();
        }
    }

    return 0;
}
