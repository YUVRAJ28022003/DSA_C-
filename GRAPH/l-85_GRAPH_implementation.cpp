#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>

class graph{
    public:

    unordered_map<T, list<T> > adj;

    void addedge(T u ,T v, bool dir ){
        // direction = 0 -> undirected
        // direction = 1 ->directed graph

        // create an edge from u to v 
        adj[u].push_back(v);
        if(dir == 0){//undirected graph
            adj[v].push_back(u);
        }
    }

    void printadjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }


};

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
           vector<int> ans[n];

        //    ans array with store all adjacent nodes corresponding on index
           for(int i =0;i<m;i++){
            //    storing the values from edge indexes to ans array 
               int u = edges[i][0];
               int v = edges[i][1];

               ans[u].push_back(v);
               ans[v].push_back(u);
           }

vector<vector<int> > adj(n);
    for(int i =0;i<n;i++){
        adj[i].push_back(i);

        //    entering neighbour
        for(int j =0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
        }
        return adj;
    }




int main(){
  int n;
  cout<<"enter the number of nodes" <<endl;
  cin>>n;

  int m;
  cout<<"enter the number of edges" <<endl;
  cin>>m;
  
  graph<int> g;
  for(int i =0;i<m;i++){
    int u ,v;
    cin>>u>>v;
    // creating an undirected graph 
    g.addedge(u,v,0);
  }

//   printing graph 
  g.printadjlist();
  return 0;
}

// // input : 
// enter the number of nodes
// 5
// enter the number of edges
// 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4

// // output
// 4->3, 0,
// 0->1, 4,
// 1->0, 2, 3,
// 2->1, 3,
// 3->2, 1, 4,