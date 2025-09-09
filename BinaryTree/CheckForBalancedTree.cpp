#include<iostream>
#include <cmath>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data :"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

pair<bool, int> isBalanced(Node* root){

    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left  = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    int diff = (left.second - left.second) <= 1;

    pair<bool, int> ans;

    ans.second = max(left.second, right.second) + 1;

    if(left.first && right.first && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;

}

int main(){

    Node* root = NULL;

    root = buildTree(root);

    cout<<"Tree is Balance  "<<isBalanced(root).first;

    return 0;
}