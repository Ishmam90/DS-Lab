#include<iostream>
#include<vector>
using namespace std;

void max_heap(vector<int> &heap, int i){
    int l=2*i+1;
    int r=2*i+2;
    int lowest=i;

    if(l<heap.size() && heap[l]>heap[lowest])  lowest=l;
    if(r<heap.size() && heap[r]>heap[lowest])  lowest=r;

    if(lowest!=i){
        swap(heap[i], heap[lowest]);
        max_heap(heap, lowest);
    }
}

void build_max_heap(vector<int> &heap){
    for(int i=(heap.size()/2)-1; i>=0; i--)
        max_heap(heap, i);
}

int heap_extract_max(vector<int> &heap){
    int num=heap.front();
    
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    max_heap(heap, 0);

    return  num;
}

void max_heap_insert(vector<int> &heap, int value){
    heap.push_back(value);

    int child=heap.size()-1;
    int parent=(child-1)/2;

    while(heap[child]>heap[parent]){
        swap(heap[child], heap[parent]);
        child=parent;
        parent=(child-1)/2;
    }
}

void heap_decrease_key(vector<int> &heap, int i, int k){
    i--;
    heap[i]-=k;
    max_heap(heap, i);
}

void heap_increase_key(vector<int> &heap, int i, int k){
    i--;
    heap[i]+=k;
    int child=i;
    int parent=(child-1)/2;

    while(heap[child]>heap[parent]){
        swap(heap[child], heap[parent]);
        child=parent;
        parent=(child-1)/2;
    }
}

void print(vector<int> heap){
    for(int i=0; i<heap.size(); i++)
        cout<<heap[i]<<" ";

    cout<<endl;
}

int heap_maximum(vector<int> heap){
    return  heap.front();
}

int main(){
    vector<int> v;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        v.push_back(x);
    }

    cout<<"Max Heap: ";
    build_max_heap(v);
    print(v);

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;

        else if(x==1){
            int num=heap_maximum(v);
            cout<<num<<endl;
            print(v);
        }

        else if(x==2){
            int num=heap_extract_max(v);
            cout<<num<<endl;
            print(v);
        }

        else if(x==3){
            int a;
            cin>>a;

            max_heap_insert(v, a);
            print(v);
        }

        else if(x==4){
            int i, k;
            cin>>i>>k;

            heap_decrease_key(v, i, k);
            print(v);
        }

        else if(x==5){
            int i, k;
            cin>>i>>k;

            heap_increase_key(v, i, k);
            print(v);
        }
    }
}