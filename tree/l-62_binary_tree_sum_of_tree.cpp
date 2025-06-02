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


pair<bool,int> issum (node*root){
        
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftans = issum(root->left);
        pair<bool,int> rightans = issum(root->right);
        
        bool isleftsumtree = leftans.first;
        bool isrightsumtree = rightans.first;
        
        int leftsum = leftans.second ;
        int rightsum = rightans.second  ;
        
        bool condn =root->data ==  leftsum+rightsum;
        pair<bool,int> ans;
        
        if(isleftsumtree && isrightsumtree && condn){
            ans.first = true;
            ans.second = 2*root->data ;
        }else{
            ans.first = false;
        }  
        
        return ans;
        
        
}
bool isSumTree(node*root)
{
    return issum(root).first;
}


int main(){
    node* root = NULL;

    buildfromlevelorder(root);
    // 1 3 5 -1 -1 -1 -1 
    
    bool value = isSumTree(root);
    if(value == true){
        cout<<"tree is balanced"<<endl;
    }if(value == false){
        cout<<"Tree is unbalanced"<<endl;
    }

    return 0;
}