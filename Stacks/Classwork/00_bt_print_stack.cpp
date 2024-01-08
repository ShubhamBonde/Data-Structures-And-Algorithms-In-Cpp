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


int main() {
    stack<int> st;
    // Print this stack without modifying it.

    for(int i = 1; i <= 5; ++i) {
        st.push(i*10);
    }

    PrintStackWithoutModifying(st);
}