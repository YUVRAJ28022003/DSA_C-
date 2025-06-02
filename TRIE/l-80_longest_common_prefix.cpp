#include<iostream>
#include<vector>

using namespace std;

class solution{
 
 string longestCommonPrefix(vector<string> &arr, int n)
 {  string ans = "";
    // for traversing all characters of first string 
    for(int i =0;i<arr[0].length();i++){
        char ch = arr[0][i];
        bool match = true;

    //    for comparing ch with rest of the string 
        for(int j =1;j<n;j++){
            // not match 
            if(arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }if(match == false){
            break;
        }else{
            ans.push_back(ch);
        }
        
    }
    return ans;
 }
};

int main(){
  int t;
  cout<<" Input the number of string : ";
  cin>>t;
  
  while(t--){
    int n;
    cin>>n;
    string arr[n];

    for(int i =0;i<n;++i){
        cin>>arr[i];
    }
    solution ob;
    cout<<ob.longestCommonPrefix(arr,n)<<endl;
  }

  return 0;
}