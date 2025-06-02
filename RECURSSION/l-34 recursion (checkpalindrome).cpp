#include<iostream>
using namespace std;
// check palindrome

bool checkpalindrome(string& name,int i,int j){
	if(i>j)
	 return true;
	 
	if(name[i]!=name[j])
	 return false;
	else{
		i++;
		j--;
		return checkpalindrome(name,i,j);
	} 
	return true;
}

int main(){
	string name = "abccbba";
	bool ispalindrome= checkpalindrome(name,0,name.length()-1);
	
	if(ispalindrome){
		cout<<"the "<<name<<" is palindrome ";
	}else{
		cout<<"the "<<name<<" is not a  palindrome ";
	}
	
	
	
	return 0;
}
