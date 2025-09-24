#include<iostream>
#include<queue>

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







Node* buildBST(Node* &root, int d)
{
    if( root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(root->data > d){
        root->left = buildBST(root->left, d);
    }
    else{
        root->right = buildBST(root->right, d);
    }

    return root;
}


void levelOrderTraversal(Node* root)
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

            if(!q.empty())
            {
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";

            if(temp->left)  q.push(temp->left);

            if(temp->right)  q.push(temp->right);
        }
    }
}


int kthSmallest(Node* root, int &i, int k)
{
    if(root == NULL)  return -1;

    //left 

    int left = kthSmallest(root->left, i, k);

    if(left != -1) return left;

    // Node
    i++;
    
    if(i == k){
        return root->data;
    }

    // right
    return kthSmallest(root->right, i, k);
}

void numNodes(Node* root, int &count)
{
        if(root == NULL)  return;
        
        // left 
        numNodes(root->left, count);
        
        //nodes
        count ++;
        
        // right
        numNodes(root->right, count);
       
   
}


int kthLargest(Node* root, int &j, int m, int n)
{
    if(root == NULL)  return -1;


    //left 

    int left = kthLargest(root->left, j, m, n);

    if(left != -1) return left;

    // Node
    j++;
    
    if(j == (n-m)+1){
        return root->data;
    }

    // right
    return kthLargest(root->right, j, m, n);
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = buildBST(root, data);
        cin>>data;
    }
}

int main()
{
    Node* root = NULL;

    cout<<"Enter the data for BST"<<endl;
    takeInput(root);

    cout<<"levelOrderTraversal :"<<endl;
    levelOrderTraversal(root);

    cout<<"enter kth smallest : "<<endl;
    int k;
    cin>> k;
    int i=0;
    cout<<"kth_smallest : "<<kthSmallest(root,i, k)<<endl;

    int n = 0;
    numNodes(root, n);
    cout<<"Number of Nodes : "<<n<<endl;

    cout<<"enter kth largest : "<<endl;
    int m;
    cin>> m;
    int j = 0;
    cout<<"kth_largest : "<<kthLargest(root, j , m, n)<<endl;
    return 0;
}