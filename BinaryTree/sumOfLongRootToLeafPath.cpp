#include<iostream>
#include <limits.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter the data :" << endl;
    int data;
    cin >> data;

    if (data == -1)   // check before creating node
        return NULL;

    root = new Node(data);

    cout << "Enter a data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter a data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void solve(Node* root, int sum, int &maxSum,int  len, int &maxlen){
    //base case

    if(root == NULL){
        if(len > maxlen){
            maxlen = len;
            maxSum = sum;
        }
        else if(len == maxlen){
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum = sum + root->data;

    solve(root->left, sum, maxSum, len + 1, maxlen);
     solve(root->right, sum, maxSum, len + 1, maxlen);

}
int  sumOfLongRootToLeafPath(Node* root){
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxlen);

    return maxSum;

}

int main(){
    Node* root = NULL;
    
    root = buildTree(root);

    cout<<"sum of nodes on the longest path from root to leaf node"<<endl;
    cout<<sumOfLongRootToLeafPath(root);




    return 0;
}