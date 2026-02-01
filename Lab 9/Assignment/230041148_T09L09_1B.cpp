#include<iostream>
#include<string>
#include<unordered_map>
#include<sstream>
using namespace std;

int main(){
    unordered_map<string, int> m;
    string s;

    getline(cin, s);

    stringstream ss(s);
    string word;
    while(ss>>word){
        m[word]++;
    }

    for(auto it:m){
        if(it.second>1){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}