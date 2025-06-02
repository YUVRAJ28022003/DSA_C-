#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }   
};



node* insertintobst(node* root,int d){
        // base case
        if(root == NULL){
            root = new node(d);
            return root;
        }
        if(d > root->data){
            // right part mien insert krna hai
            root->right = insertintobst(root->right, d);
        }else{
            // left part mien insert krna hai 
            root->left = insertintobst(root->left, d);
        }
        return root;
    }



void takeinput(node* &root){

        int data;
        cin>>data;

        while(data != -1 ){
            insertintobst(root,data);
            cin >> data;
        }
    }


//  ITERATIVE METHOD
bool search(node* root, int x){
    node* temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return true;
            cout<<"data is present";
        }
        if(temp->data > x){
            temp = temp->left;
        }else{
            temp = temp ->right;
        }
    }
    return false;
}

int minValue(node* root)
{
    node *current = root;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }
    return (current->data);
}

// Function to delete a node from BST.
node *deleteNode(node* root, int X) {
    // your code goes here
    
    if(root == NULL)
      return root;
    if(root->data == X){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        // 1 child
        // left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        
        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue( root-> right );
            root->data = mini;
            root->right = deleteNode(root->right,mini);
            return root;
        }
        
        
    }else if(root->data  > X){
        root->left = deleteNode(root->left, X);
        return root;
    }else{
        root->right = deleteNode(root->right, X); 
        return root;
    }
}


  int main(){
    node* root = NULL;


    cout<<"enter data to create BST :  "<<endl;
    takeinput(root);
    // 1 3 5 7 11 17 -1 

    cout<<"hii "<<endl;


    return 0;
  }

