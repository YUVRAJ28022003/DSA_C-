#include<iostream>
using namespace std;

void reachhome(int src ,int dest){
	
	
	cout<<"source : "<<src<<"destintion :"<<dest<<endl;
	if(src ==dest){
		cout<<"pahuch gye"<<endl;
		
		return ;
	}
//	processing :-  ek step aage badh jao
//	recurssive call
   reachhome(src+1,dest);
}




int main(){
	int dest =10;
	
	int src =1;
	
	
	cout<<"process started ;"<<endl;
	reachhome(src,dest);
	return 0;
	
}
