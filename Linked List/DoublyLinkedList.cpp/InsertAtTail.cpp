#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    

};

void insertAtTail(Node* &head,Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;

    }

   
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl<<endl;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
   insertAtTail(head, tail, 13);
   insertAtTail(head, tail, 19);
   

    print(head);
    return 0;
}