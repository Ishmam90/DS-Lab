#include<iostream>
using namespace std;

class Deque{
    private:
        int *arr;
        int ft, sz, capacity;

    public:
        Deque(int cap){
            capacity=cap;
            arr=new int[capacity];
            ft=0;
            sz=0;
        }

        void push_front(int x){
            if(sz==capacity){
                cout<<"Overflow"<<endl;
                return;
            }

            ft=(ft-1+capacity)%capacity;
            arr[ft]=x;
            sz++;

            for(int i=0; i<sz; i++){
                cout<<arr[(ft+i)%capacity]<<" ";
            }

            cout<<endl;
        }

        void push_back(int x){
            if(sz==capacity){
                cout<<"Overflow"<<endl;
                return;
            }

            int rear=(ft+sz)%capacity;
            arr[rear]=x;
            sz++;

            for(int i=0; i<sz; i++){
                cout<<arr[(ft+i)%capacity]<<" ";
            }

            cout<<endl;
        }

        void pop_front(){
            if(sz==0){
                cout<<"Undeflow"<<endl;
                return;
            }

            int val=arr[ft];
            ft=(ft+1)%capacity;
            sz--;

            for(int i=0; i<sz; i++){
                cout<<arr[(ft+i)%capacity]<<" ";
            }

            cout<<endl;
        }

        void pop_back(){
            if(sz==0){
                cout<<"Underflow"<<endl;
                return;
            }

            int rear=(ft+sz-1)%capacity;
            int val=arr[rear];
            sz--;

            for(int i=0; i<sz; i++){
                cout<<arr[(ft+i)%capacity]<<" ";
            }

            cout<<endl;
        }

        int size(){
            return      sz;
        }
};

int main(){
    int n;
    cin>>n;

    Deque q(n);

    while(1){
        int comm;
        cin>>comm;

        if(comm==-1)       break;

        if(comm==1){
            int x;
            cin>>x;

            q.push_front(x);
        }

        else if(comm==2){
            int x;
            cin>>x;

            q.push_back(x);
        }

        else if(comm==3){
            q.pop_front();
        }

        else if(comm==4){
            q.pop_back();
        }

        else if(comm==5){
            cout<<q.size()<<endl;
        }

        else if(comm==6){
            break;
        }
    }
}