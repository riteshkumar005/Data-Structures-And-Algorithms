#include<iostream>
#include<queue>
#include<vector>

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

Node* insertBST(Node* root, int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(root->data > d)
    {
       root->left = insertBST(root->left, d);
    }else{
        root->right = insertBST(root->right, d);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertBST(root, data);
        cin>>data;
    }
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

void inorder(Node* root, vector<int> &bst)
{
    if(root == NULL)  return;

    //left
    inorder(root->left, bst);
    //node
    bst.push_back(root->data);
    //right
    inorder(root->right, bst);
}

vector<int> mergeArrays(vector<int> bst1, vector<int> bst2)
{

    vector<int> arr(bst1.size()+bst2.size());

    int i=0, j=0, k=0;

    while(i<bst1.size() && j<bst2.size())
    {
        
            if(bst1[i] < bst2[j]){
                arr[k++] = bst1[i];
                i++;
            }else{
                arr[k++] = bst2[j];
                j++;
            }
       
    }

    while(i<bst1.size())
    {
        arr[k++] = bst1[i];
        i++;
    }

    while(j<bst2.size())
    {  
        arr[k++] = bst2[j];
        j++;
    }

    return arr;
}

Node* inorderToBST(int s, int e, vector<int> mergeArray)
{

    // base case
    if(s>e) return NULL;

    int mid = (s+e)/2;

    Node* root = new Node(mergeArray[mid]);

    root->left = inorderToBST(s, mid-1, mergeArray);

    root->right = inorderToBST(mid+1, e, mergeArray);

    return root;
}
Node* mergeBST(Node* root1, Node* root2)
{

    // step1
    vector<int> bst1, bst2;
    
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step2 : merger both sorted array
    vector<int> mergeArray = mergeArrays(bst1, bst2);

    // step3 : 

    int s=0, e = mergeArray.size()-1;
    return inorderToBST(s, e, mergeArray);
}

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;
    cout<<"Enter a data for a first BST :"<<endl;
    takeInput(root1);

    cout<<"Enter a data for a second BST :"<<endl;
    takeInput(root2);

    cout<<"levelOrderTraversal of first BST :"<<endl;
    levelOrderTraversal(root1);

    cout<<"levelOrderTraversal of second BST :"<<endl;
    levelOrderTraversal(root2);

    Node* root3 = mergeBST(root1, root2);
    
    cout<<"levelOrderTraversal of merged BST :"<<endl;
    levelOrderTraversal(root3);




    return 0;
}