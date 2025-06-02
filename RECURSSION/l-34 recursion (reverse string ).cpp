#include<iostream>
using namespace std;

void reverse(string& name,int i,int j){
	cout<<"call rceived for "<<name<<endl;
  //	base case
 if(i>j)
   return ;
 
 swap(name[i],name[j]);
 i++;
 j--;
 reverse(name,i,j);
 
}

int main(){
	string name = "abcde";
	
	cout<<"th string is :"<<name<<endl;
	
	reverse(name,0,name.length()-1);
	
	cout<<"th string is :"<<name<<endl;
	
	
	
	return 0;
}
