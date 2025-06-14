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
    }
};

void insertNode(Node* &tail, int element, int data){
    //Empty List
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else{
         //Non-empty list
        Node* curr = tail;
        
        while(curr->data != element){
            curr = curr->next;
        }

        //Element found
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
        temp->prev = curr;
        curr->next->prev = temp;



    }

   
}

void print(Node* tail){

    if(tail == NULL){
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = tail;

    do{
        cout<<tail->data<<" ";
        tail = tail->next;

    }while(tail != temp);

    cout<<endl;   
}

int main(){
    Node* tail = NULL;
    insertNode(tail, 5, 1);
    print(tail);
    insertNode(tail, 1, 2);
    insertNode(tail, 2, 3);
    insertNode(tail, 3, 4);
    print(tail);

    return 0;
}