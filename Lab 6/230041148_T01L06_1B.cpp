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

        void preorder(Node* root){
            if(root==NULL)  return;

            if(root->parent==NULL)  cout<<root->val<<"(NULL) ";
            else                    cout<<root->val<<"("<<root->parent->val<<") ";
            preorder(root->left);
            preorder(root->right);
        }

        void inorder(Node* root){
            if(root==NULL)  return;

            inorder(root->left);
            if(root->parent==NULL)  cout<<root->val<<"(NULL) ";
            else                    cout<<root->val<<"("<<root->parent->val<<") ";
            inorder(root->right);
        }

        void postorder(Node* root){
            if(root==NULL)  return;

            postorder(root->left);
            postorder(root->right);
            if(root->parent==NULL)  cout<<root->val<<"(NULL) ";
            else                    cout<<root->val<<"("<<root->parent->val<<") ";
        }

        void level_order(Node* root){
            if(root==NULL)  return;

            queue<Node*> t;
            t.push(root);
            int level=1;

            while(!t.empty()){
                int current=t.size();
                cout<<"Level: "<<level<<": ";
                
                for(int i=0; i<current; i++){
                    Node* current=t.front();
                    t.pop();

                    if(current->parent!=NULL)   cout<<current->val<<"("<<current->parent->val<<") ";
                    else                        cout<<current->val<<"(NULL) ";

                    if(current->left!=NULL)     t.push(current->left);
                    if(current->right!=NULL)    t.push(current->right);
                }

                cout<<endl;
                level++;
            }
        }

        Node* get_root(){
            return root;
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

    while(1){
        int comm;
        cin>>comm;

        if(comm==-1)    break;
        else if(comm==1)    tree.inorder(tree.get_root());
        else if(comm==2)    tree.preorder(tree.get_root());
        else if(comm==3)    tree.postorder(tree.get_root());
        else if(comm==4)    tree.level_order(tree.get_root());
    }
}