#include <bits/stdc++.h>
using namespace std;

class Stack {
    int topInd;
    int arr[5];

public:
    Stack(){ 
        topInd=-1; 
    }

    void push(int x){
        if(topInd>4){
            cout<<"Overflow"<<endl;
            return;
        }
        arr[++topInd]=x;
        
        for(int i=0; i<=topInd; i++){
            cout<<arr[i]<<" ";
        }
        
        cout<<endl;
    }

    int pop(){
        if (topInd<0){
            cout<<"Underflow"<<endl;
            return 0;
        }

        for(int i=0; i<topInd; i++){
            cout<<arr[i]<<" ";
        }

        topInd--;
        
        cout<<endl;
    }

    int top(){
        if (topInd<0){
            cout<<"Empty"<<endl;
            return 0;
        }

        return arr[topInd];
    }

    int size(){
        return topInd+1;
    }

    bool isEmpty(){
        if(topInd<0)        return true;
        else                return false;
    }

    bool isFull(){
        if(topInd==4)        return true;
        else                 return false;
    }
};

int main()
{
    Stack s;

    while(1){
        int inp;
        cin>>inp;

        if(inp==-1)     break;

        if(inp==1){
            int x;
            cin>>x;
            s.push(x);
        }

        if(inp==2){
            s.pop();
        }

        if(inp==3){
            if(s.isEmpty())       cout<<"True"<<endl;
            else                  cout<<"False"<<endl;
        }

        if(inp==4){
            if(s.isFull())       cout<<"True"<<endl;
            else                  cout<<"False"<<endl;
        }

        if(inp==5){
            cout<<s.size()<<endl;
        }

        if(inp==6){
            cout<<s.top()<<endl;
        }
    }
}