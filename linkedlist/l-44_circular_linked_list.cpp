#include<iostream>
using namespace std;

class node{
 public:
 int data;
 node* next;

 node(int d){
    this->data = d;
    this->next = NULL;
 }
 ~node(){
    int val = this->data;
    if(this->next != NULL){
        delete next;
        this->next = NULL;
    }
    cout<<"MEMORY IS FREE FOR NODE with data "<<val<<endl;
 }
};

void insertnode(node* &tail,int element,int d){
// empty list 
 if(tail == NULL){
  node* temp = new node(d);
  tail = temp;
  temp->next = temp;
}
else{
// non-empty list
// assuming element is present in the list 
  node* curr = tail;
  while(curr->data != element){
   curr = curr->next;
  }
//   element found -> curr is representing element node 
  node* temp = new node(d);
  temp->next = curr->next;
  curr->next = temp;
 }
}

void deletion(node* &tail,int element){
   //empty list 
 if(tail == NULL){
   cout<<"list is empty "<<endl;
 }
 else{
   // non-empty set
   // assuming that value is present in the linked list 
  node* prev = tail;
  node* curr = tail->next;
   while(curr->data !=  element){
     prev = curr;
     curr = curr->next;
   }
   prev->next = curr->next;
   // single node 
   if(prev == curr){
     tail = NULL;
 }
 //  >=2 nodes 
   else if(tail == curr){
      tail = prev;
   }
   curr->next = NULL;
   delete curr;
  }
}
  


void print(node* &tail){
   node* temp = tail;

  if(tail == NULL){
   cout<<"LIST IS EMPTY "<<endl;
   return ;
  }
   do{
     cout<<tail->data<<"  ";
     tail = tail->next;
   }while(tail != temp);
   cout<<endl;
}


int main(){
node* tail = NULL;

insertnode(tail,5,3);
print(tail);

insertnode(tail,3,5);
print(tail);

insertnode(tail,5,7);
print(tail);

insertnode(tail,7,9);
print(tail);

deletion(tail,5);
print(tail);
return 0;
}