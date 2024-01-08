#include<stack>
#include<iostream>

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
    if (st.empty() || element > st.top() ) {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(temp);
}


int main() {
    stack<int> st;
    // Print this stack without modifying it.

    for(int i = 1; i <= 10; i+=2) {
        st.push(i*10);
    }
    cout  << "Before inserting element: ";
    PrintStackWithoutModifying(st);
    cout << endl;
    
    cout << "Top: " << st.top() << endl;
    // Insert sorted
    insertSorted(st, 5); 
    cout << "After Inserting element: ";
    PrintStackWithoutModifying(st);
    cout << endl;
}