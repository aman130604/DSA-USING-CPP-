#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*back;
    public:
    Node(int data1,Node*next1,Node*back1){
    data=data1;
   next=next1;
    back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=NULL;
        back=NULL;
    }
    
};
Node* convertArrtoDll(vector<int>arr){
    int n = arr.size();
    Node* head= new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<n;i++){
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
}
int main(){
   vector<int> arr = {1,23,4,5,6};
    Node* head =convertArrtoDll(arr);
    print(head);
    
    
    
}