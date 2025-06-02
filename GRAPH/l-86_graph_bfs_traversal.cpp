#include"bits/stdc++.h"
#include<queue>
using namespace std;

 const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

int main(){
    // 1 mark every node as unvisited
    for(int i =0;i<N;i++){
        vis[i] = 0;
    }
    // 2. enter no of vertex and edges 
    int n ,m;
    cout<<"ENTER NUMBER OF VERTEX : ";
    cin>>n;
    cout<<"ENTER NUMBER OF EDGES : ";
    cin>>m;

    int x,y;
    // 3.enter the directed nodes to each other
    for(int i =0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
      
    queue<int>q;
    //4.push first node into the queue
    q.push(1);
//    5. mark first node as traversed
    vis[1] = true;
    
    while(!q.empty()){
        int node = q.front();

        q.pop();
        cout<<node<<endl;

        vector<int>:: iterator it;
        for(it = adj[node].begin();it != adj[node].end();it++){
            if(!vis[*it]){
                vis[*it] = 1;
                q.push(*it);
            }

        }
    }

    return 0;
}

// input
// 7 7 
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3

// output
// 1
// 2
// 3
// 4
// 5
// 6
// 7