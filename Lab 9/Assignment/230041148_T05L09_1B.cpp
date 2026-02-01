#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class TrieNode{
    public:
        TrieNode* children[26];
        bool endOfWord;

        TrieNode(){
            for(int i=0; i<26; i++){
                children[i]=NULL;
            }
            endOfWord=false;
        }
};

class Trie{
    private:
        TrieNode* root;
    
    public:
        Trie(){
            root=new TrieNode();
        }

        void insert(string word){
            TrieNode* node=root;
            for(char c:word){
                int index=c-'a';
                if(!node->children[index]){
                    node->children[index]=new TrieNode();
                }
                node=node->children[index];
            }
            node->endOfWord=true;
        }

        void display(TrieNode* node, string word){
            if(node->endOfWord){
                cout<<word<<" ";;
            }

            for(int i=0; i<26; i++){
                if(node->children[i]){
                    display(node->children[i], word+char('a'+i));
                }
            }
        }

        TrieNode* get_root(){
            return root;
        }
};

int main(){
    Trie t;
    string s;

    getline(cin, s);

    stringstream ss(s);
    string word;
    while(ss>>word){
        t.insert(word);
    }

    cin>>s;
    string query="";

    for(int i=0; i<s.size(); i++){
        query+=s[i];
        t.display(t.get_root(), query);
        cout<<endl;
    }
}