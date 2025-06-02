#include<iostream>
#include<queue>
using namespace std;



vector<int> rearrangeQueue(queue<int> &q){
    queue<int> nq;
    vector<int>ans;
    int n =q.size()/2;
    for(int i =0;i<n;i++){
            int val = q.front();
            q.pop();
            nq.push(val);
            
        }
        while(!nq.empty()){
            int val = nq.front();
            nq.pop();
            ans.push_back(val);
            val = q.front();
            q.pop();
            ans.push_back(val);        
    }
    return ans;
}

int main(){
  
    



  return 0;
}