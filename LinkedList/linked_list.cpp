#include <iostream>
using namespace std;


class Node {

public:
    Node *next;
    int data;
    Node(int _data): data(_data), next(NULL){}
};

class Linkedlist {
    Node *head;
    int size;

public:
    Linkedlist(int _size);
    bool isEmpty();
    void addFirst(int x);
    void addLast (int x);
    void displayList();
    void removeFirst();  
    void insertAfter(int key, int val);
    void insertBefore(int key, int val);
    void delNode(int key);
    int getFirst();
    int getLast();
    bool contains(int x);
    int get(int pos);
    void reverse();
    Linkedlist copyList();
/*  void clear(){
 *       head = NULL;
 *  }
 *   bool hasNext(Node *node){
 *      return (node->next != NULL);
 *   }
 */
};


Linkedlist::Linkedlist(int _size): head(NULL) , size(_size){}

bool Linkedlist::isEmpty(){
    return (head == NULL);
}

void Linkedlist::addFirst(int x){
    if(isEmpty()){
        Node *node = new Node(x);
        head = node;
    }
    else{
        Node *node = new Node(x);
        node->next = head;
        head = node;
    }
}

void Linkedlist::addLast(int x){
    if(isEmpty()){
        //List is empty: this data node will become head of the list.
        addFirst(x);
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node *node = new Node(x);
        temp->next = node;
    }
}

void Linkedlist::displayList () {
	cout<<"Displaying list :"<<endl;
    if(isEmpty()){
        cout<<"List is empty nothing to display !"<<endl;
    }
    else{
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

void Linkedlist::removeFirst(){
    if(isEmpty()){
        cerr<<"List is empty, nothing to be deleted!"<<endl;
    }
    else{
        head = head->next;
    }
}

//Fina a node containing "key" and insert new node after it
void Linkedlist::insertAfter(int key , int val){
     cout<<"Inserting "<<val<<" after key = "<<key<<endl;
    bool containsKey = false;
    if(isEmpty()){
        cerr<<"List is empty , can't insert after any node !"<<endl;
        return ;
    }
    else{
        Node *temp = head; 
        while(temp != NULL && !(temp->data == key)){
            temp = temp->next;
        }
        if(temp != NULL){
            containsKey = true;
            Node *node = new Node(val);
            node->next = temp->next;
            temp->next = node;
        }
    }
    if(!containsKey){
        cout<<"Key not found in list"<<endl;
    }
}

void Linkedlist::insertBefore(int key, int val){
    cout<<"Inserting "<<val<<" before key = "<<key<<endl;
    bool containsKey = false; 
    if(isEmpty()){
        cerr<<"List is empty , can't insert before any node"<<endl;
        return;
    }
    if(head->data == key){
        containsKey = true;
        addFirst(val);
    }
    else{
        Node *prev = head;
        Node *cur = head->next;
        while(cur != NULL && !(cur->data == key)){
            prev = cur;
            cur = cur->next;
        }

        if(cur != NULL){
            containsKey = true;
            Node *node = new Node(val);
            prev->next = node;
            node->next = cur;
        }
    }
    if(!containsKey){
        cerr<<"Key not found"<<endl;
    }
}

/**
  * Removes the first occurence of the specified element in the list
  *
  */
void Linkedlist::delNode(int key){
    cout<<"Deleting node with value : "<<key<<endl;
    bool containsKey = false;
    if(isEmpty()){
        cerr<<"List is empty , nothing to delete"<<endl;
        return;
    }
    if (head->data == key){
        containsKey = true;
        removeFirst();
    }   
    else{
        Node *prev = head;
        Node *cur = head->next;
        while(cur != NULL && !(cur->data == key)){
            prev = cur;
            cur = cur->next;
        }
        if(cur != NULL){
            containsKey = true;
            prev->next = cur->next;
        }
    }
    if(!containsKey){
        cerr<<"The key to be deleted was not found in the list !"<<endl;
    }
}

int Linkedlist::getFirst(){
    if(head == NULL){
        cerr<<"List is empty, 0 will be returned !"<<endl;
        return 0;
    }
    else {
        return head->data;
    }
}

int Linkedlist::getLast(){
    if(head == NULL){
        cerr<<"List is empty, 0 will be returned !"<<endl;
        return 0;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp->data;
    }
}

bool Linkedlist::contains(int x){
    bool containsKey = false;
    if(head == NULL){
        return containsKey;
    }
    else{
        Node *temp = head;
        while(temp != NULL && !(temp->data == x)){
            temp = temp->next;
        }
        if(temp != NULL){
            containsKey = true;	
        }
    }
    return containsKey;
}

int Linkedlist::get(int pos){
    if(head == NULL || pos < 1){
        cerr<<"List is empty, -1 will be returned"<<endl;
        return -1;
    }
    else{
        //assuming the index will start from 1 according to user
        int counter = 1;
        Node *temp = head;

/**     Another simpler approach to solve this problem
  *     for(int k = 0; k <pos ; k++){
  *         temp = temp->next;
  *      }
  *      if (temp == NULL) throw new IndexOutofBoundException
  *
  */    
        while(temp != NULL && (pos != counter)){
            temp = temp->next;
            counter++;
        }
        if(temp != NULL){
            return temp->data;
        }

        else{
            cerr<<"Index out of range -1 will be returned : "<<endl;
            return -1;
        }
    }
}

void Linkedlist::reverse(){
    if(head == NULL){
        cerr<<"List is empty nothing to reverse"<<endl;
        return;
    }
    else {
        Node *temp = head;
        Node *prev = NULL;
        Node *current = NULL;
        while (temp != NULL){
            current = temp;
            temp = temp->next;
            current->next = prev;
            prev = current;
        }
        head = current;
    }
}

Linkedlist Linkedlist::copyList(){
    if(head == NULL){
        cerr<<"List is emmpty nothing to reverse"<<endl;
    }
    else{
        Node *temp = head;
        Linkedlist tempList(0);
        while (temp != NULL){
            tempList.addLast(temp->data);
            temp = temp->next;
        }
        return tempList;
    }   
}



int main () {
    
    Linkedlist list(0);
    list.addFirst(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);
    list.displayList();
    list.insertBefore(2,11);
    list.displayList();
    list.insertAfter(4,44);
    list.displayList();
    list.delNode(11);
    list.delNode(44);
    list.displayList();
    bool containsKey = list.contains(44);
    cout<<"1 is true, 0 is false = "<<containsKey<<endl;
    cout<<"Value at index 3 = "<<list.get(3)<<endl;
    Linkedlist copiedList = list.copyList();
    cout<<"Displaying copied list : "<<endl;
    copiedList.displayList();
    cout<<"Checking out simple reverse list function ! "<<endl;
    list.reverse();
    list.displayList();
    return 0 ; 

}