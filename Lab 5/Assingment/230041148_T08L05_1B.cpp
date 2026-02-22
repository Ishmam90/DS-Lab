#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

    Node(int val){
        this->val=val;
        this->next=NULL;
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
        
        Node* get_odd(){
            return head;
        }

        Node* get_even(){
            return head->next;
        }
};

void print(Node* head){
    Node* temp=head;
    int count=0;

    while(temp!=NULL){
        if(count%2==0){
            cout<<temp->val<<" ";
        }

        temp=temp->next;
        count++;
    }
}


int main(){
    linkedList l;

    while(1){
        int x;
        cin>>x;

        if(x==NULL)     break;
        l.insert_at_tail(x);
    }

    print(l.get_odd());
    print(l.get_even());
}