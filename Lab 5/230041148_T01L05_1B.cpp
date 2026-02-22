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

class LinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(){
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
                tail=newNode;
            }
        }

        void insert_after_node(int key, int v){
            Node* newNode=new Node(key);
            Node* temp=head;
            bool check=false;

            if(head==NULL){
                head=newNode;
                tail=newNode;
            }

            while(temp->next!=NULL && temp->val!=v)    temp=temp->next;

            if(temp!=NULL){    
                newNode->next=temp->next;
                temp->next=newNode;

                if(temp==tail)  tail=newNode;
            }
            else{
                cout<<"Not found"<<endl;
            }
        }

        void update_node(int key, int v){
            Node* newNode=new Node(key);

            if(head==NULL){
                head=newNode;
                tail=newNode;
            }

            Node* temp=head;

            while(temp->val!=v && temp->next!=NULL)    temp=temp->next;

            temp->val=key;
        }

        void remove_head(){
            if(head==NULL){
                cout<<"Underflow"<<endl;
                return;
            }

            Node* temp=head;
            head=head->next;
            delete temp;
        }

        void remove_element(int key){
            if(head==NULL){
                cout<<"Underflow"<<endl;
                cout<<"Head=Null, Tail=Null, Empty"<<endl;
                return;
            }

            Node* temp=head;

            while(temp->next!=NULL && temp->next->val!=key) temp=temp->next;

             if(temp->next == NULL){
                cout<<"Value not found\n";
                return;
            }

            Node* del=temp->next;
            temp->next=temp->next->next;
            if(del==tail)   tail=temp;
            delete del;
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

            Node* temp=head;

            while(temp->next->next!=NULL)   temp=temp->next;

            Node* del=temp->next;
            temp->next=NULL;
            tail=temp;
            delete del;
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
    LinkedList l;

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

        else if(comm==3){
            int key, v;
            cin>>key>>v;

            l.insert_after_node(key, v);
            l.print();
        }

        else if(comm==4){
            int key, v;
            cin>>key>>v;

            l.update_node(key, v);
            l.print();
        }

        else if(comm==5){
            l.remove_head();
            l.print();
        }

        else if(comm==6){
            int key;
            cin>>key;

            l.remove_element(key);
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