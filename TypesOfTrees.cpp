#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertinthetree(){
    int data;
    
    cout<<"Enter data: ";
    cin>>data;
    if(data == -1){
        return NULL;
    }
    //we have created a root node;
    Node *root = NULL;
    root = new Node(data);

    cout<<"Enter left Node data of: "<<root->data<<endl;
    root->left = insertinthetree();  
    cout<<"Enter right Node data of: "<<root->data<<endl;
    root->right = insertinthetree();

    return root;
}

//check if the binary tree is a search tree or not
bool checkisbinarysearch(Node *root){
    bool flag1 , flag2;
    //empty tree
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left != NULL && root->right != NULL){
        if(root->left->data < root->data){
            flag1 = checkisbinarysearch(root->left);
        }
        else{
            return false;
        }
        if(root->right->data > root->data){
            flag2 = checkisbinarysearch(root->right);
        }
        else{
            return false;
        }
    }
    if((flag1 && flag2) == true){
        return true;
    }
    else{
        return false;
    }
}

//check if the binary tree is full or not 
bool checkisfull(Node *root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)){
        return false;
    }
    if(root->left != NULL && root->right != NULL){
        return checkisfull(root->left) && checkisfull(root->right);
    }
    return false;
}

//check if the binary tree is perfect tree or not
int calculatedept(Node *root){
    int d=0;
    Node *temp = root;
    while(temp->right != NULL){
        d++;
        temp= temp->right;
    }
    return d;
}
bool checkisperfect(Node *root , int d , int level=0){
    if(root == NULL){
        return true;
    }
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        if(d == level + 1){
            return true;
        }
        else{
            return false;
        }
    }
    return checkisperfect(root->left,d,level+1) && checkisperfect(root->right,d,level+1);

}

bool perfect(Node *root){
    int d = calculatedept(root);
    bool found = checkisperfect(root,d,0);
    return found;
}

//check if degenertaed tree or not
bool checkisdegenerated(Node *root){
    if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)){
        return true;
    }
    if(root == NULL){
        return false;
    }
    if(root->left != NULL && root->right != NULL){
        return false;
    }
    return checkisdegenerated(root->left) && checkisdegenerated(root->right);
}

int main(){
    Node *root = NULL;
    root = insertinthetree();

    if(checkisbinarysearch(root)){
        cout<<"The tree is a Binary Search tree"<<endl;
    }
    else{
        cout<<"Not a Binary Search tree"<<endl;
    }
    cout<<endl;
    if(checkisfull(root)){
        cout<<"The tree is a full tree"<<endl;
    }
    else{
        cout<<"Not a full tree"<<endl;
    }
    cout<<endl;
    if(checkisdegenerated(root)){
        cout<<"The tree is a degenerated tree"<<endl;
    }
    else{
        cout<<"Not a degenerated tree"<<endl;
    }
    cout<<endl;
    if(perfect(root)){
        cout<<"The tree is a Perfect tree"<<endl;
    }
    else{
        cout<<"Not a Perfect tree"<<endl;
    }
}