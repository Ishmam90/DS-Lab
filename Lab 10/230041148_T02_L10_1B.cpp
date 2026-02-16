#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<pair<int, int>> v;
    
    cin>>n;

    while(true){
        int comm;
        cin>>comm;

        if(comm==1){
            for(int i=0; i<n; i++){
                v.push_back({i, 0});
            }

            for(auto it:v){
                cout<<it.first<<"("<<it.second<<") ";
            }

            cout<<endl;
        }

        else if(comm==2){
            int x;
            cin>>x;

            cout<<v[x].first<<endl;

            while(true){
                if(x!=v[x].first){
                    cout<<"f("<<v[x].first<<") ";
                    x=v[x].first;
                }
                else    break;
            }
            cout<<endl;
        }

        else if(comm==3){
            int a, b;
            cin>>a>>b;

            if(v[a].second==v[b].second){
                if((v[a].first==a && v[b].first==b) || (v[a].first!=a && v[b].first!=b)){
                    if(v[a].first>v[b].first){
                        v[b].first=v[a].first;
                        v[a].second++;
                    }
                    else{
                        v[a].first=v[b].first;
                        v[b].second++;
                    }
                }

                else if(v[a].first!=a && v[b].first==b){
                    v[b].first=v[a].first;
                }

                else if(v[a].first==a && v[b].first!=b){
                    v[a].first=v[b].first;
                }
            }

            else if(v[a].second>v[b].second){
                v[b].first=v[a].first;
            }

            else{
                v[a].first=v[b].first;
            }

            for(auto it:v){
                cout<<it.first<<"("<<it.second<<") ";
            }

            cout<<endl;
        }

        else    break;
    }
}