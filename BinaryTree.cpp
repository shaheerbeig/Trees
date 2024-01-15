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

class binarytree{
    public:

    Node* insertionattree(){
        Queue<Node*>q;
        int data,rightdata,leftdata;
        Node *root;
        cout<<"Enter the root data: ";
        cin>>data;
        root = new Node(data);
        q.push(root);

        while(!q.isempty()){
            Node *temp = q.peek();
            q.pop();
            cout<<"Enter data for the left node "<<temp->data<<endl;
            cin>>leftdata;
            if(leftdata != -1){
                temp->left = new Node(leftdata);
                q.push(temp->left);
            }
            cout<<"Enter data for the right node "<<temp->data<<endl;
            cin>>rightdata;
            if(rightdata != -1){
                temp->right = new Node(rightdata);
                q.push(temp->right);
            }
        }
        return root;
    }

    
    void orderleveltraversalprint(Node *root){
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
                    if(temp->left != NULL){
                        q.push(temp->left);
                    }
                    if(temp->right != NULL){
                        q.push(temp->right);
                    }
            }
        }
    }


    Node* search(Node *root , int find){
        if(root == NULL){
            return NULL;
        }

        if(root->data == find){
            return root;
        }
        else if(root->left != NULL){
            root->left = search(root->left,find);
        }
        else if(root->right != NULL){
            root->right= search(root->right,find);
        }
    } 

    int getsize(Node *root){
        int ctr=0;
        Queue<Node*>q;
        q.push(root);
        ctr++;
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
                    if(temp->left != NULL){
                        q.push(temp->left);
                        ctr++;
                    }
                    if(temp->right != NULL){
                        q.push(temp->right);
                        ctr++;
                    }
            }
        }
        return ctr;
    }

    int getheight(Node *root){
        int height=0;
        Queue<Node*>q;
        q.push(root);
        q.push(NULL);

        while(!q.isempty()){

            Node *temp = q.peek();
            q.pop();
            if(temp == NULL){
                cout<<endl;
                height++;
                if(!q.isempty()){
                    q.push(NULL);
                }
            }
            else{
                    cout<<temp->data<<" ";
                    if(temp->left != NULL){
                        q.push(temp->left);
                    }
                    if(temp->right != NULL){
                        q.push(temp->right);
                    }
            }
        }
        return height;
    }
};

int main(){
    binarytree b;
    int val;
    Node *root = NULL;
    Node *temp = NULL;
    //creating a tree using level order traversal
    root = b.insertionattree();
    cout<<endl;
    cout<<"Printing the Binary tree using level order traversal."<<endl;
    b.orderleveltraversalprint(root);

    cout<<endl;
    cout<<"Enter Node to search: ";
    cin>>val;
    temp = b.search(root,val);
    if(temp == NULL){
        cout<<"Data Not Found"<<endl;
    }
    else{
        cout<<"Data Found"<<endl;
    }

    cout<<endl;
    int size = b.getsize(root);
    cout<<"The size of the whole binary tree is: "<<size<<endl;

    cout<<endl;
    int height = b.getheight(root);
    cout<<"The Height of the whole binary tree is: "<<height<<endl;
}