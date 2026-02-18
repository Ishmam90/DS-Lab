#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int a, b, src;
    cin>>a>>b>>src;

    vector<vector<int>> v(a+1);
    vector<bool> visited(a+1, false);

    for(int i=0; i<b; i++){
        int x, y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
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
    cout<<"BFS order: ";
    queue<int> q;

    q.push(src);
    visited[src]=true;

    while(!q.empty()){
        cout<<q.front()<<" ";

        for(int i=0; i<v[q.front()].size(); i++){
            int neighbor=v[q.front()][i];
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }

        q.pop();
    }

    cout<<endl;
    cout<<endl;
    cout<<"Distance from source:"<<endl;
    
    visited.assign(a+1, false);
    vector<int> distance(a+1, 0);
    q.push(src);
    visited[src]=true;

    while(!q.empty()){
        for(int i=0; i<v[q.front()].size(); i++){
            int neighbor=v[q.front()][i];
            if(!visited[neighbor]){
                visited[neighbor]=true;
                distance[neighbor]=distance[q.front()]++;
                q.push(neighbor);
            }
        }

        q.pop();
    }

    for(int i=1; i<=a; i++){
        cout<<i<<"("<<distance[i]<<") ";
    }

    cout<<endl;
    cout<<endl;
}