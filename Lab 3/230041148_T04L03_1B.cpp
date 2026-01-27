#include<iostream>
#include<queue>
using namespace std;

int main(){
    string s1, s2;
    queue<char> main, sub;
    int count=0;

    cin>>s1;
    cin.ignore();
    cin>>s2;

    if(s1.size()!=s2.size()){
        cout<<"No";
        return 0;
    }

    for(int i=s1.size()-1; i>=0; i--){
        main.push(s1[i]);
        sub.push(s2[i]);
    }

    int size1=main.size();
    int size2=sub.size();
    
    while(size1--){
        bool same=true;
        queue<char> temp=main;

        for(int i=0; i<size2; i++){
            if(temp.front()!=sub.front())      same=false;
            
            temp.pop();
            sub.push(sub.front());
            sub.pop();
        }

        if(same){
            cout<<"Yes. After "<<count<<" clockwise rotations";
            return 0;
        }

        else{
            main.push(main.front());
            main.pop();
        }

        count++;
    }

    cout<<"No";
}