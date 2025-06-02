#include<iostream>
using namespace std;

bool binarysearch(int *arr, int s,int e,int k){

//	element not found
	if(e<s)
	  return false;
	int mid= (s+e)/2;	  
	
	cout<<"value of arr mid is  : "<<arr[mid]<<endl;
	if(arr[mid]==k)
	  return true;
	else{
	  if(arr[mid]<k){
	   binarysearch(arr,mid+1,e,k); 
      }else{
       binarysearch(arr,s,mid-1,k);
	}
}
}


int main(){
	int arr[6] = {2,4,5,7,8,9};
	int size = 6;
	int key;
	cout<<"enter the element you want to search :";
	cin>>key;
	
	int s=0,e=size-1;
	int ans = binarysearch(arr,s,e,key);
	
	if(ans)
	  cout<<"element is found ";
	else
	  cout<<"element is not found ";
	  
	
	
	return 0;
}
