#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *insertintoBST(Node *root , int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertintoBST(root->left,data);
    }
    else if(data > root->data){
        root->right = insertintoBST(root->right,data);
    }

    return root;
}

Node* takeuserinput(Node* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    while(data != -1){
        root = insertintoBST(root,data);
        cin>>data;
    }
    return root;
}

Node* LCA(Node *root , int val1 , int val2){
    //if the tree is empty
    if(root == NULL){
        return NULL;
    }

    //checking if both the value whose ancestor is to be found lies on the left
    if(root->data > val1 && root->data > val2){
        return LCA(root->left,val1,val2);
    }
    //checking if both the value whose ancestor is to be found lies on the right
    if(root->data < val1 && root->data < val2){
        return LCA(root,val1,val2);
    }
    // if bth the values are not right or not left. means one is in the left and one is in the right
    if((root->data < val1 && root->data > val2) || root->data > val1 && root->data < val2){
        return root;
    }
}

int main(){
    Node *root = NULL;
    root = takeuserinput(root);
    Node *temp = NULL;
    temp = LCA(root,4,3);
    cout<<"THE COMMON ANCESTOR IS:"<<temp->data<<endl;
}