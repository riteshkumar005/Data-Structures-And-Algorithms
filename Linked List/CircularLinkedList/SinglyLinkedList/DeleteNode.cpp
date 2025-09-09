#include <iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //Deconstructor
    ~Node(){
        int value = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }

        cout<<"Memory free for node with data"<<" "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int data){
    //Empty List
    if(tail==NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
       
    }
    else{
        //Non-empty list
        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }

        //element found

        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;

    }

   


}


void deleteNode(Node* &tail, int value){

    if(tail == NULL){
        cout<<"List empty, please check again"<<endl;

        return;
    }
    else{
         Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;

        }
        
       
        prev->next = curr->next;

        // 1 Node linked list
        if(curr == prev){
            tail = NULL;
        }

        // >=2 Node Linked List
        if(curr == tail){
            tail=prev;
        }
        curr->next = NULL;
        delete curr;

    }
   

}

void print(Node* tail){
  
    if(tail == NULL){
        cout<<"List is empty"<<endl;
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

    insertNode(tail, 5, 1);  // Creates first node
    print(tail);

    insertNode(tail, 1, 2);
    insertNode(tail, 2, 3);
    insertNode(tail, 3, 4);
    insertNode(tail, 4, 5);
    print(tail);

    deleteNode(tail, 4);
    print(tail);



    return 0;
}