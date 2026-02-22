#include <iostream>
#include <string>
using namespace std;

class Stack {
    int* arr;
    int topIndex;
    int capacity;

public:
    Stack(int n){
        capacity=n;
        arr=new int[n];
        topIndex=-1;
    }

    bool isFull(){
        return topIndex==capacity-1;
    }

    bool isEmpty(){
        return topIndex==-1;
    }

    void push(int x){
        if (isFull())   cout << "Overflow !!!" << endl;
        else            arr[++topIndex] = x;
    }

    void pop(){
        if (isEmpty())  cout << "Underflow !!!" << endl;
        else            topIndex--;
    }

    int top(){ 
        return isEmpty() ? 0 : arr[topIndex]; 
    }
    int size(){ 
        return topIndex + 1; 
    }

    void printStatus(){
        cout<<"Size : "<<size()<<"\n";
        cout<<"Stack elements : ";
        if(isEmpty())           cout << "";
            else{
            for(int i=0; i<=topIndex; i++){
                cout << arr[i];
                if(i!=topIndex)  cout<< " ";
            }
        }
        cout<<"\n";

        cout<<"Top Element : "<<top()<<"\n";
        cout<<"isFull : "<<(isFull() ? "True" : "False")<<"\n";
        cout<<"isEmpty : "<<(isEmpty() ? "True" : "False")<<"\n\n";
    }
};

int main(){
    int n;
    cin>>n;
    cin.ignore();

    Stack st(n);

    while (true){
        string line;
        getline(cin, line);

        if (line=="/") break;

        if (line[0]=='+'){
            int x;
            sscanf(line.c_str(), "+ %d", &x);
            st.push(x);
        } 
        
        else if (line[0]=='-'){
            st.pop();
        }

        st.printStatus();
    }
}