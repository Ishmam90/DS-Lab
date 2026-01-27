#include <bits/stdc++.h>
using namespace std;

bool isMatch(char open, char close){
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}

int main(){
    int n;
    cin >> n;
    cin.ignore();

    vector<string> code(n);
    for(int i=0; i<n; i++)      getline(cin, code[i]);

    stack<char> st;

    for(int i=0; i<n; i++){
        for(char c : code[i]){
            if(c=='(' || c=='{' || c=='[')    st.push(c);
            else if(c==')' || c=='}' || c==']'){
                if(st.empty()){
                    cout << "Error\n";
                    return 0;
                }
                if(!isMatch(st.top(), c)){
                    cout << "Error\n";
                    return 0;
                }
                st.pop();
            }
        }
    }

    if(st.empty())
        cout << "No Error\n";
    else
        cout << "Error\n";

    return 0;
}