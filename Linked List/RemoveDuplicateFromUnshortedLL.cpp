#include <iostream>
#include <map>

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


/* Node* uniqueSortedList(Node* head){
    //empty list
    if(head == NULL){
        return NULL;
    }

    //non empty list
    Node* curr = head;
  

   while(curr != NULL){
      Node* forward = curr;
        while(forward->next != NULL){
            if(curr->data != forward->next->data){
                forward = forward->next;
            }
            else{
                Node* temp = forward->next->next;
                delete(forward->next);
                forward->next = temp;

            }
        }
        curr = curr->next;
   }

    return head;
}*/

Node* uniqueSortedList(Node* head){
    //Empty List
    if(head == NULL){
        return NULL;
    }

    //non empty
    map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    
        
    while (curr != NULL) {
        if (visited[curr->data]) {
            // Duplicate found
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
    
}


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
    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail = node1;
    insertAtPosition(tail,head,2,2);
    insertAtPosition(tail,head,3,5);
    insertAtPosition(tail,head,4,4);
     insertAtPosition(tail,head,5,2);
    insertAtPosition(tail,head,6,2);
    print(head);
    
    Node* sort = uniqueSortedList(head);
    print(sort);

    return 0;
}




