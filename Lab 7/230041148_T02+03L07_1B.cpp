#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* right;
        Node* left;
        Node* parent;
        int height;

        Node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
            this->parent=NULL;
            this->height=1;
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

        int balance_factor(Node* r){
            if(r==NULL) return 0;

            return height(r->left)-height(r->right);
        }

        
        Node* balance_node(Node* node){
            if(node==NULL)  return node;

            update_height(node);
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

            update_height(y);
            update_height(x);

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

            update_height(y);
            update_height(x);

            return x;
        }

        Node* search_node(int key){
            Node* temp=root;

            while(temp!=NULL){
                if(key<temp->val)       temp=temp->left;
                else if(key>temp->val)  temp=temp->right;
                else return temp;
            }

            return NULL;
        }

        Node* minNode(Node* curr){
            while(curr!=NULL && curr->left!=NULL)   curr=curr->left;
            return curr;
        }

        void update_height(Node* r){
            if(!r)  return;
            r->height=1+max(height(r->left), height(r->right));
        }

        void link_parent(Node* parent, Node* old_child, Node* child){
            if(parent==NULL)                    root=child;
            else if(parent->left==old_child)    parent->left=child;
            else if(parent->right==old_child)   parent->right=child;
            if(child)   child->parent=parent;
        }

        void rebalance(Node* r){
            Node* temp=r;

            while(temp!=NULL){
                Node* after=balance_node(temp);
                temp=after->parent;
            }
        }

        void deletion(int key){
            Node* temp=search_node(key);
            if(temp==NULL)  return;

            Node* rebStart=NULL;

            if(temp->left==NULL || temp->right==NULL){
                Node* child=(temp->left) ? temp->left:temp->right;
                Node* p=temp->parent;

                link_parent(p, temp, child);
                rebStart=p;

                delete temp;
                rebalance(rebStart);
                return;
            }

            Node* y=minNode(temp->right);
            temp->val=y->val;

            Node* child=y->right;
            Node* p=y->parent;

            link_parent(p, y, child);
            rebStart=p;

            delete y;
            rebalance(rebStart);
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
        avl.inorder(avl.get_root());
        cout<<avl.get_root()->val<<endl;
    }

    while(1){
        int x;
        cin>>x;

        avl.deletion(x);
        avl.inorder(avl.get_root());
        cout<<avl.get_root()->val<<endl;
    }

}