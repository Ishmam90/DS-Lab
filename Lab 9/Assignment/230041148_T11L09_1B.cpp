#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<list>
#include<sstream>
using namespace std;

int main(){
    unordered_map<string, list<string>> m;
    string s;
    set<char> st;
    vector<string> v;

    getline(cin, s);

    stringstream ss(s);
    string word;
    while(ss>>word){
        v.push_back(word);
    }

    for(int i=0; i<v.size(); i++){
        st.clear();
        string w;
        for(int j=0; j<v[i].size(); j++){
            st.insert(v[i][j]);
        }

        for(auto it:st){
            w+=it;
        }

        m[w].push_back(v[i]);
    }

    st.clear();
    cin>>word;

    for(int i=0; i<word.size(); i++){
        st.insert(word[i]);
    }

    word.clear();
    for(auto it:st){
        word+=it;
    }

    for(auto it:m[word]){
        cout<<it<<" ";
    }
}