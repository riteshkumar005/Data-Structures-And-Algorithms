#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
    
}
void insertAtPosition(Node* &tail, Node* &head, int position ,int d){

    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    
    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    //new node create
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;

}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtPosition(tail,head,2,20);
    insertAtPosition(tail,head,2,5);
    insertAtPosition(tail,head,2,15);
   
    print(head);

    return 0;
}


