#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> num, nge;
    stack<int> st;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        num.push_back(x);
    }

    for(int i=num.size()-1; i>=0; i--){
        while(!st.empty() && st.top()<=num[i]){
            st.pop();
        }

        if(!st.empty()) nge.push_back(st.top());
        else            nge.push_back(-1);

        st.push(num[i]);
    }

    for(int i=nge.size()-1; i>=0; i--) cout<<nge[i]<<" ";
}