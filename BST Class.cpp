#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
	
    BinaryTreeNode<int>* root;
    
    public:
    
    BST(){
        root=NULL;
    }  
    
    ~BST(){
        delete root;
    }
    
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* root){
        if(root==NULL){
            BinaryTreeNode<int>* node = new BinaryTreeNode<int>(data);
            return node;
        }
        
        if(data<root->data){
            root->left=insert(data,root->left);
            return root;
        }
        
        else  {
            root->right=insert(data,root->right);
            return root;
        }
    }
    
    void insert(int data){
        this->root=insert(data,this->root);
    }
    
    int minValue(BinaryTreeNode<int>* root){
        if(root->left==NULL){
            return root->data;
        }
        return minValue(root->left);
    }
    
    BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* root){
        if(root==NULL){
            delete root;
            return NULL;
        }
        if(data>root->data){
            root->right=deleteData(data,root->right);
            return root;
        }
        else if(data<root->data){
            root->left=deleteData(data,root->left);
            return root;
        }
        
        else {
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            
            else if(root->left==NULL){
                BinaryTreeNode<int>* temp=root->right;
                root->data=root->right->data;
                root->left=root->right->left;
                root->right=root->right->right;
                temp->left=NULL;
                temp->right==NULL;
                delete temp;
                return root;
                
            }
            
            if(root->right==NULL){
                BinaryTreeNode<int>* temp=root->left;
                root->data=root->left->data;
                root->left=root->left->left;
                root->right=root->left->right;
                temp->left=NULL;
                temp->right=NULL;
                delete temp;
                return root;
            }
            
            else {
                int min=minValue(root->right);
                root->data=min;
               // cout<<min<<" ";
                deleteData(min,root->right);
                return root;
            }
        }
    }
    
    void deleteData(int data){
        deleteData(data,root);
    }
    
    bool hasPath(int data,BinaryTreeNode<int>* root){
        if(root==NULL){
            return false;
        }
        
        if(root->data==data){
            return true;
        }
        
        else if(data>root->data){
            return hasPath(data,root->right);
        }
        
        else{
            return hasPath(data,root->left);
        }
    }
    
    bool hasData(int data){
        return hasPath(data,root);
    }
    
    void printTree(BinaryTreeNode<int>* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<":";
        
        if(root->left!=NULL)
        cout<<"L:"<<root->left->data<<",";
        
        if(root->right!=NULL)
        cout<<"R:"<<root->right->data;
        
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }
    
    void printTree(){
        printTree(this->root);
    }
};


int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
    
    return 0;
}
