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


int GetMiddleElementOfStack(stack<int> &st, int position) {
    if (position == 1) {
        return st.top();
    }

    int temp = st.top();
    st.pop();
    return GetMiddleElementOfStack(st, --position);
    // Backtrack to restack the popped elements.

    st.push(temp);

}

int getMiddleElPos(stack<int> &st) {

    // if the stack has odd numbers of element then middle element position will be (size/2) + 1.
    if (st.size() & 1) {
        return  (st.size()/2) + 1;
    }
    // else mid pos will be size/2
    return st.size()/2;
}

int main() {
    stack<int> st1;
    stack<int> st2;

    // push even number of elements in the stack;

    int count = 7;
    while(count--) {
        if (count <= 5 ) {
            // push even no. of elements in this stack. st1
            st1.push(count*10);
        }
        // Push odd no. of elements in this stack. st2
        st2.push(count*10);
    }

    cout << "Stack 1: ";
    PrintStackWithoutModifying(st1);
    cout << endl;
    cout << "Stack 2: ";
    PrintStackWithoutModifying(st2);
    cout << endl;
    int middleSt1 = getMiddleElPos(st1);
    int middleSt2 = getMiddleElPos(st2);

    cout << "Middle pos of st1 : " << middleSt1 << endl;
    cout << "Middle pos of st2 : " << middleSt2 << endl;

    cout << "Middle Element of st1 = " << GetMiddleElementOfStack(st1, middleSt1) << endl;
    cout << "Middle Element of st2 = " << GetMiddleElementOfStack(st2, middleSt2);


}