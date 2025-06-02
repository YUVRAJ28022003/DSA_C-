#include<iostream>
#include<vector>
using namespace std;


 void solve(int* a,string output,int index,vector<string>& ans, string mapping[],int n){
    // base case
    if(index>=n){
        ans.push_back(output);
        return ;
    }
    int num = a[index];
    string value = mapping[num];
    for(int i =0;i<value.length();i++){
        output.push_back(value[i]);
        solve(a,output,index+1,ans,mapping,n);
        output.pop_back();
    }

}
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
      vector<string> ans;
     if(N==0){
        return ans;
     }
    	string output ="";
	    int index = 0;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(a,output,index,ans,mapping,N );
    return ans;
    }
    
    
    int main(){
    	int arr[3] = {1,2,3};
    	int n =3;
    	vector<string>ans = possibleWords(arr,n);
    	
    	for(int i =0;i<ans.length();i++){
    		cout<<ans[i]<<" ";
		}
    	
    	return 0;
	}
