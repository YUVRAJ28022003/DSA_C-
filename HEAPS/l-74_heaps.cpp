#include<iostream>
#include<algorithm>

using namespace std;

class heap {
    public:
    int arr[100];
    int size =0;

 void insert(int val){
       size = size+1;
       int index = size;
       arr[index] = val;

       while(index >1){
        int parent = index/2;

        if(arr[parent] < arr[index]){
            swap(arr[parent], arr[index]);
            index = parent;           
        }else{
            return ;
        }
       }
 }


void deletefromheap(){
        if(size == 0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        // 1. put last element into first index 
        arr[1] == arr[size];

        // 2. remove last eleemnt 
        size--;

        // take root node to its correct position
        int i =1;
        while(i<size){
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if(leftindex <size && arr[i] < arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i = leftindex;
            }    
            else if(rightindex < size && arr[i] < arr[rightindex] ){
                swap(arr[i],arr[rightindex]);
                i = rightindex;
            } else{
                return ;
            }
            
    }
 }



    void print(){

        for(int i =1;i<=size;i++){
            cout<<arr[i]<<" ";

        }cout<<endl;
    }
};

 void maxheapify(int arr[],int n,int i){
    int largest =i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left])
      largest = left;

    if(right <= n && arr[largest] <arr[right])
      largest = right;

    if(largest != i){
        swap(arr[largest],arr[i]);
        maxheapify(arr ,n,largest);
    }
 }

void minheapify(int arr[],int n,int i){
    int smallest =i;
    int left = 2*i;
    int right = 2*i+1;
    if(left < n && arr[smallest] > arr[left])
      smallest = left;
    if(right < n && arr[smallest] >arr[right])
      smallest = right;
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        minheapify(arr ,n,smallest);
    }
}

void heapsort(int arr[],int n,int i){
    int size = n;
    while(size>1){
        
        swap(arr[size],arr[i]);
        size--;

        maxheapify(arr,size,1);
    }
}
int main(){
    heap h;
    h.insert(50);
    h.insert(52);
    h.insert(57);
    h.insert(51);
    h.insert(54);

    h.print();
    h.deletefromheap();

    h.print();
    int arr[6] ={-1,54,53,55,52,50};
    int n =5;
    // heap creation

    // 0 page indexing 
    //  (i = n/2 - 1, i>=0 ) left = 2*i  , right = 2*i+1
    // 1 page indexing 
    //  (i = n/2 , i>0 )    left = 2*i+1 , right = 2*i+2
    for(int i = (n/2);i>0;i--){
        maxheapify(arr,n,i);
    }

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for(int i = n/2;i>0;i--){
        minheapify(arr,n,i);
    }
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}