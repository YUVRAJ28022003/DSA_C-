#include<iostream>
using namespace std;


int partition(int arr[],int s,int e){
    int pivot = arr[s];
    int cnt =0;
    // find the right position of pivot 
    for(int i =s+1;i<=e;i++){
       if(arr[i]<= pivot)
          cnt++;  
    }
    // place pivot at right position
    int pivotindex = s + cnt;
    swap(arr[pivotindex],arr[s]);

    // left and right part wala sambhal lete hai 
    int i = s , j = e;

    while(i < pivotindex && j > pivotindex){
        // compare left from pivot if greater then i++ 
        while(arr[i] <= pivot){
            i++;
        }
        // compare right from pivot if greater then j-- 
        while(arr[j] > pivot){
            j--;
        }
        // swap if any left is greater and any right is smaller
        if(i < pivotindex && j > pivotindex ){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void quicksort(int arr[],int s,int e){

    // base case
    if(s>=e)
      return;


    // partition karenge
    int p = partition(arr,s,e);

    // left part sort karo
    quicksort(arr,s,p-1);

    // right part sort karo 
    quicksort(arr,p+1,e);
}


int main(){
    int arr[5] = {2,4,1,6,9};
    int n =5;

    quicksort(arr,0,n-1);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";

    }cout<<endl;

    return 0;
}