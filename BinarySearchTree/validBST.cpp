#include<iostream>
#include<queue>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    };
};

Node* insertIntoBST(Node* root, int d) {
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(root->data > d)
        root->left = insertIntoBST(root->left, d);
    else
        root->right = insertIntoBST(root->right, d);
    
    return root;
}

void levelorderTraversal(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void takeInput(Node*& root) {   // pass by reference
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

bool isBST(Node* root, int min, int max) {
    if(root == NULL) return true;

    if(root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    return false;
}

bool validateBST(Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = NULL;
    cout << "Enter the data for BST (-1 to stop):" << endl;
    takeInput(root);

    cout << "Level Order Traversal:" << endl;
    levelorderTraversal(root);

    cout << "\nValidate BST: " << (validateBST(root) ? "YES" : "NO") << endl;
}
