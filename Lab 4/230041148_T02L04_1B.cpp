#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void min_heapify(vector<int> &v, int ind){
    int l=2*ind+1;
    int r=2*ind+2;
    int largest=ind;

    if(l<v.size() && v[l]<v[largest])   largest=l;
    if(r<v.size() && v[r]<v[largest])   largest=r;

    if(largest!=ind){
        swap(v[largest], v[ind]);
        min_heapify(v, largest);
    }
}

void print(vector<int> v){
    for(int i=0; i<v.size(); i++)   cout<<v[i]<<" ";
    cout<<endl;
}

int Heap_minimum(vector<int> heap){
    return heap.front();
}

void Heap_extract_min(vector<int> &heap){
    cout<<heap[0]<<endl;
    
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    min_heapify(heap, 0);
}

void Min_heap_insert(int value, vector<int> &heap){
    heap.push_back(value);
    int child=heap.size()-1;
    int parent=(child-1)/2;

    while(child > 0  && heap[child]<heap[parent]){
        swap(heap[parent], heap[child]);
        child=parent;
        parent=(child-1)/2;
    }
}

void Heap_decrese_key(int i, int k, vector<int> &heap){
    heap[i]-=k;

    while(i>0){
        int parent = (i-1)/2;
        if(heap[i]<heap[parent]){
            swap(heap[i], heap[parent]);
            i=parent;
        }

        else        break;
    }
}

void Heap_increase_key(int i, int k, vector<int> &heap){
    heap[i]+=k;
    min_heapify(heap, i);
}

int main(){
    vector<int> num;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        else        num.push_back(x);
    }

    for(int i=(num.size()/2)-1; i>=0; i--)  min_heapify(num, i);
    cout<<"Min Heap: ";
    print(num);

    while(1){
        int x;
        cin>>x;

        if(x==-1)       break;

        else if(x==1){
            int a=Heap_minimum(num);
            cout<<a<<endl;
            print(num);
        }

        else if(x==2){
            Heap_extract_min(num);
            print(num);
        }

        else if(x==3){
            int a;
            cin>>a;

            Min_heap_insert(a, num);
            print(num);
        }

        else if(x==4){
            int a, ind;
            cin>>ind>>a;
            ind--;

            Heap_decrese_key(ind, a, num);
            min_heapify(num, ind);
            print(num);
        }

        else if(x==5){
            int a, ind;
            cin>>ind>>a;
            ind--;

            Heap_increase_key(ind, a, num);
            print(num);
        }
    }
}