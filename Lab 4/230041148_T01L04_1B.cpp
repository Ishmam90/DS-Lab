#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &v, int ind){
    int l=2*ind+1;
    int r=2*ind+2;
    int largest=ind;

    if(l<v.size() && v[l]>v[largest])   largest=l;
    if(r<v.size() && v[r]>v[largest])   largest=r;

    if(largest!=ind){
        swap(v[largest], v[ind]);
        heapify(v, largest);
    }
}

void build_max_heap(vector<int> &v){
    for(int i=v.size()-1; i>=0; i--)  heapify(v, i);
}

void heap_sort(vector<int> &uns, vector<int> &sort){
    if(uns.empty())     return;

    swap(uns[0], uns[uns.size()-1]);
    sort.push_back(uns[uns.size()-1]);
    uns.pop_back();
    heapify(uns, 0);
    heap_sort(uns, sort);
}

int main(){
    vector<int> num, sorted;

    while(1){
        int x;
        cin>>x;

        if(x==-1)   break;
        else        num.push_back(x);
    }

    build_max_heap(num);
    cout<<"Max Heap: ";
    for(int i=0; i<num.size(); i++)     cout<<num[i]<<" ";
    cout<<endl;

    heap_sort(num, sorted);
    cout<<"Sorted: ";
    for(int i=0; i<sorted.size(); i++)  cout<<sorted[i]<<" ";
}