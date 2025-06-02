#include<iostream>
using namespace std;

int main(){
    cout<<"enter the size of array : ";
    int n ;
    cin>>n;


    int arr[n];
    cout<<"input the array : "<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];

    }
    
    // precompute
    int hash[13] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]] +=1;
    }
    int q;
    cin>>q;

    while(q--){
        cout<<"enter the number : "; 
        int num;
        cin>>num;
        cout<<hash[num]<<endl;
    }

    return 0;
}