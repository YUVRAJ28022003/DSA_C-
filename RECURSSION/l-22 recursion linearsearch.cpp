 #include<iostream>
using namespace std;


void print(int *arr,int size){
	cout<<"size of the array : "<<size<<endl;
	for(int i =0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
}

bool linearsearch(int *arr,int size, int key){
	
	print(arr,size);

//	base function
	if(size == 0)
	  return false;
	if(arr[0] == key)
   	  return true;

//	recrusive cycle
	int remainingpart = linearsearch(arr+1,size-1,key);
	return remainingpart;
	
}

int main(){
	
	int arr[5] = {3,5,1,2,6};
	int size = 5;
	int key ;
	cout<<"Enter the key :";
	cin>>key;
	bool ans = linearsearch(arr, size,key);
	
	if(ans)
	   cout<<"Key is found";
	else
	   cout<<"Key is not found";
	return 0;
	
}
