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
    insertAtHead(head, 12);
    insertAtHead(head, 15);
    print(head);

    return 0;
}


