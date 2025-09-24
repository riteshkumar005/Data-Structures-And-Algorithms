#include<iostream>

using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* insertIntoBST(Node* root, int d)
{
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data)
        root->right = insertIntoBST(root->right, d);
    else
        root->left = insertIntoBST(root->left, d);


    return root;
}


void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

Node* maxVal(Node* root)
{
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;

}

int main()
{
    Node* root = NULL;
    cout<<"Enter the data for BST"<<endl;
    takeInput(root);

    cout<<"MAX val of BST : "<< maxVal(root)->data;

    return 0;
}