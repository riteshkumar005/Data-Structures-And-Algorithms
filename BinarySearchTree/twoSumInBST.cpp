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
    if(root == NULL)  return;

    // left
    inorder(root->left, inorderVal);

    // Node
     inorderVal.push_back(root->data);

    // right

    inorder(root->right, inorderVal);
}

bool twoSumInBST(Node* root, int target)
{
    vector<int> inorderVal;

    inorder(root, inorderVal);

    int i=0; 
    int j = inorderVal.size() -1;

    while (i<j)
    {
       int sum = inorderVal[i] + inorderVal[j];

        if(sum == target)
            return true;

        else if(sum > target)
           j--;
        else
           i++;
    }

    return false;
    
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

    cout<<"Enter the target val :"<<endl;
    int val;
    cin>> val;
    cout<<" Two Sum in BST : "<<twoSumInBST(root, val);

}