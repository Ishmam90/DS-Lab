#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* right;
        Node* left;
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
            cout<<r->val<<"("<<height(r)<<") ";
            inorder(r->right);
        }

        int height(Node* r){
            if(r==NULL) return -1;

            int left=height(r->left);
            int right=height(r->right);

            return max(left, right)+1;
        }

        Node* get_root(){
            return root;
        }
};

int main(){
    tree bst;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        bst.insert(x);
        bst.inorder(bst.get_root());
        cout<<endl;
    }
}