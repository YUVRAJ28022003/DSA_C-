#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cout<<"enter the size of the array : ";
    cin>>n;

    int arr[n];
    cout<<"enter the element of array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    // precompute 
    unordered_map<int,int> mpp;
    for(int i =0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        cout<<it.first<<"-> "<<it.second<<endl;
    }

    int q;
    cout<<"enter how much we will check :";
    cin>>q;

    while(q--){
        int num;
        cin>>num;

        cout<<mpp[num]<<endl;
    }


    return 0;
}