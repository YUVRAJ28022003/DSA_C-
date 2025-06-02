#include<iostream>
#include<vector>
#include<queue>
#include<map>

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
void createmapping(int in[],map<int,int> &nodetoindex, int n){
        for(int i=0;i<n;i++){
           nodetoindex[in[i]] =i;
        }
}
    
    
Node* solve(int in[],int pre[], int &index,int inorderstart,int inorderend,int n,map<int,int> &nodetoindex){
        
        // base case
        if((index >= n) || (inorderstart > inorderend)){
           return NULL;
        }
           
        // create a root node
        int element = pre[index++];
        Node* root = new Node(element);
        
        // find element's index in inorder
        int position = nodetoindex[element];
       
        
        // recursive call
        root->left = solve(in,pre,index,inorderstart,position-1,n,nodetoindex);
        root->right = solve(in,pre,index,position-1,inorderend,n,nodetoindex);
        
        return root;
}
Node* buildTree(int in[],int pre[], int n)
{
        int preorderindex = 0;
        map<int,int> nodetoindex;
        // create node to index map
        createmapping(in,nodetoindex,n);
        
        Node* ans = solve(in,pre,preorderindex,0,n-1,n,nodetoindex);
        return ans;
}


    int main(){
    node* root = NULL;

    // buildfromlevelorder(root);
    // levelordertraversing(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    n = 4;
    int in[n] = {1 6 8 7};
    int pre[n] = {1 6 7 8};
    
    int ans = buildTree(in,pre,n);
    levelordertraversing(ans);

    return 0;
}