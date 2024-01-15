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
//calculating size
int getsize(Node *root){
    if(root == NULL){
        return 0;
    }
    int right = getsize(root->right);
    int left = getsize(root->left);

    return 1 + right + left;
}

//calculating height
int getheight(Node *root){
    if(root == NULL){
        return 0;
    }
    else{
        int leftheight = getheight(root->left);
        int rightheight = getheight(root->right);

        if(leftheight > rightheight){
            return leftheight +1 ;
        }
        else{
            return rightheight+1;
        }

    }
}

//insertion into the BST
Node *insertintoBST(Node *root , int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(root->data  > data){
        root->left = insertintoBST(root->left,data);
    }
    if(root->data  < data){
        root->right = insertintoBST(root->right,data);
    }
    return root;
}

Node *takedata(Node *root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    while(data != -1){
        root = insertintoBST(root,data);
        cin>>data;
    }
    return root;
}

bool comparetree(Node *root1 , Node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }
    
    bool lefttree;
    bool righttree;

    lefttree = comparetree(root1->left,root2->left);
    righttree = comparetree(root1->right,root2->right);
    bool value ;
    if(root1->data == root2->data){
        value = true;
    }
    else{
        value = false;
    }

    if((lefttree && righttree && value )==true){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    Node *root1 = NULL;
    Node *root2 = NULL;
    cout<<"Enter data to create the binary search tree: "<<endl;
    root1 = takedata(root1);
    root2 = takedata(root2);
    cout<<endl;

    if(comparetree(root1,root2)){
        cout<<"Trees are identical."<<endl;
    }
    else{
        cout<<"Trees are not identical."<<endl;
    }
}