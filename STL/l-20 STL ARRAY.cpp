#include<iostream>
#include<array>
using namespace std;
int main(){
	int arr[3] = {1,2,3};
	 
	array<int,4>a = {1,2,3,4} ;
	int size = a.size();
	for(int i =0;i<size;i++){
		cout<<a[i]<<endl;
	}
	cout<<"element at 2nd index"<<a.at[2]<<endl;
	cout<<" element is empty or not"<<a.at[2]<<endl;
	return 0;
}
