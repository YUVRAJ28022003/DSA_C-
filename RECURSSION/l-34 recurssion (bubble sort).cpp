#include<iostream>
using namespace std;
void
void bubblesort(int *arr,int n){
	
	if(n==0 || n==1){
		return ;
	}  
	
	for(int i =0;i<n-1;i++){
		if(arr[i]>arr[i+1])
		 swap(arr[i],arr[i+1]);
	}
	bubblesort(arr,n-1);
}
int main(){
	
	int arr[6]= {1,5,2,4,7,9};
	int n = 6;
	bubblesort(arr,n-1);
	cout<<"The sorted array is  : "<<endl;
		for(int i =0;i<n-1;i++){
		 cout<<arr[i]<<" ";
	    }
	return 0;
	
}
