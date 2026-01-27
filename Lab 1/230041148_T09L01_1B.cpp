#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,r,s[1001];

    cin>>n>>r;

    for(int i=0; i<n; i++)      cin>>s[i];

    for(int i=0; i<r; i++){
        int p, count=0, sum=0;
        cin>>p;

        for(int j=0; j<n; j++){
            if(p>=s[j]){
                sum+=s[j];
                count++;
            }
        }

        cout<<count<<" "<<sum<<endl;
    }
}