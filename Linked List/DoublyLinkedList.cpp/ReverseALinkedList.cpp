#include <iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;

    }

    ~Node(){
        int value = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory free for the value"<<" "<<value;
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

Node* reverseLinkedList(Node* &head) {
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is current->prev after swapping)
        current = current->prev;
    }

    // Fix the head of the reversed list
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
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

   Node* rev = reverseLinkedList(head);
   print(rev);

    return 0;
}