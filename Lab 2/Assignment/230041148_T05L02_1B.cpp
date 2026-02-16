#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    while(n--){
        string s;
        stack<char> c;

        cin>>s;

        for(int i=0; i<s.length(); i++)   c.push(s[i]);

        for(int i=0; i<s.length(); i++){
            cout<<c.top();
            c.pop();
        }

        cout<<endl;
    }
}