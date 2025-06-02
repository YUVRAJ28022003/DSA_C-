//heap

#include<iostream>
#include<queue>
using namespace std;

int main(){
	
//	max heap
   priority_queue<int> maxi;
   
//   min heap
    priority_queue<int,vector<int>,greater<int>> mini;
    
    
    
    maxi.push(1);
    maxi.push(2);
	maxi.push(3);
	maxi.push(4);    
	cout<<"size of max heap :"<<maxi.size()<<endl;
    for(int i =0;i<maxi.size();i++){
    	cout<<maxi.top()<<" ";
//    	maxi.pop();
	}
     
    return 0;

}
