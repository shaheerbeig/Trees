#include<iostream>
#include<vector>
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

void inorder(Node *root , vector<int> &v){
    if(root == NULL){
        return ;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool findsum(Node *root , int target){
    if(root == NULL){
        return false;
    }
    vector<int> v;
    inorder(root,v);
    int sum = 0;
    int i=0;
    int j=v.size()-1;
    while(i < j){
        if(v[i] + v[j] == target){
            return true;
        }
        else if(v[i] + v[j] > target){
            j--;
        }
        else if(v[i] + v[j] < target){
            i++;
        }
    }
    return false;
}

Node* insertion(Node *root , int data){
    if(root == NULL){
        Node *temp = new Node(data);
        return temp;
    }
    if(root->data > data){
        root->left = insertion(root->left,data);
    }
    else if(root->data < data){
        root->right = insertion(root->right,data);
    }
    return root;
}
Node* takedata(Node *root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    while(data != -1){
        root = insertion(root,data);
        cin>>data;
    }
    return root;
}

int main(){
    Node *root = NULL;
    root = takedata(root);
    if(findsum(root,20)){
        cout<<"Sum found";
    }
    else{
        cout<<"not found";
    }
}