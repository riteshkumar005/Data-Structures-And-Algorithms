#include<iostream>
#include<queue>

using namespace std;


class  node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }

};

node*  buildTree(node* root){
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;

    root = new node(data);
    if(data == -1)
        return NULL;
    
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

int height(node* node){
    if(node == NULL){
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;



    return ans;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max(op1, max(op2, op3));

    return ans;
}

int main(){

    node* root = NULL;
    root = buildTree(root);

    cout<<"Diameter of a BinaryTree"<<endl;
    cout<<diameter(root);


    return 0;
}