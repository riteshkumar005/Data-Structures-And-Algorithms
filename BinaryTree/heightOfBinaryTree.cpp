#include<iostream>
#include<queue>
using namespace std;

class  node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }

};

void buildFromLevelOrder(node* &root){
    queue<node*> q;

    cout<<"enter the data for root"<< endl;
    int data;
    cin>>data;

    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

int height(node* node){
    if(node == NULL){
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;



    return ans;
}



int main(){
    node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"height of tree is "<<height(root);

    return 0;
}