#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    bool daiyan=false, ishraq=false;
    queue<int> q;
    string s;

    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        q.push(x);
    }

    cin.ignore();
    cin>>s;

    if(s=="Daiyan")     daiyan=true;
    else                ishraq=true;

    while(!q.empty()){
        if(daiyan){
            q.push(q.front());
            q.pop();
            q.pop();
            if(q.empty())   break;

            daiyan=false;
            ishraq=true;

            cout<<"Daiyan ";

            for(int i=0; i<q.size(); i++){
                cout<<q.front()<<" ";
                q.push(q.front());
                q.pop();
            }

            cout<<endl;
        }

        else if(ishraq){
            q.push(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
            q.pop();
            if(q.empty())   break;
            
            ishraq=false;
            daiyan=true;

            cout<<"Ishraq ";

            for(int i=0; i<q.size(); i++){
                cout<<q.front()<<" ";
                q.push(q.front());
                q.pop();
            }

            cout<<endl;
        }
    }
}