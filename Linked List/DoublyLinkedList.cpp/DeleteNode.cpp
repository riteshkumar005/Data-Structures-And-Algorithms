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

void insertAtHead(Node* &head,Node* &tail, int data){

    if(head == NULL){
        Node* temp = new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head=temp;

    }
}
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

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    //insert at start
    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(head, tail, data);
        return;
    }

    Node* nodeToInsert= new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL ;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        int cnt=1;

        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        if(curr = tail){
            tail = prev;
        }
        delete curr;
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
   insertAtTail(head, tail, 17);
   insertAtTail(head, tail, 20);
   print(head);
   print(tail);

   cout<<"After insert at position"<<endl;
   insertAtPosition(head, tail, 2, 11);

   print(head);
   print(tail);

   cout<<"After delete the node"<<endl;
   deleteNode(head, tail, 5);
   print(head);
   print(tail);

    return 0;
}