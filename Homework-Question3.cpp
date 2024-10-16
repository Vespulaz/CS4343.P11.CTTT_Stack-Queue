// STT: 8
// Full Name: Tran Duy Hai Dang
// Homework - Exercise 03
// Notes: Implementation of determine how many people each person can see to their right using Stack.

#include <iostream>
using namespace std;

// Stack implementation
class Stack {
private:
    int* data;
    int top;
    int capacity;

public:
    Stack(int size) {
        data = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int x) {
        if (top < capacity - 1) {
            data[++top] = x;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
    }

    int peek() {
        if (top >= 0) {
            return data[top];
        }
        return -1; // Error value
    }

    bool isEmpty() {
        return top == -1;
    }
};

class Solution {
public:
    int* canSeePersonsCount(int* heights, int n) {
        int* answer = new int[n]();  // Initialize with zeros
        Stack st(n);

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;

            // Remove people shorter than the current person
            while (!st.isEmpty() && heights[i] > heights[st.peek()]) {
                st.pop();
                count++;
            }

            // If stack is not empty, current person can see the tallest remaining person
            if (!st.isEmpty()) {
                count++;
            }

            // Save the result and push current index to stack
            answer[i] = count;
            st.push(i);
        }

        return answer;
    }
};

int main() {
    Solution sol;
    int n;

    // Get the number of people
    cout << "Enter the number of people: ";
    cin >> n;

    // Input validation
    if (n <= 0 || n > 100000) {
        cout << "Invalid number of people. Please enter a number between 1 and 100000." << endl;
        return 1;
    }

    int* heights = new int[n];

    // Get the heights of people
    cout << "Enter the heights of " << n << " people (separated by spaces): ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        // Input validation
        if (heights[i] <= 0 || heights[i] > 100000) {
            cout << "Invalid height. Please enter heights between 1 and 100000." << endl;
            delete[] heights;
            return 1;
        }
    }

    // Calculate the result
    int* result = sol.canSeePersonsCount(heights, n);

    // Print the result
    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Free memory
    delete[] heights;
    delete[] result;

    return 0;
}
