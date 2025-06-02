#include<iostream>
using namespace std;

int main(){
    string s;
    cout<<"enter the string : ";
    cin>>s;

    
    // precompute
    int hash[256] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    int q;
    cout<<"enter the number character you will check : ";
    cin>>q;

    while(q--){
        cout<<"enter the character : "; 
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }

    return 0;
}