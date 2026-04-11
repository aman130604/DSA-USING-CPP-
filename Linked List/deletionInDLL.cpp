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
Node* deletionAtHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev= head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
    
}
Node* deletionAtEnd(Node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*prev=temp->back;
    prev->next=NULL;
    temp->back=NULL;
    delete temp;
    return head;
    
}
Node* deletionAtSpecificPosition(Node* head, int k=1){
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node * prev= temp->back;
    Node* front= temp->next;
    if(prev==NULL && front==NULL){
        delete temp;
        return NULL;
    }
    else if (prev==NULL){
      return deletionAtHead(head);
    }
    else if(front==NULL){
        return deletionAtEnd(head);
    }
    else{
        prev->next=front;
        front->back=prev;
        temp->back==NULL;
        temp->next==NULL;
        delete temp;
        return head;
    }
    
}
void deleteNode(Node* temp){
    if(temp == NULL) return;

    Node* front = temp->next;
    Node* prev  = temp->back;

    // Case 1: temp is the only node
    if(prev == NULL && front == NULL){
        delete temp;
        return;
    }

    // Case 2: temp is head
    if(prev == NULL){
        front->back = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    // Case 3: temp is last node
    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }

    // Case 4: temp is in middle
    prev->next = front;
    front->back = prev;

    temp->next = NULL;
    temp->back = NULL;
    delete temp;
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
    Node* head2= deletionAtSpecificPosition(head,2);
    display(head2);
}