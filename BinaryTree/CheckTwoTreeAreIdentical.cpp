#include<iostream>

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

bool isIdentical(Node* r1, Node* r2){

    // base case
    if(r1 == NULL && r2 == NULL)
        return true;
    
    if(r1 == NULL && r2 !=NULL)
        return false;
    
    if(r1 != NULL && r2 == NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);

    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }

    
}



int main(){
    Node* r1 = NULL;
    r1 = buildTree(r1);

    Node* r2 = NULL;
    r2 = buildTree(r2);

    cout<<"Tree is "<<isIdentical(r1, r2) <<" identical";
    
    


    return 0;
}