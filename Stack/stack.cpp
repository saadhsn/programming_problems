#include <iostream>
using namespace std;

class Stack {
    int top;
    int * stack;
    int size;
    
public:
    Stack(int max);
    void createStack();
    void push(int x);
    int peek();
    int pop();
    bool isEmpty();
    bool isFull();
    void displayStack();
};

Stack::Stack(int max):size(max),top(-1){}

void Stack::createStack(){
    stack = new int[size];
    cout<<"Stack created of size : "<<size<<endl;
}

bool Stack::isEmpty(){
    return (top == -1);
}

bool Stack::isFull(){
    return (top == size - 1);
}

void Stack::push(int x){
    if(isFull()){
        cout<<"Stack overflow"<<endl;
    }
    else {
        stack[++top] = x;
    }
}

int Stack::peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else {
        cout<<"Element at top : "<<stack[top]<<endl;
        return stack[top];
    }
}
int Stack::pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else {
        cout<<"Element popped : "<<stack[top]<<endl;
        return stack[top--];
    }
}

void Stack::displayStack(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        for(int i = top; i >= 0; i--) {
            cout<<stack[i]<<endl;
        }
    }
}

//Driver program
int main () {

    int x ,i;
    cout<<"Enter the size of stack : "<<endl;
    cin>>x;
    Stack s(x);
    s.createStack();
    for (i = 0; i < x; i++){
        s.push(i+1);
    }
    s.peek();
    s.pop();
    s.peek();
    s.displayStack();

    return 0;

}