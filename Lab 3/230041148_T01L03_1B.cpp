#include<iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int ft, sz, capacity;

    public:
        Queue(int cap){
            capacity=cap;
            arr=new int[capacity];
            ft=0;
            sz=0;
        }

        void EnQueue(int x){
            if(sz==capacity){
                cout<<"Enqueue: Overflow"<<endl;
                return;
            }

            int rear=(ft+sz)%capacity;
            arr[rear]=x;
            sz++;

            cout<<"Enqueue: ";

            for(int i=0; i<sz; i++){
                cout<<arr[(ft+i)%capacity]<<" ";
            }

            cout<<endl;
        }

        void DeQueue(){
            if(sz==0){
                cout<<"Dequeue: Underflow"<<endl;
                return;
            }

            ft=(ft+1)%capacity;
            sz--;

            cout<<"Dequeue: ";

            for(int i=0; i<sz; i++){
                cout<<arr[(ft+i)%capacity]<<" ";
            }

            cout<<endl;
        }

        bool isEmpty(){
            if(sz==0)     return true;
            else          return false;
        }

        bool isFull(){
            if(sz==capacity)  return  true;
            else              return  false;
        }

        int size(){
            return      sz;
        }

        int front(){
            return      arr[ft];
        }
};

int main(){
    int n;
    cin>>n;

    Queue q(n);

    while(1){
        int comm;
        cin>>comm;

        if(comm==-1)       break;

        if(comm==1){
            int x;
            cin>>x;

            q.EnQueue(x);
        }

        else if(comm==2){
            q.DeQueue();
        }

        else if(comm==3){
            if(q.isEmpty())     cout<<"isEmpty: True"<<endl;
            else                cout<<"isEmpty: False"<<endl;
        }

        else if(comm==4){
            if(q.isFull())      cout<<"isFull: True"<<endl;
            else                cout<<"isFull: False"<<endl;
        }

        else if(comm==5){
            cout<<"Size: "<<q.size()<<endl;
        }

        else if(comm==6){
            cout<<"Front: "<<q.front()<<endl;
        }
    }
}