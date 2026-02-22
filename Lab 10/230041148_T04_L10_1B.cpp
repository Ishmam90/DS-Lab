#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int a, b;
    queue<int> q;
    vector<int> order;
    
    cin>>a>>b;
    vector<vector<int>> adj(a);
    vector<int> indegree(a, 0);

    for(int i=0; i<b; i++){
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
        indegree[y]++;
    }

    for(int i=0; i<a; i++){
        if(indegree[i]==0)  q.push(i);
    }

    while(!q.empty()){
        order.push_back(q.front());

        for(auto it:adj[q.front()]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }

        q.pop();
    }

    for(int i=0; i<order.size(); i++)   cout<<order[i]<<" ";
}