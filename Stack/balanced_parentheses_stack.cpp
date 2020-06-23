#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

template <class T> class Stack {
    int top;
    int size;
    T *stack;

public:
    Stack(int max);
    Stack();
    ~Stack(){ delete [] stack; }
    void createStack();
    bool isEmpty();
    bool isFull();
    void push(T x);
    T peek();
    T pop();
    void displayStack();
    void checkParentheses(Stack<T> *s2, char arr [], int len);
};

template <class T> Stack<T>::Stack(int max): size(max) , top(-1){}

template <class T> Stack<T>::Stack(){
    size =  10;
    top = -1;
}

template <class T> void Stack<T>::createStack(){
    stack = new T [size];
}

template <class T> bool Stack<T>::isEmpty(){
    return (top == -1);
}

template <class T> bool Stack<T>::isFull() {
    return (top == size - 1);
}

template <class T> void Stack<T>::push(T x){
    if(isFull()){
        cout<<"Stack overflow"<<endl;
    }
    else{
        stack[++top] = x;
    }
}

template <class T> T Stack<T>::peek(){
    if(isEmpty()){
        cout<<"Stack is emtpty"<<endl;
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
        return 0;    
    }
    else{
        cout<<"Element popped : "<<stack[top]<<endl;
        return stack[top--];
    }
}

template <class T> void Stack<T>::displayStack(){
    if(isEmpty()){
        cout<<"Stack is empty nothing to display! "<<endl;
    }
    else{
        int i;
        for( i = top;  i >= 0 ; i--)
            cout<<stack[i]<<endl;
    }
}

template <class T> void Stack<T>::checkParentheses(Stack<T> *s2 ,char arr [], int len){
    int i ;
    s2->createStack();
    char expr , temp;
    bool isBalanced = false;
    for( i = 0 ; i < len ; i++ ){
        expr = arr[i];
        switch(expr){
            case '{':
                s2->push(expr);
                break;
            case '(':
                s2->push(expr);
                break;
            case '[':
                s2->push(expr);
                break;
            case '}':
                if(s2->isEmpty()){
                    cout<<"Stack is empty : and parentheses are unbalanced "<<endl;
                    isBalanced == false;
                    break;
                }
                else{
                temp = s2->pop();
                if(temp == '{')
                    isBalanced = true;
                break;
                }
            case ')':
                if(s2->isEmpty()){
                    cout<<"Stack is empty : and parentheses are unbalanced "<<endl;
                    isBalanced == false;
                    break;
                }
                else{
                    temp = s2->pop();
                    if(temp == '(')
                        isBalanced = true;
                    break;
                }
            case ']':
                if(s2->isEmpty()){
                    cout<<"Stack is empty : and parentheses are unbalanced "<<endl;
                    isBalanced == false;
                    break;
                }
                else{                
                    temp = s2->pop();
                    if(temp == '[')
                        isBalanced = true;
                    break;
                }
        }
    }
    if(!isEmpty()){
        isBalanced = false ;
    }
    if(isBalanced){
        cout<<"expression is balanced"<<endl;
    }
    else {
        cout<<"expression is not balanced"<<endl;
    }
}

//Driver program 
int main (){
    int len = 0;
    char buffer [50]; // for storing expression
    cout<<"Enter the expression for checking balanced parentheses : "<<endl;
    /* Other approaches can be used for reading data from stdin
       As I am refreshing data structures focus on C++ language
       comes later, definitely one could use more optimized approach 
       other than fgets ,fgets was used C language */
    fgets(buffer,40, stdin);
    while(buffer[len] != '\n'){
        len++;
    }
    Stack<char> s2(len);
    Stack<char> *stackPtr=&s2;
    s2.checkParentheses(stackPtr,buffer, len);
    return 0;
}