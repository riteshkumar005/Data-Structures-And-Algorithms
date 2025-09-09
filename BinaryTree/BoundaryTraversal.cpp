#include<iostream>
#include<vector>

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
    cout<<"Enter a data :"<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter a data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter a data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

}

void traverseLeft(Node* root, vector<int> &ans)
{
    //base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left, ans);
    }
    else{
        traverseLeft(root->right, ans);
    }

}

void traverseLeaf(Node* root , vector<int> &ans)
{
    //base case
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans)
{
    //base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right, ans);
    }
    else{
        traverseRight(root->left, ans);
    }

    //wapas aagy
    ans.push_back(root->data);

}
vector<int> boundary(Node* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    //left part store
    traverseLeft(root->left, ans);

    
    // leave node store
    // 1. traverse left subtree
    traverseLeaf(root->left, ans);

    // 2. traverse right subtree
    traverseLeaf(root->right, ans);

    //right part store
    traverseRight(root->right, ans);

    return ans;


}

int main(){

    Node* root = NULL;
    root = buildTree(root);

    vector<int> ans;
    cout<<"Boundary travesal of Binary Tree :"<<endl;
    ans = boundary(root);
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}