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
        cout<<temp->data;
        temp=temp->next;
    }
}


Node* removeHead(Node* &head){
    if(head==NULL){
        return head;
    }
    Node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
Node* deleteTail(Node*&head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    return head;
}
Node* removeKtNode(Node*&head,int target){
    if(head==NULL){
        return NULL;
    }
    if(target==1){
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;
    int count=1;
    while(temp!=NULL){
        if(count==target){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
        count++;
    }
    return head;
}
Node* removeKtElement(Node*&head,int el){
    if(head==NULL){
        return NULL;
    }
    if(head->data==el){
        Node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node*temp=head;
    Node*prev=NULL;
    
    while(temp!=NULL){
        if(temp->data==el){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;

    }
    return head;
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    Node* node= new Node(arr[0]);
    cout<<node->data;
    Node * head= convertArrtoLL(arr);
    cout<<head->data;
    display(head);
    

    head=removeKtNode(head,2);
   
    cout<<endl;
    display(head);
    cout<<endl;
    head=removeKtElement(head,4);
    display(head);
}