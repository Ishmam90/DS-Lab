#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class Deque{
    private:
        Node* head;
        Node* tail;

    public:
        Deque(){
            head=NULL;
            tail=NULL;
        }

        void insert_front(int key){
            Node* newNode=new Node(key);
            
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }
        }

        void insert_back(int key){
            Node* newNode=new Node(key);

            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
        }

        void remove_head(){
            if(head==NULL){
                cout<<"Underflow"<<endl;
                return;
            }

            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }

        void remove_tail(){
            if(head==NULL){
                cout<<"Underflow"<<endl;
                return;
            }

            if(head->next==NULL){
                delete head;
                head=NULL;
                tail=NULL;
                cout<<"Head=Null, Tail=Null, Empty"<<endl;
                return;
            }

            Node* temp=tail;

            tail->prev->next=NULL;
            tail=temp;
            delete temp;
        }

        void print(){
            if(head!=NULL){
                cout<<"Head="<<head->val<<", ";
                cout<<"Tail="<<tail->val<<", ";
            }

            if(head==NULL)    cout<<"Empty"<<endl;
            else{
                Node* temp=head;
                while(temp!=NULL){
                    cout<<temp->val<<" ";
                    temp=temp->next;
                }
            }

            cout<<endl;
        }
};

int main(){
    Deque l;

    while(1){
        int comm;
        cin>>comm;

        if(comm==1){
            int x;
            cin>>x;

            l.insert_front(x);
            l.print();
        }

        else if(comm==2){
            int x;
            cin>>x;

            l.insert_back(x);
            l.print();
        }

        else if(comm==5){
            l.remove_head();
            l.print();
        }

        else if(comm==7){
            l.remove_tail();
            l.print();
        }

        else if(comm==8){
            break;
        }
    }
}