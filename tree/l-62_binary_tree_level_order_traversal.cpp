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

int main(){
    node* root = NULL;
    buildfromlevelorder(root);
    levelordertraversing(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1


    return 0;
}