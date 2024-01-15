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


///global function

//insertion in to BST
Node* insertintoBST(Node *root , int data){
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

Node* takedata(Node *root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertintoBST(root,data);
        cout<<"Enter data again: ";
        cin>>data;
    }
    return root;
}

//searching a value in BST

bool search(Node *root , int data){
    if(root->data == data){
        return true;
    }
    if(root == NULL){
        return false;
    }
    if(data > root->data){
        return search(root->right,data);
    }
    else{
        return search(root->left,data);
    }
    if(root->data != data){
        return false;
    }
}
    
//Maximum in the BST
Node* max(Node *root){
    Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

//deletion from a BST
 Node *deletefromBST(Node *root , int value){
    if(root == NULL){
        return root;
    }

        //this is the case if the roots initial data is equal to the value to be deleted.
    if(root->data == value){
            //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
            //1 child
            //left child
        if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
            //right child
        if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
            //2 child
        if(root->left != NULL && root->right != NULL){
                //in this case we can use 2 approac. go to left subtree and find the maximum or got to right tree of search the maximum.
            int minvalue = max(root) ->data;
                //here from the min function we are calculating the minimum value.
            root->data = minvalue;
            root->right = deletefromBST(root->right,minvalue);
            return root;
        }
        }
        else{
        if(root->data > value){
                //searching in the left side.
            root->left = deletefromBST(root->left,value);
            return root;
        }
        else{
            root->right = deletefromBST(root->right,value);
            return root;
        }
    }
}

//calculating size of the BST
int getsize(Node *root){
    if (root == NULL) {
        return 0;
    }
    
    // Recursively calculate the size of the left and right subtrees
    int left = getsize(root->left);
    int right = getsize(root->right);

    return 1 + left + right;
}

//calculating the height of the BST
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

void inorder(Node *root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    cout<<"Inserting values in the BST."<<endl;
    cout<<"Enter data to be inserted in the tree: ";
    Node *root=  NULL;
    Node *temp = NULL;
    int val,val2;
    cout<<endl;
    temp = takedata(root);
    cout<<endl;

    cout<<"Printing In-order."<<endl;
    inorder(temp);
    cout<<endl;

    cout<<"Deleting Value from the BST."<<endl;
    cout<<"Enter value to delete: ";
    cin>>val2;
    root = deletefromBST(temp,val2);
    cout<<endl;

    cout<<"Printing In-order After deletion."<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Enter value to search: ";
    cin>>val;
    if(search(root,val)){
        cout<<"Value is found"<<endl;
    }
    else{
        cout<<"Value is not Found"<<endl;
    }

    int ctr;
    ctr = getsize(root);
    cout<<"The size of the Binary Search Tree is: "<<ctr<<endl;

    int height=0;
    height = getheight(root);
    cout<<"The height of the Binary Search Tree is: "<<height<<endl;
}