#include<iostream>
#include<stack>

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

Node* buildTree(Node* root){
    cout<<"Enter data : "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

void postorder(Node* root){
    if(root == NULL)
       return;

    stack<Node*> st;
     st.push(root);

    stack<int> out;

   

    while(!st.empty()){
        Node* curr = st.top();
        st.pop();

        out.push(curr->data);

        if(curr->left){
            st.push(curr->left);
        }

        if(curr->right){
            st.push(curr->right);
        }
    }

    while(!out.empty()){
        cout<<out.top() <<" ";
        out.pop();
    }

}


int main(){
    Node* root = NULL;

    root = buildTree(root);

    // postorder traversal
    cout<<"postoder Traversal "<<endl;
    postorder(root);


    return 0;
}