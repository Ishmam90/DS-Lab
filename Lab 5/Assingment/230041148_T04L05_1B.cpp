#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    
    Node(int val){
        this->next=NULL;
        this->val=val;
    }
};

class linkedList{
    private:
        Node* head;
        Node* tail;

    public:
        linkedList(){
            head=NULL;
            tail=NULL;
        }

        void insert_at_tail(int val){
            Node* newNode=new Node(val);

            if(head==NULL){
                head=newNode;
                tail=newNode;

                return;
            }

            tail->next=newNode;
            tail=newNode;
        }

        void remove_node(){
            if(head==NULL)  return;
            
            Node* temp=head;

            while(temp->next!=NULL){
                if(temp->val==temp->next->val){
                    Node* del=temp->next;
                    temp->next=temp->next->next;
                    
                    delete  del;
                }

                else    temp=temp->next;
            }
        }

        void print(){
            if(head==NULL)  return;

            Node* temp=head;

            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
        }
};

int main(){
    linkedList l;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;

        l.insert_at_tail(x);
    }

    l.remove_node();
    l.print();
}