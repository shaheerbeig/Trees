#include<iostream>
using namespace std;

//this node class is for binary tree
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

template  <class T>
//this node class is for queue
class NodeQueue{
    public:
    T data;
    NodeQueue<T> *next;

    NodeQueue(T data){
        this->data = data;
        next = NULL;
    }
};

template <class T>
class Queue{
	public:
		NodeQueue<T> *rear;
		NodeQueue<T> *front;
		
	Queue(){
		rear = NULL;
		front = NULL;
	}
	
	//to insert in the queue
	void push(T data){
		NodeQueue<T> *tempnode = new NodeQueue<T>(data);
		
		if(front==NULL){
			front = rear = tempnode;
		}
		else{
			rear->next = tempnode;
			rear = tempnode;
		}
	}
	
	//to remove from the queue
	T pop(){
		if(front==NULL){
			cout<<"Queue is empty: "<<endl;
			return 0;
		}
		else{
			NodeQueue<T> *temp = front;
			front = front->next;
			temp->next = NULL;
			return temp->data;
			delete temp;
		}
	}
	
	//to check if queue is empty
	bool isempty(){
		if(front==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	T peek(){
		if(!isempty()){
			return front->data;
		}
		else{
			cout<<"Empty Queue."<<endl;
		}
	}

};
 
    Node* insertintoBST(Node *root , int data){
        
        if(root == NULL){
            root = new Node(data);
            return root;
        }

        if(data > root->data){
            root->right = insertintoBST(root->right,data);
        }

        if(data < root->data){
            root->left = insertintoBST(root->left,data);
        }
        return root;
    }

    Node* takeuserdata(Node *root){
        int data;
        cout<<"Enter the data: ";
        cin>>data;
        while(data != -1){
            root = insertintoBST(root,data);
            cout<<"Enter the data: ";
            cin>>data;
        }
        return root;
    }

    //traversals
    void inorder(Node *root){
        if(root == NULL){
            return ;
        }

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void postorder(Node *root){
        if(root == NULL){
            return ;
        }

        inorder(root->left);
        inorder(root->right);
        cout<<root->data<<" ";
    }

    void preorder(Node *root){
        if(root == NULL){
            return ;
        }

        cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
    }

    void levelordertraversal(Node *root){
    Queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.isempty()){
        Node *temp = q.peek();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.isempty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
              if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    
    Node *root = NULL;
    Node *tem =NULL;
    tem = takeuserdata(root);
    
    cout<<"Printing In-Order: "<<endl;
    inorder(tem);
    cout<<endl;

    cout<<"Printing Post-Order: "<<endl;
    postorder(tem);
    cout<<endl;

    cout<<"Printing Pre-Order: "<<endl;
    preorder(tem);
    cout<<endl;

    cout<<"Printing Level-order Traversal: "<<endl;
    levelordertraversal(root);
    cout<<endl;
}