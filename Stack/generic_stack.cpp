#include <iostream>
using namespace std;

template <class T> class Stack {
    int top;
    int size;
    T * stack;

public:
    Stack(int max);
    Stack();
    ~Stack() { delete [] stack ; }
    void createStack();
    bool isEmpty();
    bool isFull();
    void push(T x);
    T peek();
    T pop();
    void displayStack();
};

template <class T> Stack<T>::Stack(int max):size(max),top(-1){}

template <class T> Stack<T>::Stack(){
    size = 10;
    top = -1;
}

template <class T> void Stack<T>::createStack(){
    stack = new T[size];
}

template <class T> bool Stack<T>::isEmpty(){
    return (top == -1);
}

template <class T> bool Stack<T>::isFull(){
    return (top == size-1);
}

template <class T> void Stack<T>::push(T x){
    if(isFull()){
        cout<<"Stack overflow "<<endl;
    }
    else{
        stack[++top] = x;
    }
}

template <class T> T Stack<T>::peek(){
    if(isEmpty()){
       cout<<"Stack is empty"<<endl;
       return 0; 
    }
    else{
        cout<<"Element at top : "<<stack[top]<<endl;
        return stack[top];
    }
}

template <class T> T Stack<T>::pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Element popped : "<<stack[top]<<endl;
        return stack[top--]; 
    }
}

template <class T > void Stack<T>::displayStack(){
    if(isEmpty()){
        cout<<"Stack is empty, nothing to display!"<<endl;
    }
    else{
        for(int i = top; i >= 0; i--)
            cout<<stack[i]<<endl;
    }    
}

//Driver program 
int main (){

    //Stack <char> s0;
    Stack<char> s1(5);
    s1.createStack();
    s1.push('s');
    s1.push('a');
    s1.push('a');
    s1.push('d');
    s1.push('h');
    s1.displayStack();
    s1.peek();
    s1.push('u');
    s1.pop();
    s1.push('q');
    s1.displayStack();
}