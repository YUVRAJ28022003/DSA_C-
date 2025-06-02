#include<iostream>
#include<vector>
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
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
           }
        }
    }
}

node* buildfromlevelorder(node* &root){
    queue<node*> q;
    cout<<"enter a data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter left node for : "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout<<"enter right node for : "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right= new node(rightdata);
            q.push(temp->right);
        }
    }

}

    void traverseleft(node* &root,vector<int> &ans){
        if( (root == NULL) || (root->left == NULL && root->right == NULL) ){
           return ;
        }
        
        ans.push_back(root->data);
        if(root->left)
           traverseleft(root->left,ans);
        else
           traverseleft(root->right,ans);
    }
    void traverseleaf(node* &root,vector<int> &ans){
        if(root == NULL){
           return ;
        }
        
        if(root->left == NULL && root->right == NULL){
          ans.push_back(root->data);
          return ;
        }
           traverseleaf(root->left,ans);
           traverseleaf(root->right,ans);
    }
    
    void traverseright(node* &root,vector<int> &ans){
        if( (root == NULL) || (root->left == NULL && root->right == NULL) ){
           return ;
        }
        
        
        if(root->right)
           traverseright(root->right,ans);
        else
           traverseright(root->left,ans);
           
        ans.push_back(root->data);
    }
    vector <int> boundary(node *root)
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        // left part print /store
        traverseleft(root->left,ans);
        
        // print leaf nodes
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
        
        
        // print right nodes
        traverseright(root->right,ans);
        
        return ans;
        
    }


    int main(){
    node* root = NULL;

    buildfromlevelorder(root);
    levelordertraversing(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    
    vector<int> res = boundary(root);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<"  ";
    }
    return 0;
}