#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    


};

void insertNode(Node* &tail, int element, int data){
    //Empty List
    if(tail==NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode-> next = newNode;
    }
    else{
        //Non-Empty List
        //Assuming that the element is present in the list

        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        //Element Found
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);

    cout<<endl;
}

int main(){
    
    
    Node* tail = NULL;

    //Empty
    insertNode(tail, 2, 1);
    print(tail);
    insertNode(tail, 1, 2);
    insertNode(tail, 2, 3);
    insertNode(tail, 3, 4);
    insertNode(tail, 4, 5);
    print(tail);

    return 0;
}