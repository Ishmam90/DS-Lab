#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    int n, fail=0;
    queue<int> students;
    stack<int> food;
    vector<int> temp;

    cin>>n;

    cout<<"Students: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        students.push(x);
    }

    cout<<"Food: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        temp.push_back(x);
    }

    for(int i=0; i<n; i++){
        food.push(temp.back());
        temp.pop_back();
    }

    while(!students.empty() && !food.empty()){
        if(students.front()==food.top()){
            students.pop();
            food.pop();
            fail=0;
        }

        else{
            students.push(students.front());
            students.pop();
            fail++;
        }

        if(fail==students.size())   break;
    }

    cout<<students.size();
}