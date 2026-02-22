#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;

    cin>>n>>q;

    stack<int> num, pseudo;
    vector<int> v;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        v.push_back(x);
    }

    while(!v.empty()){
        num.push(v.back());
        v.pop_back();
    }

    while(q--){
        int x, count=0;
        bool found=false;
        cin>>x;

        while(!num.empty()){
            count++;

            if(x==num.top() && !found){
                cout<<count<<" ";
                num.pop();
                found=true;
            }

            else{
                pseudo.push(num.top());
                num.pop();
            }
        }

        while(!pseudo.empty()){
            num.push(pseudo.top());
            pseudo.pop();
        }

        num.push(x);
    }
}