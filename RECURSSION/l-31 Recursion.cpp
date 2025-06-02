#include<iostream>
using namespace std;


int factorial(int n ) {
	
//	base function
  if(n==0){
  	return 1;
  }
  
  
//  recurssive relation
  return n*factorial(n-1); 	
	 

}	
int main(){
	
	int n ;
	cin>>n;
	int ans = factorial (n);
	cout<<ans<<endl;
	
	return 0;
}
