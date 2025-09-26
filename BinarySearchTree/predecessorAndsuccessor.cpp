#include<iostream>
#include <utility>
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
    //base case
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



// 1nd way to implement predecessor and successor
void solve(Node* root, vector<int> &arr)
{

    if(root == NULL) return;

    // left
    solve(root->left, arr);

    // Node

    arr.push_back(root->data);

    // right;

    solve(root->right, arr);
}

pair<int, int> predAndsucc(Node* root, int key)
{
    if(root == NULL)  return make_pair(0, 0);

    vector<int> ans;
    solve(root, ans);

    int i = 0;
    for(i; i<ans.size(); i++)
    {
        if(ans[i] == key){
            break;
        }
    }

    return {ans[i-1], ans[i+1]};
}



// 2nd way to implement predecessor and successor

pair<int, int> predecessorSuccessor(Node* root, int key)
{

    // find key
    Node* temp = root;

    int pred = -1;
    int succ = -1;

    while(temp != NULL && temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp->data; // possible successor
            temp = temp->left;
        }else{
            pred = temp->data;  // possible predecessor
            temp = temp->right;
        }
    }

     // If key not found, just return current pred and succ
        if(temp == NULL) {
            return {pred, succ};
        }

    // pred and succ

    //pred
    Node* leftTree = temp->left;

    while(leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ
    Node* rightTree = temp->right;

    while(rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);

    return ans;
}

void levelOrderTraversal(Node* root)
{
    // base case
    if(root == NULL) return;

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

            if(!q.empty())
            {
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
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

    cout<<"Enter the data for BST :"<<endl;
    takeInput(root);

    cout<<"levelOrderTraversal of BST :"<<endl;
    levelOrderTraversal(root);

    cout<<"key :"<<endl;
    int key;
    cin>> key;

    cout<<"predecessor And successor in BST (TC -> O(N) And SC -> O(N)) :"<<endl;
    pair<int, int> p = predAndsucc(root, key);

    cout<<"predecessor : "<<p.first<<endl;
    cout<<"successsor : "<<p.second;

    cout<<endl;

    cout<<"predecessor And successor in BST (TC -> O(N) And SC -> O(1)) :"<<endl;
    pair<int, int> ans = predecessorSuccessor(root, key);
    cout<<"predecessor : "<<ans.first<<endl;
    cout<<"successor : "<<ans.second<<endl;
    return 0;
}