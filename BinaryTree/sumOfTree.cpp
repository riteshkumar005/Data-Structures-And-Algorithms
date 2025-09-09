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
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1)
       return NULL;
    
    cout<<"Enter a data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter a data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

pair<bool, int> isSumFast(Node* root){
    //base case
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // leaf node
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumFast(root->left);
    pair<bool, int> rightAns = isSumFast(root->right);

    bool isleftSumTree = leftAns.first;
    bool isrightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool cond = root->data == leftSum + rightSum;

    pair<bool, int> ans;
    if(isleftSumTree && isrightSumTree && cond){
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root){
    return isSumFast(root).first;
}
int main(){
    Node* root = NULL;
    
    root = buildTree(root);

    cout<<"Sum of Tree "<< isSumTree(root)<<endl;
}
