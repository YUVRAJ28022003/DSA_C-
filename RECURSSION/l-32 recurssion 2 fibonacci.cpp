#include<iostream>
using namespace std;

//fibonacci series 

//0 1 1 2 3 5 8 13 21 ......


void fibonacciseries(int num,int second, int first){
	cout<<first<<"  ";
	
//	base class
	if(num == 0){
		return;
	}
	num--;
	
//	recurrence relation
    fibonacciseries(num ,first+second ,second);

}


int main(){
 int num;
 int first =0;
 int second = 1;
 cout<<"enter the number: "<<endl;
 cin>>num;
 cout<<"fibonacci series :"<< endl;
 fibonacciseries(num , second,first);
 
 return 0;	
	
}
