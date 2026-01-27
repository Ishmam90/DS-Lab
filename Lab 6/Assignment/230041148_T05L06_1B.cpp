#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int val;
        Node* right;
        Node* left;
        Node* parent;

        Node(int val){
            this->val=val;
            this->right=NULL;
            this->parent=NULL;
            this->left=NULL;
        }
};

class bst{
    private:
        Node* root;
        vector<int> v;

    public:
        bst(){
            root=NULL;
        }

        void insert(int val){
            Node* newNode=new Node(val);
            Node* temp=root;
            Node* parent=NULL;

            if(root==NULL){
                root=newNode;
                return;
            }

            while(temp!=NULL){
                parent=temp;
                if(val<temp->val)       temp=temp->left;
                else if(val>temp->val)  temp=temp->right;
            }

            newNode->parent=parent;
            if(val<parent->val) parent->left=newNode;
            else                parent->right=newNode;
        }

        void inorder(Node* r){
            if(r==NULL) return;

            inorder(r->left);
            v.push_back(r->val);
            inorder(r->right);
        }

        Node* get_root(){
            return  root;
        }

        vector<int> get_v(){
            return v;
        }
};

int main(){
    bst tree;
    int n;

    cin>>n;

    while(n--){
        int x;
        cin>>x;

        tree.insert(x);
    }

    tree.inorder(tree.get_root());
    vector<int> v=tree.get_v();

    int q;
    cin>>q;

    while(q--){
        int n;
        cin>>n;
        n--;

        if(n>v.size())  cout<<"Invalid"<<endl;
        else            cout<<v[n]<<endl;
    }
}