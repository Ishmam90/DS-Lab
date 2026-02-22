#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;    

int main(){
    vector<int> v;
    unordered_map<int, int> m;

    while(true){
        int x;
        cin>>x;

        if(x==-1)   break;
        v.push_back(x);
    }

    int target;
    bool found = false;
    cin>>target;

    for(int i=0; i<v.size(); i++){
        int complement = target - v[i];

        if(m.find(complement) != m.end() && m[complement]>0){
            found = true;
            cout<<"("<<complement<<", "<<v[i]<<")"<<endl;
            m[complement]--;
        }
        m[v[i]]++;
    }

    if(!found){
        cout<<"No pairs found"<<endl;
    }
}