#include<iostream>
#include<map>
#include<list>
using namespace std;

int main(){
    int a, b;
    map<int, list<int>> m;

    cin>>a>>b;

    for(int i=1; i<=a; i++) m[i].push_back(0);

    while(b--){
        int x, y;
        cin>>x>>y;

        m[x].push_back(y);
        m[y].push_back(x);
    }

    int edge=0;
    
    for(auto it:m){
        if(edge==0) edge=it.second.size();
        else if(edge!=it.second.size()){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}