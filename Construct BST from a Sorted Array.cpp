#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* arrayTree(int *input, int si,int ei){
    
    if(si>ei){
        return NULL;
    }
    int mid=(si+ei)/2;
    
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* left=arrayTree(input,si,mid-1);
    BinaryTreeNode<int>* right=arrayTree(input,mid+1,ei);
    
    root->left=left;
    root->right=right;
    
    return root;
    
}

BinaryTreeNode<int>* constructTree(int *input, int n) {

    return arrayTree(input,0,n-1);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    
    return 0; 
}
