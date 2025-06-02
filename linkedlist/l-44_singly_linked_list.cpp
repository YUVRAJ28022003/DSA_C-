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


// ~node(){
//     int value = this -> data;
// //  MEMORY FREE 
//     if(this->next != NULL){
//       delete next;
//       this->next = NULL;
//     }
//     cout<<"MEMORY IS FREE FOR NODE WITH DATA "<<value<<endl;
// }

void inserthead(node* &head, int d){
    node* temp = new node(d);
    temp -> next= head;
    head = temp;
}


void insertattail(node* &tail,int d){

//  new node create 
    node* temp = new node(d);
    tail ->next = temp;
    tail = temp;

}

void insertatposition(node* &tail,node* &head,int position,int d){
   
// insert at start
   if(position ==1){
    inserthead(head,d);
    return;
   }
   
   node* temp = head ;
   int cnt =1;

   while(cnt < position-1){
     temp = temp->next ;
     cnt++;

   }
// inserting at last position 
   if(temp->next == NULL){
     insertattail(tail,d);
     return;
   }

// creating a node for d 
   node* nodetoinsert = new node(d);
   nodetoinsert->next = temp->next;
   temp->next = nodetoinsert;

}
void deletenode(int position,node* &head){
    int cnt =1;
// deleting first or start node 
    if(position ==1){
     node* temp = head;
     head = head->next;
//  memory free start node 
     temp->next = NULL;
     delete temp ;
    }
    else{
//  deleting any middle and last node 
     node* curr = head;
     node* prev = NULL;

     while(cnt < position){
      prev = curr ;
      curr= curr->next; 
      cnt++; 
     }
     prev -> next = curr -> next; 
     curr->next = NULL;
     delete curr;
    }
}
void print(node* &head){
 node* temp = head;
 while(temp !=NULL){
    cout<< temp -> data <<" ";
    temp = temp -> next;
 }
  cout<<endl;

}

int main(){

// created a node 
 node* node1 = new node(10);
//  cout<< node1 -> data <<endl;
//  cout<< node1 -> next <<endl;


//  head pointing to node
  node* head = node1;
  node* tail = node1;
  print (head);

  inserthead(head,12);
  print (head);

  inserthead(head,14);
  print (head);

  insertattail(tail,15);
  print (head);
  

  insertatposition(tail,head,4,56);
  print (head);

  insertatposition(tail,head,6,58);
  print (head);


cout<<" Head "<<head->data<<endl;
cout<<" Tail "<<tail->data<<endl;

  deletenode(4,head);
  print (head);

  cout<<" Head "<<head->data<<endl;
  cout<<" Tail "<<tail->data<<endl;

 return 0;
}