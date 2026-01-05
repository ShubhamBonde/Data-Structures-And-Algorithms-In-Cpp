#include<iostream>
#include<stack>

using namespace std;

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

void insertSorted(stack<int> &st, int element) {
    if (st.empty() || element < st.top() ) {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(temp);
}


void SortStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }

    int temp = st.top();
    st.pop();
    SortStack(st);
    insertSorted(st, temp);
}

int main() {
    
    stack<int> st;
    // Insert elements in random order
    st.push(5);
    st.push(9);
    st.push(3);
    st.push(6);
    cout << "Before sort: ";
    PrintStackWithoutModifying(st);
    cout << endl;

    cout << "After sort: ";
    SortStack(st);
    PrintStackWithoutModifying(st);
    cout << endl;
}

