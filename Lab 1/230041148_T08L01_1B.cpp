#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    pair<string, int> dna[101];

    cin>>a>>b;

    for(int i=0; i<b; i++){
        string a;
        cin>>a;
        
        int length=a.length(), count=0;
        for(int j=0; j<length-1; j++){
            for(int k=j; k<length; k++){
                if(a[j]>a[k])   count++;
            }
        }

        dna[i].first=a;
        dna[i].second=count;
    }

    for(int i=0; i<b; i++){
        for(int j=0; j<b; j++){
            if(dna[i].second<dna[j].second){
                pair<string, int> temp=dna[i];
                dna[i]=dna[j];
                dna[j]=temp;
            }
        }
    }

    cout<<endl;

    for(int i=0; i<b; i++){
        cout<<dna[i].first<<" "<<dna[i].second<<endl;
    }
}