#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<char, string> m;
    unordered_map<string, int> unique;
    int n;

    cin>>n;

    m['a']=".-";    m['b']="-...";  m['c']="-.-.";  m['d']="-..";   m['e']=".";     m['f']="..-.";  m['g']="--.";   m['h']="....";  m['i']="..";    m['j']=".---";
    m['k']="-.-";   m['l']=".-..";  m['m']="--";    m['n']="-.";    m['o']="---";   m['p']=".--.";  m['q']="--.-";  m['r']=".-.";   m['s']="...";   m['t']="-";
    m['u']="..-";   m['v']="...-";  m['w']=".--";   m['x']="-..-";  m['y']="-.--";  m['z']="--..";

    while(n--){
        string s, morse;
        cin>>s;

        for(int i=0; i<s.size(); i++){
            morse+=m.at(s[i]);
        }

        unique[morse]++;
    }

    cout<<unique.size()<<endl;
    for(auto it:unique){
        cout<<it.first<<endl;
    }
}