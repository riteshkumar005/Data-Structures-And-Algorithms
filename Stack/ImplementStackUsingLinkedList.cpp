#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        cout << "Memory freed for node with value: " << data << endl;
    }
};

class Stack{
 
    private:
    Node* top;

   public:
    Stack(){
       top=NULL;
    }

    void push(int data){
        Node* newNode=new Node(data);
        newNode->next=top;
        top=newNode;

    }

    void pop(){
       if (top == NULL) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        else{

            Node* temp = top;
            top = top->next;
            cout << "Popped: " << temp->data << endl;
            delete temp;
        }
       
       
    }

    int peek(){

        if(top==NULL){
            return -1;
        }

        return top->data;

    }

    bool isEmpty(){
       return top==NULL;

    }
};


int main(){

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Top element is: " << s.peek() << endl;
    s.pop();
    cout << "Top element is: " << s.peek() << endl;
    s.pop();
    cout << "Top element is: " << s.peek() << endl;
    

    return 0;
}