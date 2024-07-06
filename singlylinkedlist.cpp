#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
//constructor
    Node(int data){
        this-> data=data;
        this-> next= NULL;
    }
    //destructor
    ~Node(){
        int value= this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void InsertAtHead(Node* &head, int d){
    //new node create
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}
void InsertAtTail(Node* &tail, int d){
    //new node create
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void InsertAtPosition(Node* &head,Node* &tail, int position, int d){
    //insert at start
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while (cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtTail(tail,d);
        return;

    }
    //creating a node for d
    Node* nodetoInsert=new Node(d);
    nodetoInsert->next=temp->next;
}
//Deletion
void deleteNode(int position, Node* &head){
    //deleting  first or start node
    if(position == 1){
        Node* temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;

        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &head){
   Node* temp = head;
   while(temp!=NULL){
    cout << temp->data<<" ";
    temp= temp->next;

   }
   cout<<endl;

}
int main(){
    Node* node1 = new Node(10);
    Node* head= node1;
    Node* tail= node1;
    print(head);
    InsertAtTail(tail,12);
    print(head);
    InsertAtTail(tail,17);
    print(head);
    InsertAtPosition(head,tail,2,22);
print(head);
deleteNode(1,head);
print(head);
    return 0;
}
