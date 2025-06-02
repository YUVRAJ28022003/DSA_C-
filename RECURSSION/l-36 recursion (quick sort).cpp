#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
	int pivot = arr[s];
	int count =0;
	
//	finding partition element
	for(int i =s+1;i<=e;i++){
		if(arr[i]<= pivot)
		 count++;
	}
//	placing partition eleemnt in its position
	int pivotindex = s+count;
	swap (arr[pivotindex],arr[s]);
	
//	sorting

	int i =s,j=e;
	while(i<pivotindex&& j>pivotindex){
//			left elements must be less than pivot
		while(arr[i]<=pivot){
			i++;
		}
//			right elements must be greater than pivot
		while(arr[j]>pivot){
			j--;
		}
		if(i<pivotindex&& j>pivotindex)
		 swap(arr[i++],arr[j--]);
	}
	return pivotindex;
}
void Quicksort(int arr[],int s ,int e){
	if(s>=e)
	  return; 
	 
	int p = partition(arr,s,e);
//	recursive call for left eleemnts of partition
	Quicksort(arr,s,p-1);
//	recursive call for right elements of partition
	Quicksort(arr,p+1,e);
}



int main(){
	int arr[12] = {1,2,0,4,5,7,6,22,99,66,44,77};
	int size = 12;
	
	Quicksort(arr,0,size-1);
	
	
	for(int i =0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	
	
	
	return 0;
}



