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
            Node* newNode= new Node(val);

            if(head==NULL){
                head=newNode;
                tail=newNode;

                return;
            }

            tail->next=newNode;
            tail=newNode;
        }

        void print(){
            if(head==NULL){
                cout<<"Empty"<<endl;
                return;
            }

            Node* temp=head;

            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
        }

        Node* get_head(){
            return head;
        }
};

linkedList interserction(Node* n1, Node* n2){
    linkedList l;

    while(n1!=NULL && n2!=NULL){
        if(n1->val<n2->val)         n1=n1->next;
        else if(n2->val<n1->val)    n2=n2->next;
        else if(n1->val==n2->val){
            l.insert_at_tail(n1->val);
            n1=n1->next;
            n2=n2->next;
        }
    }

    return l;
}

int main(){
    linkedList l1,l2;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        l1.insert_at_tail(x);
    }

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        l2.insert_at_tail(x);
    }

    linkedList result=interserction(l1.get_head(), l2.get_head());
    result.print();
}