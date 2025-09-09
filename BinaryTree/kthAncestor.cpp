#include<iostream>
#include <limits.h>
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

Node* solve(Node* root, int &k, int node){
    //base case
    if(root == NULL)
       return NULL;
    
    if(root->data == node){
        return root;
    }

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(Node* root, int k, int node){
    Node* ans = solve(root, k, node);

    if(ans == NULL || ans->data == node)
    {
        return -1;
    }
    else{
        return ans->data;
    }

}

int main(){
    Node* root = NULL;
    root = buildTree(root); 

    cout<<"Enter Kth element :"<<endl;
    int k;
    cin>> k;
    cout<<"Enter node :"<<endl;
    int node;
    cin>>node;
    cout<<"Kth Ancestor in a Tree "<<endl;
    cout<<kthAncestor(root, k, node);




    return 0;
}