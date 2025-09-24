#include<iostream>
#include<vector>
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


Node* buildTree(Node* root)
{
    cout<<"Enter a data :"<<endl;
    int data;
    cin>>data;

    if(data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter the data inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    
    cout<<"Enter the data inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}


vector<int> inorder(Node* root)
{
    vector<int> ans;
    Node* curr = root;

    while(curr != NULL)
    {
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            //find the IP
            Node* IP = curr->left;
            while(IP->right != NULL && IP->right != curr)
            {
                IP = IP->right;

            }

            if(IP->right == NULL){
                IP->right = curr; //create
                curr = curr->left;
            }
            else{
                IP->right = NULL; //destroy
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}


int main()
{
    Node* root = NULL;
    root = buildTree(root);

    cout<<"Morris Inorder Traversal :"<<endl;
    vector<int> ans = inorder(root);

   for(auto i : ans){
    cout<< i <<" ";
   }


    return 0;
}