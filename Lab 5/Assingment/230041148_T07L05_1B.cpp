#include<iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int val;
    
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class Queue{
    private:
        Node* head;
        Node* tail;
        int sz;
        int capacity;

    public:
        Queue(int cap){
            head=NULL;
            tail=NULL;
            capacity=cap;
            sz=0;
        }

        void enqueue(int x){
            if(sz==capacity){
                cout<<"Overflow";
                return;
            }
            
            Node* newNode=new Node(x);

            if(head==NULL){
                head=newNode;
                tail=newNode;
                sz++;

                return;
            }

            tail->next=newNode;
            tail=newNode;
            sz++;
        }

        void dequeue(){
            if(sz==0){
                cout<<"Underflow";
                return;
            }

            Node* temp=head;
            head=head->next;

            delete temp;
            sz--;
        }

        bool isEmpty(){
            if(head==NULL)  return true;
            else    return false;
        }

        bool isFull(){
            if(sz==capacity) return true;
            else    return false;
        }

        int size(){
            return sz;
        }

        int front(){
            if(head!=NULL)  return head->val;
        }

        void print(){
            Node* temp=head;

            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }

            cout<<endl;
        }
};

int main(){
    int n;
    cin>>n;

    Queue s(n);

    while(1){
        int comm;
        cin>>comm;

        if(comm==-1)   break;

        if(comm==1){
            int x;
            cin>>x;

            s.enqueue(x);
            s.print();
        }

        else if(comm==2){
            s.dequeue();
            s.print();
        }

        else if(comm==3){
            if(s.isEmpty()) cout<<"True"<<endl;
            else            cout<<"False"<<endl;
        }

        else if(comm==4){
            if(s.isFull())   cout<<"True"<<endl;
            else             cout<<"False"<<endl;
        }

        else if(comm==5){
            cout<<s.size()<<endl;
        }

        else if(comm==6){
            cout<<s.front()<<endl;
        }
    }
}