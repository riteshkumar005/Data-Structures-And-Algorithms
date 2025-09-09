#include<iostream>
#include <vector>
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

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

} 

void solve(Node* root, vector<int> &ans, int level){
    //base case

    if(root == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}


vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}


int main()
{
    Node* root = NULL;
    root = buildTree(root);

    vector<int> ans;
    cout<<"Left View of Binary Tree "<<endl;
    ans = leftView(root); 

    for(auto i : ans){
        cout<<i<<" ";
    }

}