#include<iostream>

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


Node* lca(Node* root, int n1, int n2){
    //base case
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }

}






int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<"Enter the element"<<endl;
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;

    cout<<"Lowest Common Ancestor "<<endl;
    cout<<lca(root, n1, n2)->data;
 




    return 0;
}