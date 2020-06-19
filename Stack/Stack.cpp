#include <iostream>
using namespace std;

class Stack {
	int top;
	int * stack;
	int size;

	public:
		Stack(int max);
		void create_Stack();
		void push(int x);
		int peek();
		int pop();
		bool isEmpty();
		bool isFull();
		void displayStack();
};

Stack::Stack(int max):size(max),top(-1){}

void Stack::create_Stack(){
	stack = new int[size];
	cout<<"stack created of lentgh : "<<size<<endl;
}
//isEmpty() and isFull() can be optimized more
//see the implementation in geeks for geeks
bool Stack::isEmpty(){
	if(top == -1)
		return true;
	else 
		return false;
}
bool Stack::isFull(){
	if (top == size-1)
		return true;
	else 
		return false;
}
void Stack::push(int x){
	if(isFull()){
		cout<<"Stack overflow"<<endl;
	}
	else {
		stack[++top]=x;
	}
}

int Stack::peek(){
	if(isEmpty()){
		cout<<"Stack is empty"<<endl;
		return 0;
	}
	else {
		cout<<"element at top : "<<stack[top]<<endl;
		return stack[top];
	}
}
int Stack::pop(){
	if(isEmpty()){
		cout<<"Stack is empty"<<endl;
		return 0;
	}
	else {
		cout<<"element popped : "<<stack[top]<<endl;
		return stack[top--];
	}
}
void Stack::displayStack(){
	if(isEmpty()){
		cout<<"Stack is empty"<<endl;
	}
	else{
		for(int i=top;i>=0;i--)
			cout<<stack[i]<<endl;
	}
}
//Driver program

int main () {
	int x;
	cout<<"Enter the size of stack : "<<endl;
	cin>>x;
	Stack s(x);
	s.create_Stack();
	s.push (1);
	s.push (2);
	s.push (3);
	s.push (4);
	s.peek();
	s.pop();
	s.peek();
	s.displayStack();

}