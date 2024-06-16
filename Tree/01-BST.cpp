//Binary search tree implementation - 
#include <iostream>

using namespace std;

//defination of node in BST
struct BstNode{
 int data;
 BstNode *left;
 BstNode *right;
};

//Function to create a new node in heap
BstNode *GetNewNode(int data){
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//To insert data in BST, returns address of root node
BstNode *Insert( BstNode *root, int data){
    if( root == NULL){
        root = GetNewNode(data);
    }
    //if data to be inserted is lesser, insert in left sub tree
    else if( data <= root->data){
        root->left = Insert( root->left, data);
    }
    //else, insert in right subtree
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}
//To search element in BST returns true if element is found
bool search ( BstNode* root, int data){
    if( root == NULL ){
        return false;
    }
    else if( root->data == data){
        return true;
    }
    else if( data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

int main(){
  BstNode *root = NULL; // creating an empty tree
  root = Insert(root, 15);
  root = Insert(root, 10);
  root = Insert(root, 20);
  root = Insert(root, 25);
  root = Insert(root, 8);
  root = Insert(root, 12);
  
  int number;
  cout << "Enter a number to be searched : " << endl;
  cin >> number;
  if( search(root, number) == true) cout << "Found" << endl;
  else cout << "Not Found" << endl;
  return 0;
}