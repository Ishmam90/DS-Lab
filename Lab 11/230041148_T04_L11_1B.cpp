#include<iostream>
#include<vector>
using namespace std;

void dfs(int src, vector<vector<int>> v, vector<int> &visited){
    visited[src]=true;
    cout<<src<<" ";

    for(int i=0; i<v[src].size(); i++){
        int neighbor=v[src][i];
        if(!visited[neighbor]){
            dfs(neighbor, v, visited);
        }
    }
}

int main(){
    int a, b;
    cin>>a>>b;

    vector<vector<int>> v(a+1);
    vector<int> visited(a+1, 0);

    for(int i=0; i<b; i++){
        int x, y;
        cin>>x>>y;

        v[x].push_back(y);
    }

    cout<<"Adjacency List: "<<endl;
    for(int i=1; i<=a; i++){
        cout<<i<<": ";
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"DFS Order: ";
    for(int i=1; i<=a; i++){
        if(!visited[i]) dfs(i, v, visited);
    }
}