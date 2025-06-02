#include<iostream>
using namespace std;

void merge(int *arr,int s,int e){
	int mid =(s+e)/2;
	
//	length two sorted arrays
	int len1 = mid-s+1;
	int len2 = e-mid;
	
//	2 arrays
	int *first = new int[len1];
	int*second = new int[len2];
	
//	copy values
	int mainarrayindex =s;
	for(int i =0;i<len1;i++){
		first[i] = arr[mainarrayindex++];	
	}
	
	
	mainarrayindex =mid+1;
	for(int i =0;i<len2;i++){
		second[i] = arr[mainarrayindex++];
	}
	
//	merge 2 sorted arrays

    int index1 =0;
    int index2 =0;
    
    mainarrayindex = s;
    
    while(index1 <len1 && index2 < len2){
    	if(first[index1]< second[index2]){
    		arr[mainarrayindex++] = first[index1++];
		}else{
			arr[mainarrayindex++] = second[index2++];
		}
		
	}while(index1 <len1){
		arr[mainarrayindex++] = first[index1++];
	}
	while(index2 <len2){
		arr[mainarrayindex++] = second[index2++];
	}
    
    delete []first;
    delete []second;
}

void mergesort(int *arr,int s,int e){
	
	if(s>=e)
	 return;
//	 cout<<"hi";
	int mid=(s+e)/2;
	
	
//	left part sort krne ke liye
	mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);
    
//    merge
    merge(arr,s,e);

}

int main(){
	int arr[11]= {1,4,2,8,5,6,22,90,54,87,23};
	int n =11;
	
	mergesort(arr,0,n-1);
	
	for(int i =0;i<n-1;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
