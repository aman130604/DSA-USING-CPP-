#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node * convertArrtoLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void display(Node * &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* insertAtBegning(Node*head,int val){
    Node*temp=new Node(val);
    temp->next=head;
    return temp;
}
Node*insertAtEnd(Node*head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*newNode= new Node(val);
    temp->next=newNode;
    return head;
}
Node* insertAtKthPosition(Node*head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return NULL;
        }
    }
    if(k==1){
        Node*temp=new Node(val);
        temp->next=head;
        return temp;
        
    }
    Node*temp=head;
    int count=1;
    while(temp!=NULL){
       
            if(count==(k-1)){
            Node*newNode= new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
           
        }
          count++;
         temp=temp->next;
        
    }
    return head;
    
}


int main(){
    vector<int>arr = {1,2,3,4,5};
    Node* node= new Node(arr[0]);
    cout<<node->data;
    Node * head= convertArrtoLL(arr);
    display(head);
    cout<<endl;
    head=insertAtBegning(head,34);
    head=insertAtEnd(head,67);
    head=insertAtKthPosition(head,69,5);
    display(head);
    
    
}