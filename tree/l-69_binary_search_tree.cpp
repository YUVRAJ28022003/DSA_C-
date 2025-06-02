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

void levelordertraversing(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){// old level completely traversed
            cout<<endl;
            if(!q.empty()){ // queue still have some child nodes
                q.push(NULL);
            }
        }else{
            cout<<temp->data <<" ";
            if(temp ->left){
              q.push(temp->left);
            }
            if(temp ->right){
              q.push(temp->right);
           }
        }
    }
}

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

// RECURSIVE METHOD 
//   bool search(node* root, int x){
//     // base case
//     if(root == NULL)
//       return false;
      
//     if(root->data == x)
//       return true;
      
//     if(root->data > x)
//      return search(root->left, x);
//     else
//      return search(root->right,x);
//   }

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

  int main(){
    node* root = NULL;


    cout<<"enter data to create BST :  "<<endl;
    takeinput(root);
    // 1 3 5 7 11 17 -1 

    cout<<"hii "<<endl;

    // cout<<"printing the BST :"<<endl;
    // levelordertraversing(root);


    cout<<search(root,8)<<endl;
    // if(y == true){
    //     cout<<" DATA is present in the TREE ."<<endl;
    // }else{
    //     cout<<"Data is absent in the TREE "<<endl;
    // }
    return 0;
  }