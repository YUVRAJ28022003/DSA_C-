
#include<bits/stdc++.h>
using namespace std;

    void insertionSort(int arr[], int n)
    {
       for(int i =0;i<n;i++){
           int temp = arr[i];
           int j=i-1;
           for(;j>=0;j--){
               if(arr[j] > temp)
                 arr[j+1] = arr[j];
                else
                  break;
           }
           arr[j+1]= temp;
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
    
    insertionSort(arr, n);
    
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}