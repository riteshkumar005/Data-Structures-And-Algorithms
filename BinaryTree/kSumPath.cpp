#include<iostream>
#include<vector>
using namespace std;

class Node
{
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


Node* buildTree(Node* root)
{
    cout<<"Enter a data :"<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

} 


void printVector(const vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
void solve(Node* root, int k, int &count, vector<int> path)
{
    //base case
    if(root == NULL)
       return;

    path.push_back(root->data);

    //left
    solve(root->left, k, count, path);

    //right
    solve(root->right, k, count, path);

    //check for k sum
    int size = path.size();
    int sum =0;


    for(int i=size-1; i>=0; i--)
    {
        sum+=path[i];
        if(sum == k){
 
            printVector(path, i);
        //    count++;
        }
          

    }

    path.pop_back();

}

void sumK(Node* root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);

    // return count;
}

int main()
{ 
    Node* root = NULL;

    root = buildTree(root);

    cout<<"Enter Sum Path :"<<endl;
    int k;
    cin>>k;

    cout<<"K Sum Path "<<endl;
    sumK(root, k);



    return 0;
}