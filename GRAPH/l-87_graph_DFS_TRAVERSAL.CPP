#include"bits/stdc++.h"
#include<queue>
using namespace std;

 const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];


vector<int>dfs(int node , vector<int>visited , vector<int>result , vector<int>adj[]){
    visited[node] = 1;

    result.push_back(node);

    for(int neighbour :adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,visited,result,adj);       
         }
    }
}


vector<int>dfsgraph(int V,vector<int>adj[]){
    vector<int> result;
    vector<int> visited(V,0);

    dfs(0,visited,result,adj);
    return result;

}

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

    vector<int> result;
    vector<int> visited(V,0);

    dfs(0,visited,result,adj);
    
    return 0;
}