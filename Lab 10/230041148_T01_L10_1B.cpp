#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<int> v;
    
    cin>>n;

    while(true){
        int comm;
        cin>>comm;

        if(comm==1){
            for(int i=0; i<n; i++){
                v.push_back(i);
                cout<<i<<" ";
            }

            cout<<endl;
        }

        else if(comm==2){
            int x;
            cin>>x;

            while(true){
                if(v[x]!=x){
                    x=v[x];
                }

                else break;
            }

            cout<<v[x]<<endl;
        }

        else if(comm==3){
            int a, b;
            cin>>a>>b;

            a=v[a];

            while(true){
                if(v[b]!=b){
                    b=v[b];
                }

                else break;
            }

            v[b]=a;

            for(int i=0; i<n; i++){
                cout<<v[i]<<" ";
            }

            cout<<endl;
        }

        else    break;
    }
}