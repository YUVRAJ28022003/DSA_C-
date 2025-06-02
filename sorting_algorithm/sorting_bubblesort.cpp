#include<bits/stdc++.h>
using namespace std;

    void bubbleSort(int arr[], int n)
    {
        
        for(int i =1;i<n;i++){
            bool swapped = false;
            for(int j =0;j<n-1;j++){
                if(arr[j] > arr[j+1]){
                   swap(arr[j],arr[j+1]); 
                   swapped = true;
                }
            }
            if(swapped == false)
                break;
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
    
    bubbleSort(arr, n);
    
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}