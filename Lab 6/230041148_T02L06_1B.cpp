#include<iostream>
#include<queue>
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

class bst{
    private:
        Node* root;

    public:
        bst(){
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
                if(val<temp->val)       temp=temp->left;
                else                    temp=temp->right;
            }

            newNode->parent=parent;
            if(val<parent->val)   parent->left=newNode;
            else                  parent->right=newNode;
        }

        void inorder(Node* root){
            if(root==NULL)  return;

            inorder(root->left);
            if(root->parent==NULL)  cout<<root->val<<"(NULL) ";
            else                    cout<<root->val<<"("<<root->parent->val<<") ";
            inorder(root->right);
        }

        Node* find_node(Node* current, int parent){
            if(current==NULL)           return NULL;
            if(current->val==parent)    return current;
            
            Node* left_search=find_node(current->left, parent);
            if(left_search!=NULL)   return left_search;

            return  find_node(current->right, parent);
        }

        int height(Node* root){
            if(root==NULL)  return 0;

            queue<Node*> q;
            int height=-1;

            while(!q.empty()){
                int size=q.size();
                height++;

                while(size--){
                    Node* current=q.front();
                    q.pop();

                    if(current->left!=NULL) current=current->left;
                    else                    current=current->right;
                }
            }

            return height;
        }

        void before_after(int val){
            Node* temp=root;

            Node* parent_node=find_node(temp, val);
            if(parent_node!=NULL){
                if(parent_node->left==NULL) cout<<parent_node->val<<" ";
                else{
                    Node* temp1=parent_node;
                    while(temp->left!=NULL){
                        temp=temp->left;
                    }

                    cout<<temp->val<<" ";
                }
            }

            temp=root;

            parent_node=find_node(temp, val);
            if(parent_node!=NULL){
                if(parent_node->right==NULL) cout<<parent_node->val<<" ";
                else{
                    Node* temp1=parent_node;
                    while(temp->right!=NULL){
                        temp=temp->right;
                    }

                    cout<<temp->val<<" ";
                }
            }
        }

        void max_min(){
            Node* min=root;
            Node* max=root;

            while(min->left!=NULL){
                min=min->left;
            }
            cout<<min->val<<" ";

            while(max->left!=NULL){
                max=max->left;
            }
            cout<<max->val<<endl;
        }

        Node* get_root(){
            return root;
        }
};

int main(){
    bst tree;

    while(1){
        int comm;
        cin>>comm;

        if(comm==-1)    break;
        
        else if(comm==1){
            int x;
            cin>>x;

            tree.insert(x);
            tree.inorder(tree.get_root());
        }

        else if(comm==2){
            tree.inorder(tree.get_root());
        }

        else if(comm==3){
            int x;
            cin>>x;

            Node* temp=tree.find_node(tree.get_root(), x);
            if(temp!=NULL)  cout<<"Present"<<endl;
            else            cout<<"Not Present"<<endl;
        }

        else if(comm==4){
            cout<<tree.height(tree.get_root())<<endl;
        }

        else if(comm==5){
            int x;
            cin>>x;

            tree.before_after(x);
        }

        else if(comm==6){
            tree.max_min();
        }
    }
}