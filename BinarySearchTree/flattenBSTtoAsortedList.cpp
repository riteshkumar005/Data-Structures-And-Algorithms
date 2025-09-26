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
void inorder(Node* root, vector<int> & inorderVal)
{
    //base case
    if(root == NULL)  return;

    //left 
    inorder(root->left, inorderVal);

    // node
    inorderVal.push_back(root->data);

    // right
    inorder(root->right, inorderVal);
}
Node* flatten(Node* root)
{
    vector<int> inorderVal;
    // store inorder -> sorted value
    inorder(root, inorderVal);

    int  n = inorderVal.size();
    Node* newNode = new Node(inorderVal[0]);
    Node* curr = newNode;

    for(int i =1; i<n; i++)
    {
        Node* temp = new Node(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newNode;
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

void listTraversal(Node* root)
{
    
    Node* curr = root;
    while(curr != NULL)
    {
        cout<<curr->data<<" ";

        curr = curr->right;
    }
}



int main()
{
    Node* root = NULL;
    cout<<"Enter a data for BST :"<<endl;
    takeInput(root);
    cout<<"levelOrderTraversal of BST :"<<endl;
    levelOrderTraversal(root);

    //Flatten BST To A Sorted List
    Node* newRoot = flatten(root);
    cout<<"Traversal of a sorted list :"<<endl;
    listTraversal(newRoot);


    return 0;
}