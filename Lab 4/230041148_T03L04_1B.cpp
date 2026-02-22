#include<iostream>
#include<vector>
using namespace std;

void max_heap(vector<int> &heap, int ind){
    int l=2*ind+1;
    int r=2*ind+2;
    int largest=ind;

    if(l<heap.size() && heap[l]>heap[largest])  largest=l;
    if(r<heap.size() && heap[r]>heap[largest])  largest=r;

    if(largest!=ind){
        swap(heap[largest], heap[ind]);
        max_heap(heap, largest);
    }
}

int heap_extract_max(vector<int> &heap){
    if(heap.empty())    return 0;

    int num=heap[0];
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    if(!heap.empty())   max_heap(heap, 0);

    return  num;
}

void insert_heap(vector<int> &heap, int val){
    heap.push_back(val);
    int child=heap.size()-1;
    int parent=(child-1)/2;

    while(child>0 && heap[child]>heap[parent]){
        swap(heap[parent], heap[child]);
        child=parent;
        parent=(child-1)/2;
    }
}

int main(){
    vector<int> v;

    while(1){
        int x;
        cin>>x;

        if(x==-1)       break;
        else            v.push_back(x);
    }

    for(int i=(v.size()/2)-1; i>=0; i--)    max_heap(v, i);

    while(v.size()>1){
        int x=heap_extract_max(v);
        int y=heap_extract_max(v);

        if(x!=y) insert_heap(v, x-y);
    }

    if(v.empty())   cout<<"0";
    else            cout<<v.front();
}