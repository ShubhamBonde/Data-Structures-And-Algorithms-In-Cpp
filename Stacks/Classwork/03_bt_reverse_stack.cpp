#include<iostream>
#include<stack>

using namespace std;

// Purpose - To insert an element at the bottom of the stack using backtracking.
void insertAtBottom(stack<int> &st, int value) {
    if (st.empty()) {
        st.push(value);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, value);

    // Backtrack
    st.push(temp);
}

void PrintStackWithoutModifying(stack<int> &st) {
    // We'll be using backtracking here.
    if (st.empty()) return;

    // Get top element
    int topEl = st.top();
    // Print it.
    cout << topEl << " ";

    st.pop();
    // Recurse
    PrintStackWithoutModifying(st);
    // Backtrack to push back the popped element in this call.
    st.push(topEl);
}


void ReverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }

    int temp = st.top();
    st.pop();
    ReverseStack(st);
    // Backtrack to insert an element at the bottom of the stack.
    insertAtBottom(st, temp);
}


int main() {
    stack<int> st;

    // Push some elements over the stack.
    for(int i = 10; i >= 1; --i) {
        st.push(i);
    }


    cout << "Bfefore reversing: "; 
    PrintStackWithoutModifying(st);
    cout << endl;
    // Reverse the stack

    ReverseStack(st);
    cout << "After reversing: ";
    PrintStackWithoutModifying(st);
}
