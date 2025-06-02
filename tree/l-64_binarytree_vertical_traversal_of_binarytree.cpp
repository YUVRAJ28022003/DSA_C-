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

vector<int> verticalOrder(node* &root)
    {
        map<int, map<int,vector<int> > >nodes;
        queue<pair<node* ,pair<int,int> > > q;
        vector<int> ans ;
        
        if(root == NULL)
            return ans;
        
        q.push(make_pair(root , make_pair(0,0)));
        
        while(!q.empty()){
            pair<node* ,pair<int,int> > temp = q.front();
            q.pop();
            node* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontnode->data);
            if(frontnode->left)
              q.push(make_pair(frontnode-> left,make_pair(hd-1, lvl+1) ) );
            if(frontnode->right)
              q.push(make_pair(frontnode->right,make_pair(hd+1, lvl+1) ) );
        }
        for(auto i: nodes){
            for(auto j:i.second){
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }

    int main(){
    node* root = NULL;

    buildfromlevelorder(root);
    levelordertraversing(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    
    vector<int> res = verticalOrder(root);
    for(int i: res){
        cout<<i<<"  ";
    }

    return 0;
}