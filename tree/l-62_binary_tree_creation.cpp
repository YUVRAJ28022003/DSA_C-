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
        this->left= NULL;
        this->right= NULL;
    }
};

node* buildtree(node* root){
    
    cout<<"enter the data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data ==-1){
        return NULL;
    }
    cout<<"enter data for inserting in left : "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"enter data for inserting in right : "<<data<<endl;
    root->right = buildtree(root->right); 
    return root;   
}

void levelordertraversing(node*root){
    queue<node* >q;
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
            if(temp->right){
            q.push(temp->right);
           }
        }
        

    }
}

// INORDER traversing 
void inorder(node* root){
    // base class
    if(root == NULL){
        return ;
    } 

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

// PREORDER TRAVERSING
void preorder(node* root){
    // base class
    if(root == NULL){
        return ;
    } 
    cout<< root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

// POSTORDER TRAVERSING
void postorder(node* root){
    // base class
    if(root == NULL){
        return ;
    } 
    
    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<" ";
}
//  height of binary tree 
    int height(node* root){
        // code here 
        if(node == NULL){
           return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left,right)+1;
        return ans ;
        
        
    }



int main(){
    node* root = NULL;

    // creating a tree
    root = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     
    // levelorder 
    cout<<"Printing the level order traversal output " <<endl;
    levelordertraversing(root);


    cout<<"inorder travesal is : ";
    inorder(root);
    cout<<endl;
    cout<<"preorder travesal is : ";
    preorder(root);
    cout<<endl;
    cout<<"postorder travesal is : ";
    postorder(root);
    cout<<endl;
    return 0;
}