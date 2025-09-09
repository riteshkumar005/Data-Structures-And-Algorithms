#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node{
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

void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n)
{
    for(int i=0; i<n; i++)
    {
        nodeToIndex[inorder[i]] = i;
    }
}

Node* solve(vector<int> &inorder, vector<int> &preorder, int &index, 
    int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        // base case
        if(index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        //create a root Node for element
        int element = preorder[index++];

        Node* root = new Node(element);

        // find element index in Inorder
        int position = nodeToIndex[element];

        //recursive calls

        root->left = solve(inorder, preorder, index, inorderStart, position-1, n, nodeToIndex);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n, nodeToIndex);

        return root;
    }


Node* buildTree(vector<int> &inorder, vector<int> &preorder, int n)
{

    int preOrderIndex = 0;
    map<int, int> nodeToIndex;

    // create nodes to index mapping
    createMapping(inorder, nodeToIndex, n);
    Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n, nodeToIndex);

    return ans;
}

void levelOrderTraversal(Node* root)
{
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }

}
int main(){

    cout<<"Enter the size of vector :"<<endl;
    int n;
    cin>>n;
    
    cout<<"Inorder : "<<endl;
    vector<int> inorder(n);
    for(int i=0; i<n; i++){
        cin>>inorder[i];
    }

    cout<<"Preorder :"<<endl;
    vector<int> preorder(n);
    for(int i=0; i<n; i++){
       cin>>preorder[i];

    }

   Node* root =  buildTree(inorder, preorder,n );

   //level order traversal 
   cout<<"LevelOrder Traversal"<<endl;
   levelOrderTraversal(root);


    return 0;
}