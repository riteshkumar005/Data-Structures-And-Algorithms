#include<iostream>
#include<stack>

using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>> data;

    root = new Node(data);

    if(data == -1)
        return NULL;
    
    cout<<"Enter data inserting of left of "<< data <<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data inserting of right of "<< data << endl;
    root->right = buildTree(root->right);

    return root;

}


void inorder(Node* root){
    stack<Node*> st;
    Node* curr = root;

    while(!st.empty() || curr != NULL){
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            st.pop();
            cout<< curr->data << " ";
            curr = curr->right;
        }
    }

}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    // Inorder Traversal

    inorder(root);
}
