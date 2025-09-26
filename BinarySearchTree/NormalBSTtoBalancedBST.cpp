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

void inorder(Node* root, vector<int> &inorderVal)
{
    if(root == NULL) return;

    //left
    inorder(root->left, inorderVal);

    // node
    inorderVal.push_back(root->data);

    //right
    inorder(root->right, inorderVal);
}


Node* inorderBST(int s, int e, vector<int> inorderVal)
{
    // base case
    if(s > e) return NULL;

    int mid = (s+e)/2;

    Node* root = new Node(inorderVal[mid]);

   // left
   root->left =  inorderBST(s, mid-1, inorderVal);
   // right
   root->right = inorderBST(mid+1, e, inorderVal);

   return root;
}


Node* balancedBST(Node* root)
{
    vector<int> inorderVal;

    inorder(root, inorderVal);

    return inorderBST(0, inorderVal.size()-1, inorderVal);
}


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



int main()
{
    Node* root = NULL;
    cout<<"Enter a data for BST :"<<endl;
    takeInput(root);


    cout<<" levelOrderTraversal :"<<endl;
    levelOrederTraversal(root);

    cout<<"Normal BST To Balanced BST :"<<endl;
    root = balancedBST(root);
    levelOrederTraversal(root);

}