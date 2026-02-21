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
int lengthOfLL(Node* &head){
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
       temp=temp->next;
       cnt++;
    }
    return cnt;
}
bool searchInLL(Node*&head,int val){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            return true;
        }
        temp=temp->next;
    }
    return false;
    
}
int main(){
    vector<int>arr = {1,2,3,4,5};
    Node* node= new Node(arr[0]);
    cout<<node->data;
    Node * head= convertArrtoLL(arr);
    cout<<head->data;
    display(head);
    cout<<lengthOfLL(head);
    cout<<searchInLL(head,41);
}