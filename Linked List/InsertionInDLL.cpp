#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*back;
    
    Node(int data1,Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
        
    }
};
Node* convertArrToDll(vector<int> arr){
    Node* head= new Node(arr[0],NULL,NULL);
    Node* prev= head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],NULL,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node* InsertionAtStart(Node * head, int el){
    Node * newNode = new Node(el,head,nullptr);
    head->back=newNode;
    return newNode;
}
Node* InsertionAtEnd(Node * head, int el){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev= temp->back;
    Node*newNode = new Node (el,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
    
}
Node* InsertionBeforeKthElement(Node * head, int k, int el){
    Node * temp= head;
    int cnt=0;
    while(temp!=NULL){
     cnt++;
     if(cnt==k){
         break;
     }
     temp=temp->next;
  }
  Node* prev= temp->back;
   Node* newNode= new Node (el,temp,prev);
   prev->next=newNode;
   temp->back=newNode;
   return head;
}
Node* InsertionAfterKthElement(Node * head, int k, int el){
    Node * temp= head;
    int cnt=0;
    while(temp!=NULL){
     cnt++;
     if(cnt==k){
         break;
     }
     temp=temp->next;
  }
  Node* front= temp->next;
   Node* newNode= new Node (el,front,temp);
   front->back=newNode;
   temp->next=newNode;
   return head;
}


void display(Node* head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
  
}

    int main(){
   vector<int> arr = {1,23,4,5,6};
    Node* head =convertArrToDll(arr);
    display(head);
    cout<<endl;
    Node* head2= InsertionAfterKthElement(head,2,69);
    display(head2);
    
    
    
    

}