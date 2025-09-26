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

Node* insertBST(Node* root, int d)
{
    // base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(root->data > d)
    {
        root->left = insertBST(root->left, d);
    }else{
        root->right = insertBST(root->right, d);
    }

    return root;
}

// recursive way
Node* lcaInBST(Node* root, int a, int b)
{
    //base case
    if(root == NULL)  return NULL;

    if(root->data < a && root->data < b)
    {
        return lcaInBST(root->right, a, b);
    }

    if(root->data > a && root->data > b)
    {
        return lcaInBST(root->left, a, b);
    }

    return root;
}

// iterative way
Node* LcaInBST(Node* root, int p, int q)
{
    if(root == NULL) return NULL;

    while(root != NULL)
    {
        if(root->data > p && root->data > q)
        {
            root = root->left;
        }
        else if(root->data < p && root->data < q)
        {
            root = root->right;
        }
        else{
            return root;
        }
    }
}
void levelOrederTraversal(Node* root)
{
    if(root == NULL)  return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";

            if(temp->left) q.push(temp->left);

            if(temp->right) q.push(temp->right);
        }
    }

}


void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertBST(root, data);
        cin>>data;
    }
}


int main()
{
    Node* root = NULL;
    cout<<"Enter a data for BST :"<<endl;
    takeInput(root);

    cout<<" levelOrderTraversal :"<<endl;
    levelOrederTraversal(root);

    cout<<"Enter a And b for Ancestor"<<endl;
    int a, b;
    cin>>a;
    cin>>b;
    cout<<" lowest common ancestor in BST (recursive) :"<<endl;
    cout<<lcaInBST(root, a, b)->data;
    
    cout<<endl;
    cout<<" lowest common ancestor in BST (iterative) :"<<endl;
    cout<<LcaInBST(root, a, b)->data;


    return 0;
}