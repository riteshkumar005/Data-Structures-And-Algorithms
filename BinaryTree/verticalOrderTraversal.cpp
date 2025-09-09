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

Node* buildTree(Node* root){
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter the data inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    root;
}

vector<int> verticalOrder(Node* root)
{
    map<int, map<int, vector<int>>> nodes;

    queue<pair<Node*, pair<int, int>>> q;

    vector<int> ans;

    if(root == NULL)
         return ans;
    
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty())
    {
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        }

        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }
    }

    for(auto i : nodes)
    {
        for(auto j : i.second)
        {
            for(auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}


int main()
{
    Node* root = NULL;

    root = buildTree(root);

    vector<int> ans;
    cout<<"Vertical Order Travesal "<<endl;
    ans = verticalOrder(root);

    for(auto i : ans){
        cout<<i <<" ";
    }

    return 0;
}