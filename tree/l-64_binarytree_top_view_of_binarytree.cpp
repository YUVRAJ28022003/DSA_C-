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
vector<int> topView(node* &root){
        vector<int> ans;
        if(root == NULL)
           return ans;
           
        map<int,int>topnode;
        queue<pair<node*,int> > q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<node*,int>temp = q.front();
            q.pop();
            node* frontnode = temp.first;
            int hd =temp.second;
            
            // if one value is present for a hd ,then do
            if(topnode.find(hd)== topnode.end())
               topnode[hd] = frontnode -> data;
               
            if(frontnode->left)
               q.push(make_pair(frontnode->left,hd-1));
            if(frontnode->right)
               q.push(make_pair(frontnode->right,hd+1));   
        }
        for(auto i :topnode){
            ans.push_back(i.second);
        }
        return ans;
}



    int main(){
    node* root = NULL;

    buildfromlevelorder(root);
    levelordertraversing(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    
    vector<int> res = topView(root);
    for(int i: res){
        cout<<i<<"  ";
    }

    return 0;
}