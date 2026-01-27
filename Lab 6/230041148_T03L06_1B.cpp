#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node* parent;

        Node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
            this->parent=NULL;
        }
};

class tree{
    private:
        Node* root;

    public:
        tree(){
            root=NULL;
        }

        void insert(int val){
            Node* newNode=new Node(val);
            Node* temp=root;
            Node* parent=NULL;

            if(temp==NULL){
                root=newNode;
                return;
            }

            while(temp!=NULL){
                parent=temp;
                if(val<temp->val)   temp=temp->left;
                else                temp=temp->right;
            }

            newNode->parent=parent;
            if(val<parent->val) parent->left=newNode;
            else                parent->right=newNode;
        }

        int lca(int left, int right){
            Node* temp=root;

            while(temp!=NULL){
                if(left<temp->val && right<temp->val)       temp=temp->left;
                else if(left>temp->val && right>temp->val)  temp=temp->right;
                else return temp->val;
            }

            return temp->val;
        }
};

int main(){
    tree bst;
    Node* find_left;
    Node* find_right;
    int n, q;

    cin>>n;

    while(n--){
        int x;
        cin>>x;

        bst.insert(x);
    }

    cin>>q;

    while(q--){
        int l, r;
        cin>>l>>r;

        cout<<bst.lca(l, r)<<endl;
    }
}