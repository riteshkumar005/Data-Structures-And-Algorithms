#include<iostream>

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
    cout<<"Enter data :"<<endl;
    int data;
    cin>> data;

    root = new Node(data);

    if(data == -1)
        return NULL;
    
    cout<<"Enter data for inserting in left of "<< data <<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting in right of "<< data <<endl;
    root->right = buildTree(root->right);

    return root;
}

void flatten(Node* root){
    Node* curr = root;

    while(curr != NULL)
    {
        if(curr->left != NULL)
        {
            Node* IP = curr->left;

            while(IP->right != NULL && IP->right != curr){
                IP = IP->right;
            }

            IP->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

void inorder(Node* root)
{
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main(){
    Node* root = NULL;

   root =  buildTree(root);

   cout<<"Flatten Binary Tree TO Linked List"<<endl;
   flatten(root);

   inorder(root);

    return 0;
}