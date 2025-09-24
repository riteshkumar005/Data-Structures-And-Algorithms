#include<iostream>

using namespace std;


class Node
{
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

Node* insertIntoBST(Node* root, int d)
{
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }

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

//recursive way
bool searchInBST(Node* root, int x)
{
    if(root == NULL) return false;

    if(root->data == x) 
        return true;

    if(x > root->data)
        //right part
        return searchInBST(root->right, x);
    else
       //left part
       return searchInBST(root->left, x);
}

//Iterative way

// bool searchInBST(Node* root, int x)
// {
//     Node* temp = root;

//     while(temp != NULL)
//     {
//         if(temp->data == x)
//             return true;
        
//         if(root->data > x)
//             temp = temp->left;
            
//         else
//             temp = temp->right;
//     }

//     return false;
// }

int main()
{
    Node* root = NULL;
    cout<<"Enter the data for BST"<<endl;
    takeInput(root);

    cout<<"Data for found"<<endl;
    int val;
    cin>>val;
    cout<<"search in BST : "<< searchInBST(root, val);

}