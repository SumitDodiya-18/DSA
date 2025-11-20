#include <iostream>
using namespace std;

class AbstractStack {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual int top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual int size() = 0;
    virtual void display() = 0;  
};

class Stack : public AbstractStack {
private:
    int arr[100];     
    int topIndex;
    int capacity;

public:
   
    Stack(int cap) {
        capacity = cap;
        topIndex = -1;
    }

    void push(int value) override {
        if (isFull()) {
            cout << "Stack is FULL! Cannot push.\n";
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed to stack.\n";
    }

    void pop() override {
        if (isEmpty()) {
            cout << "Stack is EMPTY! Cannot pop.\n";
            return;
        }
        cout << arr[topIndex] << " popped from stack.\n";
        topIndex--;
    }

    int top() override {
        if (isEmpty()) {
            cout << "Stack is EMPTY!\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() override {
        return topIndex == -1;
    }

    bool isFull() override {
        return topIndex == capacity - 1;
    }

    int size() override {
        return topIndex + 1;
    }

    void display() override {
        if (isEmpty()) {
            cout << "Stack is EMPTY!\n";
            return;
        }

        cout << "\nStack (Top to Bottom):\n";
        cout << "-----------------\n";

        for (int i = topIndex; i >= 0; i--) {
            cout << "|  " << arr[i] << "  |\n";
        }

        cout << "-----------------\n";
    }
};

int main() {
    int capacity;
    cout << "Enter Stack Capacity: ";
    cin >> capacity;

    Stack st(capacity);

    int choice, value;

    while (true) {
        cout << "\n===== STACK MENU =====\n";
        cout << "Presh 1 For Push\n";
        cout << "Presh 2 For Pop\n";
        cout << "Presh 3 For Top Element\n";
        cout << "Presh 4 For Check Empty\n";
        cout << "Presh 5 For Check Full\n";
        cout << "Presh 6 For Size\n";
        cout << "Presh 7 For Display\n";
        cout << "Presh 8 For Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            st.push(value);
            break;

        case 2:
            st.pop();
            break;

        case 3:
            cout << "Top Element: " << st.top() << endl;
            break;

        case 4:
            cout << (st.isEmpty() ? "Stack is EMPTY" : "Stack is NOT empty") << endl;
            break;

        case 5:
            cout << (st.isFull() ? "Stack is FULL" : "Stack is NOT full") << endl;
            break;

        case 6:
            cout << "Stack Size: " << st.size() << endl;
            break;

        case 7:
            st.display();
            break;

        case 8:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
