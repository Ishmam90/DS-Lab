#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[1001], i=0, target, count=0;

    while(1){
        int x;
        cin>>x;

        if(x==0)        break;
        else            arr[i]=x;
        i++;
    }

    cin>>target;

    for(int j=0; j<i; j++){
        for(int k=j+1; k<i; k++){
            if(arr[j]+arr[k]==target)   count++;
        }
    }

    cout<<count<<" pairs;"<<endl;

    for(int j=0; j<i; j++){
        for(int k=j+1; k<i; k++){
            if(arr[j]+arr[k]==target)   cout<<"(worker- "<<j+1<<", worker- "<<k+1<<")"<<endl;
        }
    }
}