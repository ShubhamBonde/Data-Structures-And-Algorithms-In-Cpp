#include<iostream>
#include<climits>
using namespace std;



class Stack {
    int LIMIT = 10;
    int stack[10];
    int topPtr = -1;

    public:
    // Insertion
        void push(int _val);
    // Deletion g
        void pop();
    // Empty Check
        bool isEmpty();
    // Retrieval of top element
        int top();
    // get the size of stack
        int size();
};

int Stack::size() {
    // if stack is undeflowing that means stack size = 0
    return (isEmpty() ? 0 : topPtr+1);
}

void Stack::push(int _value) {
    // Case where stack doens't have enough space to push elements.
    if (topPtr >= LIMIT-1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    // In all other cases we can safely push onto the stack.
    stack[++topPtr] = _value;
}

void Stack::pop() {
    // if the stack is empty then no deletion is possible.
    if (isEmpty()) {
        cout << "Stack Underflow cannot pop!" << endl; 
        return; 
    }

    --topPtr;
}

bool Stack::isEmpty() {
    // If top is -1 then stack is empty;
    return topPtr == -1;
}

int Stack::top() {
    // Stack could be underflowing
    if (isEmpty()) {
        cout << "Stack underflow cannot retrieve top element" << endl;
        return INT_MIN;
    }
    // In other cases we can return top element.
    return stack[topPtr];
}


int getMiddleElementOfStack(Stack &st) {
    int MidIdx = st.size()&1 ;
}

int main() {
    Stack st;
    
    // Kya stack empty hai?
    cout << "Stack size = " << st.size() << endl;
    st.push(1);
    // make the stack full 
    for (int i = 1; i<=10; i++) {
        st.push(i);
    }

    st.push(-10);
 
    cout << "Stack size = " << st.size() << endl;
    cout << "Stack top element: "<< st.top() << endl;
}