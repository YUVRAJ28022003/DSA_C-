#include<iostream>
using namespace std;


bool issorted(int arr[] ,int size){
	
//	base case
    if(size==0 || size == 1)
	  return true;	
	if(arr[0] > arr[1])
      return false;	
	else{
	
	  bool remainingpart = issorted(arr+1,size-1);
	  return remainingpart;
    }
}

int main(){
	int arr[6] = {2,4,22,9,9,9};
	int size = 6;
	
	bool ans = issorted(arr, size);
	
	if(ans){
	cout<<"array is sorted  ";
    }else{
    	cout<<"array is not sorted";
	}
	
	return 0;
}
