#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* solve(vector<int> preorder, int mini, int maxi, int &i)
{

    // base case
    if(i > preorder.size()) return NULL;

    if(preorder[i]<mini || preorder[i]>maxi) return NULL;

    Node* root = new Node(preorder[i++]);

    root->left = solve(preorder, mini, root->data, i);

    root->right = solve(preorder, root->data, maxi, i);

    return root;
}


Node* preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;

    int i = 0;

    return solve(preorder, mini, maxi, i);

}



void levelOrederTraversal(Node* root)
{
    if(root == NULL)  return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";

            if(temp->left) q.push(temp->left);

            if(temp->right) q.push(temp->right);
        }
    }

}


int main()
{
    cout<<"Enter a size of vector :"<<endl;
    int size;
    cin>>size;

    vector<int> preorder(size);

    for(int i=0; i<size; i++)
    {
        cin>>preorder[i];
    }

    Node* root = preorderToBST(preorder);
    


    cout<<" levelOrderTraversal :"<<endl;
    levelOrederTraversal(root);


}