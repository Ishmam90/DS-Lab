#include<iostream>
#include<vector>
using namespace std;

class wizard{
    public:    
        string name;
        int age;
        string house;
};

void max_heap(vector<wizard> &heap, int ind){
    int l=2*ind+1;
    int r=2*ind+2;
    int largest=ind;

    if(l<heap.size() && heap[l].age>heap[largest].age)  largest=l;
    if(r<heap.size() && heap[r].age>heap[largest].age)  largest=r;

    if(largest!=ind){
        swap(heap[largest], heap[ind]);
        max_heap(heap, largest);
    }
}

void max_heap_insert(wizard value, vector<wizard> &heap){
    heap.push_back(value);
    int child=heap.size()-1;
    int parent=(child-1)/2;

    while(child > 0  && heap[child].age>heap[parent].age){
        swap(heap[parent], heap[child]);
        child=parent;
        parent=(child-1)/2;
    }
}

void heap_extract_max(vector<wizard> &heap){
    cout<<"Name: " <<heap[0].name<<", Age: "<<heap[0].age<<", House: "<<heap[0].house<<endl;
    
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    if(!heap.empty())   max_heap(heap, 0);
}

int main(){
    vector<wizard> wiz;

    while(1){
        char c;
        cin>>c;

        if(c=='X')      break;
        else if(c=='I'){
            wizard w;

            cin>>ws;
            getline(cin, w.name);
            cin>>w.age;
            cin>>w.house;

            max_heap_insert(w, wiz);
        }

        else if(c=='S') heap_extract_max(wiz);
    }
}