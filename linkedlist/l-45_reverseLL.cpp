#include<iostream>
using namespace std;

class node{
    public :
    int data ;
    node* next;

    node(int data){
        this-> data = data;
         this-> next = NULL;
    }
};

 void recursivereversed(node* &head,node* curr,node* prev){
    // base
    if(curr == NULL){
          head = prev;
          return;
    }
    node* forw = curr->next;
    recursivereversed(head,forw,curr);
    curr->next = prev;
}
void reverseLL(node* &head){
   node* curr = head;
   node* prev = NULL;
   recursivereversed(head,curr,prev);
   return head;
}

int main(){
    
 return 0;
}