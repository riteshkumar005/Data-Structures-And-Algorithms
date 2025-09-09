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

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


void createMapping(vector<int> &in, int n, map<int, int> &nodeToIndex)
{
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(vector<int> &in, vector<int> &post, int index, 
    int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex )
    {
        //base case
        if(index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = post[index--];

        Node* root = new Node(element);

        int position = nodeToIndex[element];

        root->right = solve(in, post, index, position+1, inorderEnd, n, nodeToIndex );
        root->left =  solve(in, post, index, inorderStart, position-1, n, nodeToIndex );
      

        return root;

    }

Node* buildTree(vector<int> &in,vector<int> &post,  int n){

    int postIndex = n-1;
    map<int, int> nodeToIndex;
    createMapping(in, n , nodeToIndex);

    Node* ans = solve(in, post, postIndex, 0, n-1, n, nodeToIndex );
    return ans;
}


void  levelOrderTraversal(Node* root)
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

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}





int main()
{
    cout<<"Enter a size of vector :"<<endl;
    int n;
    cin>>n;

    cout<<"Inorder :"<<endl;
    vector<int> in(n);
    
    for(int i=0; i<n; i++){
        cin>>in[i];
    }

    cout<<"Postorder :"<<endl;
    vector<int> post(n);

    for(int i=0; i<n; i++){
        cin>>post[i];
    }

    Node* root = buildTree(in, post, n);

    cout<<"level order traversal :"<<endl;
    levelOrderTraversal(root);

    return 0;
}