#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

int main(){
    unordered_map<string, string> m;
    string line;

    while(getline(cin, line)){
        if(line.empty())    break;

        stringstream ss(line);
        string main, foreign;
        ss>>main>>foreign;

        m[foreign]=main;
    }

    while(1){
        cin>>line;
        if(line.empty())    break;

        auto it=m.find(line);
        cout<<(it!=m.end() ? it->second : "eh")<<endl;
    }
}