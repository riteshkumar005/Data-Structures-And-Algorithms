#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int value) {
    if (head == NULL) return;

    if (value == head->data) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
            
    while (curr != NULL && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }


        if (curr == NULL) {
            cout << "Position out of bounds, no deletion performed.\n";
            return;
        }

        prev->next = curr->next;
        if(curr == tail){
            tail=prev;
        }
        
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtPosition(head, tail, 2, 20);
    insertAtPosition(head, tail, 3, 30);
    insertAtPosition(head, tail, 4, 40);
    insertAtPosition(head, tail, 5, 50);
    insertAtPosition(head, tail, 6, 60);

    cout << "List after insertions:\n";
    print(head);

    print(tail);

    // deleteNode(head,tail 1);  // Deletes 10
    deleteNode(head, tail ,10);  // Deletes 60
    
    cout << "List after deletions:\n";
    print(head);
    print(tail);


    return 0;
}
