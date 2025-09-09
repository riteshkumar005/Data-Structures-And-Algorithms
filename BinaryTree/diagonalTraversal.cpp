#include<iostream>
#include<vector>
#include <unordered_map>

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

    return root;
}

void solve(Node* root, int level, unordered_map<int, vector<int>> &levelData )
{
    if(root == NULL)
       return;

    levelData[level].push_back(root->data);

    solve(root->left, level+1, levelData); // left child goes to next diagonal
    solve(root->right, level, levelData); // right child stays in same diagonal
}
vector<int> diagonalTraversal(Node* root)
{
    vector<int> ans;
    unordered_map<int, vector<int>> levelData;

    solve(root, 0, levelData);

    int level = 0;

    while(levelData.find(level) != levelData.end())
    {
        vector<int> v = levelData[level];
        for(int j =0; j<v.size(); j++){
            ans.push_back(v[j]);
        }
        level++;
    }

    return ans;
}

void printList(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);

    vector<int> ans;
    cout<<"Diagonal Traversal of Binary Tree"<<endl;
    ans = diagonalTraversal(root);

   printList(ans);


    return 0;
}