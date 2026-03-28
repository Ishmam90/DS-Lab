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

    tree[node]=min(tree[left], tree[right]);
}

int query(int node, int begin, int end, int i, int j){
    if(i>end || j<begin)    return INT_MAX;

    if(begin>=i && end<=j)  return tree[node];

    int left=node*2;
    int right=(node*2)+1;
    int mid=(begin+end)/2;

    int p1=query(left, begin, mid, i, j);
    int p2=query(right, mid+1, end, i, j);

    return min(p1, p2);
}

int main(){
    int n, q;
    cin>>n>>q;

    arr.resize(n+1);
    tree.resize(n*4);
    
    for(int i=1; i<=n; i++) cin>>arr[i];

    init(1, 1, n);

    while(q--){
        int x, y;
        cin>>x>>y;
        
        cout<<query(1, 1, n, x, y)<<endl;
    }
}