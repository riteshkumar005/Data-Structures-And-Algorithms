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

    ~Node(){
        int value = this->data;

        if(this->next != NULL){
            delete this;
            this->next=NULL;
        }

        cout<<"memory release for data"<<" "<<value<<endl;
    }
    


};

Node* divideCircularLL(Node* &tail){
    
    Node* slow = tail->next;
    Node* fast = tail->next->next;

    while(fast->next != tail->next){
        fast = fast->next;
        if(fast->next != tail->next){
            fast = fast->next;
        }
        slow = slow->next;

    }

    
    Node* temp1 = slow->next;
    Node* temp2 = tail->next;
     fast->next = temp1;
    slow->next = temp2;
   

    return slow;
}

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
    insertNode(tail, 1, 2);
    insertNode(tail, 2, 3);
    insertNode(tail, 3, 4);
    insertNode(tail, 4, 5);
    insertNode(tail, 5, 6);
    print(tail);
    cout<<"After break from mid"<<endl;
    Node* mid = divideCircularLL(tail);
    print(mid);
    print(tail);


    return 0;
}