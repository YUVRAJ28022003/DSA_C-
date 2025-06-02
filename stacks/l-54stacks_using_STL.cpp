#include<iostream>
#include<stack>

using namespace std;

int main(){
    // creation of stack 
    stack<int> s;

    // insertion
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(6);

    cout<<"printing top element "<<s.top()<<endl;
    
    // deletion
    s.pop();

   if(s.empty()){
    cout<<"stack is empty"<<endl;
   }else{
    cout<<"stack is not empty"<<endl;
   }
    cout<<"size of the stack "<<s.size()<<endl;
   return 0;
}