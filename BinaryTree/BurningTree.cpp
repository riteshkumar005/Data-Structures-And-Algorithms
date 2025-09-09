#include<iostream>
#include<map>
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


Node* buildTree(Node* root)
{
    cout<<"Enter the data :"<<endl;
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

Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent)
{

    Node* targetNode = NULL;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->data == target)
        {
            targetNode = temp;
        }

        if(temp->left)
        {
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }

        if(temp->right)
        {
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }

      return targetNode;
}

int burnTree(Node* root, map<Node*, Node*> &nodeToParent)
{
    map<Node*, bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty())
    {
        bool flag = false;
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            // process neighbouring nodes
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if(front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }

             
        }

        if(flag == true)
                 ans++;
       
    }


    return ans;
}



int minTime (Node* root, int target)
{
    // step 1: create nodeToParent Mapping
    // step 2: find target node
    
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);

    // step 3: burn the tree in min time
    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}
int main()
{
    Node* root = NULL;
    root = buildTree(root);

    int target;
    cout<<"Enter a target :"<<endl;
    cin>>target;
    cout<<"Minimum Time TO Burn A Tree :"<<endl;

    cout<< minTime(root, target);

    return 0;
}