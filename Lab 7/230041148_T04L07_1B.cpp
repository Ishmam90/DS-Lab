#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* right;
        Node* left;
        Node* parent;
        int height;
        int size;

        Node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
            this->parent=NULL;
            this->height=1;
            this->size=1;
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

            temp=newNode->parent;
            while(temp!=NULL){
                temp->height=1+max(height(temp->left), height(temp->right));
                balance_node(temp);
                temp=temp->parent;
            }
        }

        void inorder(Node* r){
            if(r==NULL) return;

            inorder(r->left);
            cout<<r->val<<"("<<balance_factor(r)<<") ";
            inorder(r->right);
        }

        int height(Node* r){
            if(r==NULL) return 0;

            return r->height;
        }

        int size(Node* r){
            if(r==NULL) return 0;

            return r->size;
        }

        int balance_factor(Node* r){
            if(r==NULL) return 0;

            return height(r->left)-height(r->right);
        }

        
        Node* balance_node(Node* node){
            if(node==NULL)  return node;

            update(node);
            int balance=balance_factor(node);
            
            if(balance>1){
                if(balance_factor(node->left)<0){
                    left_rotate(node->left);
                }
                return right_rotate(node);
            }
            
            if(balance<-1){
                if(balance_factor(node->right)>0){
                    right_rotate(node->right);
                }
                return left_rotate(node);
            }
            
            return node;
        }
        
        Node* right_rotate(Node* y){
            Node* x=y->left;
            Node* temp=x->right;
            Node* p=y->parent;

            x->right=y;
            y->left=temp;

            x->parent=p;
            y->parent=x;
            if(temp)    temp->parent=y;

            if(p==NULL)         root=x;
            else if(p->left==y) p->left=x;
            else                p->right=x;

            update(y);
            update(x);

            return x;
        }
        
        Node* left_rotate(Node* y){
            Node* x=y->right;
            Node* temp=x->left;
            Node* p=y->parent;

            x->left=y;
            y->right=temp;

            x->parent=p;
            y->parent=x;
            if(temp)    temp->parent=y;

            if(p==NULL)         root=x;
            else if(p->left==y) p->left=x;
            else                p->right=x;

            update(y);
            update(x);

            return x;
        }
        
        void update(Node* n){
            if(n==NULL) return;
            n->height=1+max(height(n->left), height(n->right));
            n->size=1+size(n->left)+size(n->right);
        }

        int lower_count(int x){
            int count=0;
            Node* temp=root;

            while(temp!=NULL){
                if(x<=temp->val)    temp=temp->left;
                else{
                    count+=1+size(temp->left);
                    temp=temp->right;
                }
            }

            return count;
        }

        Node* get_root(){
            return root;
        }
};

int main(){
    tree avl;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        avl.insert(x);
    }

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        cout<<avl.lower_count(x)<<endl;
    }
}