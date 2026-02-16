#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Queue{
    private:
        stack<int> s1, s2;
        vector<int> v;
        int size, capacity;

    public:
        Queue(int x){
            size=0;
            capacity=x;
        }

        void push(int x){
            if(size==capacity){
                cout<<"Size: "<<size<<" ELements: Overflow!"<<endl;
            }

            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(x);

            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }

            cout<<"Size: "<<s1.size()<<" Elements: ";

            while(!s1.empty()){
                cout<<s1.top()<<" ";
                v.push_back(s1.top());
                s1.pop();
            }

            while(!v.empty()){
                s1.push(v.back());
                v.pop_back();
            }

            size++;
            cout<<endl;
        }

        void pop(){
            s1.pop();
            size--;
            
            if(size==0){
                cout<<"Size: "<<size<<"ELements: NULL"<<endl;
            }

            else{
                cout<<"Size: "<<s1.size()<<" Elements: ";
            }

            while(!s1.empty()){
                cout<<s1.top()<<" ";
                v.push_back(s1.top());
                s1.pop();
            }

            while(!v.empty()){
                s1.push(v.back());
                v.pop_back();
            }

            cout<<endl;
        }
};

int main(){
    int i, q;

    cin>>i>>q;

    Queue que(i);

    while(q--){
        int comm;
        cin>>comm;
        
        if(comm==1){
            int x;
            cin>>x;

            que.push(x);
        }

        else if(comm==2){
            que.pop();
        }
    }
}