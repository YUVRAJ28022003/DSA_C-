




#include<bits/stdc++.h>
using namespace std;

// // approach 1 
// // merge sort using indexes
//     void merge(int arr[], int start, int mid, int end)
// {
//     int start2 = mid + 1;
 
//     // If the direct merge is already sorted
//     if (arr[mid] <= arr[start2]) {
//         return;
//     }
 
//     while (start <= mid && start2 <= end) {
 
//         // If element 1 is in right place
//         if (arr[start] <= arr[start2]) {
//             start++;
//         }
//         else {
//             int value = arr[start2];// pit the vaule in the container
//             int index = start2; // save the index of the element
            
//             // right shift the indexes until it reach to its start location
//             while (index != start) {
//                 arr[index] = arr[index - 1];
//                 index--;
//             }
//             arr[start] = value;
 
//             // Update all the pointers
//             start++;
//             mid++;
//             start2++;
//         }
//     }
// }
// approach 2
// merge sort by recursion in which creating new array and copy values
 

 void merge(int *arr, int l, int m, int r)
    {
        // size of 1st half array 
         int len1 = m-l+1;
         // size of 2nd half array 
         int len2 = r-m;
         
        //  creating 2 array 
         int *first = new int[len1];
         int *second = new int[len2];
         
         
        //  copy values in 1st
        int mainarrayindex =l;
        for(int i =0;i<len1;i++){
           first[i] = arr[mainarrayindex++];
        }
        
        //  copy values in 2nd
        mainarrayindex =m+1;
        for(int i =0;i<len2;i++){
            second[i] = arr[mainarrayindex++];
        }
        
        
        // merge 2 sorted arrays
        int index1 = 0;
        int index2 = 0;
        mainarrayindex =l;
        
        // sort 
        while(index1 < len1 &&  index2 < len2){// run the loop until first and second array untill traversed
            if(first[index1] <second[index2]){
              arr[mainarrayindex++] = first[index1++];
            }else{
              arr[mainarrayindex++] = second[index2++];
            }
        }
        
        // rest values after sorting 
        while(index1 < len1){
          arr[mainarrayindex++] = first[index1++];
        }while(index2 < len2){
          arr[mainarrayindex++] = second[index2++];
        }
        
        // free the waste allocation 
        delete[]first;
        delete[]second;  
        }
    

    void mergeSort(int *arr, int l, int r)
    {
        if(l>=r)
          return;
          
        int mid = (l+r)/2;
    
        // left part sort krna hai
        mergeSort(arr,l,mid);
          
        // right part sort krna hai
        mergeSort(arr,mid+1,r);

        int m = (l+r)/2;
        // merge
        merge(arr,l,m,r);
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
    
    mergeSort(arr,0, n);
    
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}