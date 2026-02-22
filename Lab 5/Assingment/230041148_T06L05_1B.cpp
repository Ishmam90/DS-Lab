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

class Stack{
    private:
        Node* head;
        int capacity;
        int sz;

    public:
        Stack(int cap){
            head=NULL;
            capacity=cap;
            sz=0;
        }

        void push(int val){
            if(sz==capacity){
                cout<<"Overflow"<<endl;
                return;
            }
            
            Node* newNode=new Node(val);

            if(head==NULL){
                head=newNode;
                sz++;

                return;
            }

            newNode->next=head;
            head=newNode;
            sz++;
        }

        void pop(){
            if(sz==0){
                cout<<"Underflow";
                return;
            }
            
            Node* temp=head;
            head=head->next;

            delete temp;
            sz--;
        }

        int size(){
            return sz;
        }

        int top(){
            if(head!=NULL)      return head->val;
        }

        bool isEmpty(){
            if(head==NULL)      return true;
            return  false;
        }

        bool isFull(){
            if(sz==capacity)    return true;;
            return  false;
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

    Stack s(n);

    while(1){
        int comm;
        cin>>comm;

        if(comm==-1)   break;

        if(comm==1){
            int x;
            cin>>x;

            s.push(x);
            s.print();
        }

        else if(comm==2){
            s.pop();
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
            cout<<s.top()<<endl;
        }
    }
}