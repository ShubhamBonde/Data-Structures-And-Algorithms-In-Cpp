#include<iostream>
using namespace std;


class Queue {
	public: 
		int arr[10];
		int front;
		int rear;
		
		// ctor
		Queue() {
			front = -1;
			rear = -1;
			// Note if both the front and rear are on the -1 then that means Queue is empty.
		};
};

int main() {
	Queue q;
	cout << "Front: " << q.front << "End:  " << q.rear << endl;
	return 0;
}	
