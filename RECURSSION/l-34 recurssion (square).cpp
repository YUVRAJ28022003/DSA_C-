#include<iostream>
using namespace std;

int power(int a,int b){
	int sum =0;
//	base case
	if(b==0)
	 return 1;
	if(b==1)
	 return a;
	
//	recursive call
	sum =power(a,b/2); 
	 
    if(b%2==0){
    	return sum*sum;
	}else{
		return a*sum*sum;
	}
}
int main (){
	
	int a ,b;
	cin>>a>>b;
    int sum =power(a,b);
    cout<<sum<<endl;
    return 0;
}

