#include<bits/stdc++.h>
using namespace std;

int main(){
    int freq[10]={0};

    while(1){
        int x;
        cin>>x;

        if(x<1)     break;
        else        freq[x]+=1;
    }

    pair<int, int> seq[10];

    for(int i=1; i<10; i++){
        seq[i].first=i;
        seq[i].second=freq[i];
    }

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            if(seq[i].second>seq[j].second){
                pair<int, int> temp=seq[i];
                seq[i]=seq[j];
                seq[j]=temp;
            }
        }
    }

    cout<<endl;

    for(int i=1; i<10; i++){
        if(seq[i].second>0) cout<<seq[i].first<<" occurs "<<seq[i].second<<" times"<<endl;
    }
}