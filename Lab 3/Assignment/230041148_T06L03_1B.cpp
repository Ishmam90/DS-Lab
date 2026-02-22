#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<char> back;
    stack<string> front;
    bool op=false;
    string s, line;

    cin>>line;

    for(int i=0; i<line.size(); i++){
        if(line[i]=='[')         op=true;
        else if(line[i]==']')    op=false;

        if(op){
            if(((line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z') || line[i]=='_') && line[i+1]!=']'){
                s+=line[i];
            }

            else if(((line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z') || line[i]=='_') && line[i+1]==']'){
                s+=line[i];
                front.push(s);
            }
        }

        else if(((line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z') || line[i]=='_') && !op)     back.push(line[i]);
    }

    while(!front.empty()){
        cout<<front.top();
        front.pop();
    }

    while(!back.empty()){
        cout<<back.front();
        back.pop();
    }
}