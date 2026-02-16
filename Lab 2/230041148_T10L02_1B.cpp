#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    int n, current=1;
    bool ver=true;

    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        if(x==current)  current++;
        else            s.push(x);
    }
    
    for(int i=0; i<s.size(); i++){
        if(s.top()!=current){
            cout<<"No"<<endl;
            ver=false;
            break;
        }
        else{
            s.pop();
        }
        current++;
    }

    if(ver)     cout<<"Yes";
}