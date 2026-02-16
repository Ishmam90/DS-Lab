#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void min_heap(deque<int> &heap, int ind){
    int l=2*ind+1;
    int r=2*ind+2;
    int lowest=ind;

    if(l<heap.size() && heap[l]<heap[lowest])  lowest=l;
    if(r<heap.size() && heap[r]<heap[lowest])  lowest=r;

    if(lowest!=ind){
        swap(heap[lowest], heap[ind]);
        min_heap(heap, lowest);
    }
}

void build_min_heap(deque<int> &heap){
    for(int i=(heap.size()/2)-1; i>=0; i--){
        min_heap(heap, i);
    }
}

void insert(deque<int> &heap, int val){
    heap.push_back(val);

    int child=heap.size()-1;
    int parent=(child-1)/2;

    while(heap[child]<heap[parent]){
        swap(heap[child], heap[parent]);
        child=parent;
        parent=(child-1)/2;
    }
}

int main(){
    int n;
    vector<int> v;
    deque<int> pseudo;
    cin>>n;

    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<-1<<endl;
    cout<<-1<<endl;

    pseudo.push_back(v[0]);
    pseudo.push_back(v[1]);
    pseudo.push_back(v[2]);

    build_min_heap(pseudo);

    for(int i=3; i<v.size()+1; i++){
        int mul=pseudo[0]*pseudo[1]*pseudo[2];
        cout<<mul<<endl;

        insert(pseudo, v[i]);
        pseudo.pop_front();
    }
}