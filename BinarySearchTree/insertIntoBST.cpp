#include<iostream>
#include<queue>
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
    //base case
    if(root == NULL)
    {
       root =   new Node(d);
       return root;
    }

    if(d > root->data)
    {
        //right part me insert
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //left par me insert
        root->left = insertIntoBST(root->left, d);
    }

    return root;

}

void levelOrderTraversal(Node* root)
{
    if(root == NULL)  return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left)
              q.push(temp->left);

            if(temp->right)
               q.push(temp->right);
        }
    }
}


void inorder(Node* root)
{
    if(root == NULL)
         return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void takeInput(Node* &root)
{
    int data;
    cin>> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing the inorder"<<endl;
    inorder(root);

    return 0;
}