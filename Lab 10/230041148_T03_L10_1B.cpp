#include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;

int main(){
    int a,b;
    map<int, list<int>> m;
    cin>>a>>b;

    for(int i=0; i<b; i++){
        int x, y;
        cin>>x>>y;

        m[x].push_back(y);
        m[y].push_back(x);
    }

    cout<<"Adjacency List:"<<endl;
    for(int i=1; i<=a; i++){
        cout<<i<<": ";
        for(auto it:m[i]){
            if(!m[i].empty())   cout<<it<<" ";
            else                break;
        }
        cout<<endl;
    }

    cout<<"Adjacency Matrix:"<<endl;
    for(int i=1; i<=a; i++){
        vector<int> v(a+1, 0);

        for(auto it:m[i]){
            v[it]=1;
        }

        for(int j=1; j<=a; j++){
            cout<<v[j]<<" ";
        }

        cout<<endl;
    }
}