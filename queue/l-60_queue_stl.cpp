#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    // insertion
    q.push(1);
    q.push(12);
    q.push(21);
    q.push(41);
    
    
    cout<<"size of the queue : "<<q.size()<<endl;
    

    q.pop();
    cout<<"front element of the queue : "<<q.front()<<endl;
    q.pop();
    q.pop();

    
    if(q.empty()){
        cout<<"queue is empty";

    }else{
        cout<<"quue is not empty";
    }
    
    return 0;
}