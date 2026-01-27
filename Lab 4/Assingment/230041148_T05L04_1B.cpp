#include<iostream>
#include<vector>
using namespace std;

void min_heap(vector<int> &heap, int i){
    int l=2*i+1;
    int r=2*i+2;
    int lowest=i;

    if(l<heap.size() && heap[l]<heap[lowest])   lowest=l;
    if(r<heap.size() && heap[r]<heap[lowest])   lowest=r;

    if(lowest!=i){
        swap(heap[lowest], heap[i]);
        min_heap(heap, lowest);
    }
}

void build_min_heap(vector<int> &heap){
    for(int i=(heap.size()/2)-1; i>=0; i--)
        min_heap(heap, i);
}

void heap_sort(vector<int> heap){
    while(!heap.empty()){
        swap(heap[0], heap[heap.size()-1]);
        cout<<heap.back()<<" ";
        heap.pop_back();
        min_heap(heap, 0);
    }
}

int main(){
    vector<int> v;

    while(1){
        int x;
        cin>>x;

        if(x==-1)       break;
        v.push_back(x);
    }

    build_min_heap(v);
    cout<<"Min Heap: ";
    for(int i=0; i<v.size(); i++)   cout<<v[i]<<" ";
    cout<<endl;

    cout<<"Sorted: ";
    heap_sort(v);
}