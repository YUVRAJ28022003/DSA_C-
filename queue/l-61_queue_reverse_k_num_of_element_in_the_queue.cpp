#include<iostream>
#include<queue>

using namespace std;

    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        
        // 1  fetch from queue and put it into stack
        for (int i =0;i<k;i++){
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        
        
        // 2  fetch from stack and put it into queue
        while(!s.empty()){
            int val =s.top();
            s.pop();
            q.push(val);
            
        }
        
        // 3 fetch first n-k element from queue and push back to queue
        
        int t = q.size() -k;
        while(t--){
            int val =  q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }


int main(){


  return 0;
}