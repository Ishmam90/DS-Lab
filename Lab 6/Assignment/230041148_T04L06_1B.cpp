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

        void route(int left, int right){
            Node* temp=root;
            vector<int> v;

            while(temp!=NULL){
                if(left<temp->val && right<temp->val)       temp=temp->left;
                else if(left>temp->val && right>temp->val)  temp=temp->right;
                else break;
            }

            v.push_back(temp->val);
            Node* l=temp->left;
            Node* r=temp->right;

            while(l->val!=left && r->val!=right){
                if(left<l->val){
                    v.push_back(l->val);
                    l=l->left;
                }     
                else if(left>l->val){
                    v.push_back(l->val);
                    l=l->right;
                }

                if(right<r->val){
                    v.push_back(r->val);
                    r=r->left;
                }
                else if(right>r->val){
                    v.push_back(r->val);
                    r=r->right;
                }
            }

            int length=v.size();

            for(int i=0; i<length; i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            cout<<v.size()<<endl;
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
        int left, right;
        cin>>left>>right;

        bst.route(left, right);
        break;
    }
}