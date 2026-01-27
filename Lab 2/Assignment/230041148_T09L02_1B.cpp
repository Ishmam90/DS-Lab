#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    stack<char> c1, c2;

    cin>>s;

    for(int i=0; i<s.size(); i++)   c1.push(s[i]);

    while(1){
        bool ver=true;

        if(c1.empty()){
            while(!c2.empty()){
                c1.push(c2.top());
                c2.pop();

                if(c2.empty())  break;

                if(c1.top()==c2.top()){
                    c1.pop();
                    c2.pop();
                    ver=false;
                }
            }
        }

        else{
            while(!c1.empty()){
                c2.push(c1.top());
                c1.pop();

                if(c1.empty())  break;

                if(c1.top()==c2.top()){
                    c1.pop();
                    c2.pop();
                    ver=false;
                }
            }
        }

        if(ver)     break;
    }

    if(c1.empty()){
        while(!c2.empty()){
            cout<<c2.top();
            c2.pop();
        }
    }

    else if(c2.empty()){
        while(!c1.empty()){
            cout<<c1.top();
            c1.pop();
        }
    }

    else if(c1.empty() && c2.empty())   cout<<"NULL";
}