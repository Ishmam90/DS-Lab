#include<iostream>
#include<stack>
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
        Node* ad;

    public:
        tree(){
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
            cout<<r->val<<" ";
            inorder(r->right);
        }

        Node* get_root(){
            return root;
        }

        void print(int val){
            Node* temp=root;
            stack<int> st;

            if(temp==NULL){
                cout<<"NULL"<<endl;
                return;
            }

            while(temp->val!=val){
                st.push(temp->val);
                if(val<temp->val)   temp=temp->left;
                else                temp=temp->right;
            }

            if(temp==NULL){
                cout<<"NULL"<<endl;
                ad=NULL;
                return;
            } 

            ad=temp;

            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }

            cout<<endl;
        }

        Node* get_ad(){
            return ad;
        }
};

int main(){
    tree bst;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        bst.insert(x);
    }

    bst.inorder(bst.get_root());
    cout<<endl;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        bst.print(x);
        bst.inorder(bst.get_ad());
        cout<<endl;
    }
}