#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> arr;
vector<int> tree;

void init(int node, int begin, int end){
    if(begin==end){
        tree[node]=arr[begin];
        return;
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(begin+end)/2;

    init(left, begin, mid);
    init(right, mid+1, end);

    tree[node]=tree[left]+tree[right];
}

int query(int node, int begin, int end, int i, int j){
    if(i>end || j<begin)    return 0;

    if(begin>=i && end<=j)  return tree[node];

    int left=node*2;
    int right=(node*2)+1;
    int mid=(begin+end)/2;

    int p1=query(left, begin, mid, i, j);
    int p2=query(right, mid+1, end, i, j);

    return p1+p2;
}

void update(int node, int begin, int end, int index, int v){
    if(begin==end){
        arr[begin]=v;
        tree[node]=v;
        return;
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(begin+end)/2;

    if(index<=mid)  update(left, begin, mid, index, v);
    else            update(right, mid+1, end, index, v);

    tree[node]=tree[left]+tree[right];
}

int main(){
    int n, q;
    cin>>n>>q;

    arr.resize(n+1);
    tree.resize(n*4);
    
    for(int i=1; i<=n; i++) cin>>arr[i];

    init(1, 1, n);

    while(q--){
        int comm;
        cin>> comm;

        if(comm==1){
            int x;
            cin>>x;

            cout<<arr[x]<<" ";
            update(1, 1, n, x, 0);

            cout<<"(";
            for(int i=1; i<=n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<")"<<endl;
        }

        else if(comm==2){
            int x, y;
            cin>>x>>y;

            update(1, 1, n, x, arr[x]+y);
            for(int i=1; i<=n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        else if(comm==3){
            int x, y;
            cin>>x>>y;

            cout<<query(1, 1, n, x, y)<<endl;
        }
    }
}