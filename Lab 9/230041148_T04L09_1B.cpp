#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class TrieNode{
    public:
        TrieNode* children[26];
        int count;

        TrieNode(){
            for(int i=0; i<26; i++){
                children[i]=NULL;
            }
            count=0;
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
                node->count++;
            }
        }

        int returnCount(string prefix){
            TrieNode* node=root;
            for(char c:prefix){
                int index=c-'a';
                if(!node->children[index]){
                    return 0;
                }
                node=node->children[index];
            }
            return node->count;
        }

        TrieNode* getRoot(){
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

    getline(cin, s);

    stringstream ss1(s);
    while(ss1>>word){
        cout<<t.returnCount(word)<<endl;
    }
}

//beauty beast beautiful amazing amsterdam beautify banana xray beauty glorifying
//a am am beauty beaut beast ing ams be b