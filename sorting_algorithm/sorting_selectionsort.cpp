#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
   for(int i =0;i<n-1;i++){
      int minindex =i;
      for(int j =i+1;j<n;j++){
         if(arr[minindex]>arr[j]){
            minindex =j;
         }
      }
      swap(arr[minindex],arr[i]);
      }
}


int main(){
    int n;
    cout<<"enter the size of the array : ";
    cin>>n;
    

    int arr[n];
    cout<<"enter the element of the array : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    selectionSort(arr, n);
    
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}