#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int d){
        this ->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<" MEMORY FREE FOR NODE WITH DATA "<<val<<endl;
    }
};

void insertathead(node* &tail,node* &head, int d){
 if(head== NULL){
   node* temp = new node(d);
   tail = temp;
   head = temp;
  }
 node*temp = new node(d);
 head -> prev = temp;
 temp -> next = head;
 head = temp;
}
 
void insertattail(node* &tail,node* &head, int d){
  if(tail== NULL){
   node* temp = new node(d);
   tail = temp;
   head = temp;
  }
  else{
   node* temp = new node(d);
   tail ->next = temp;
   temp ->prev = tail;
   tail = temp;
  }
}

void insertatposition(node* &tail,node* &head,int position, int d ){
    
    // insert at start 
    if(position ==1){
        insertathead(tail,head,d);
        return;
    }

    int cnt = 1;
    node* temp = head;
    while(cnt <=position-1){
       temp = temp->next;
       cnt++;
    }
    // insert at end
    if(temp->next == NULL){
       insertattail(tail,head,d);
       return;
    }

    // insert at position 
    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
    }
void print(node* head){
    node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<"   ";
        temp = temp ->next;

    }
    cout<<endl;
}
void deletion(node* &tail,node* &head,int position){
    // deleting from first node 
    if(position == 1){
        node* temp = head;
        temp ->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
    // delete any middle node or last node 
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }

}

int getlength(node* head){
    int len = 0;
    node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp ->next;

    }
    cout<<endl;
    return len;
}

int main(){
 node* node1 = new node(10);
 node* head = node1;
 node* tail = node1;

 print(head);
 cout<<getlength(head)<<endl;
 cout<<"head -> "<<head->data<<endl;
 cout<<"tail -> "<<tail->data<<endl;

 insertathead(tail,head,11);
 print(head);
 cout<<"head -> "<<head->data<<endl;
 cout<<"tail -> "<<tail->data<<endl;

 insertattail(tail,head,25);
 print(head);
 cout<<"head -> "<<head->data<<endl;
 cout<<"tail -> "<<tail->data<<endl;

 insertatposition(tail,head,1,100);
 print(head);
 cout<<"head -> "<<head->data<<endl;
 cout<<"tail -> "<<tail->data<<endl;

 insertatposition(tail,head,4,101);
 print(head);

 cout<<"head -> "<<head->data<<endl;
 cout<<"tail -> "<<tail->data<<endl;

 insertatposition(tail,head,2,105);
 print(head);

 cout<<"head -> "<<head->data<<endl;
 cout<<"tail -> "<<tail->data<<endl;

 deletion(tail,head,1);
 print(head);
 deletion(tail,head,5);
 print(head);
 cout<<"head -> "<<head->data<<endl;
 cout<<"tail -> "<<tail->data<<endl;
return 0;
}