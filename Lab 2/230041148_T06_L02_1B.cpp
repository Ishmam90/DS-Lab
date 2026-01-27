#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;

    while(x--){
        stack<char> st;
        vector<char> q;
        string s;
        bool ver=true;

        cin>>s;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')         st.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']')    q.push_back(s[i]);
        }

        if(st.size()!=q.size()){
            cout<<"No"<<endl;
            continue;
        }

        else{
            for(int i=0; i<st.size(); i++){
                if(st.top()!=q.back()){
                    cout<<"No"<<endl;
                    ver=false;
                    break;
                }
                st.pop();
                q.pop_back();
            }

            if(ver)   cout<<"Yes"<<endl;
        }
    }
}