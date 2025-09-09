#include<iostream>
#include<queue>

using namespace std;


class node{
    public:
      int data;
      node* left;
      node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }  

};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1)
      return NULL;

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void inorder(node* root, int &count){
    if(root == NULL){
        return;
    }

    inorder(root->left, count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }

    inorder(root->right, count);
}

int noOfLeafNodes(node* root){
    int count=0;
    inorder(root, count);

    return count;
}
int main(){

    node* root = NULL;
    root  = buildTree(root);
   
   cout<<"Number of Leaf Node  "<< noOfLeafNodes(root); 


    return 0;
}