#include<iostream>
#include<vector>
using namespace std;

int mod(int a, int b){
    int r=(int)(a%b);
    if(r<0) return r+b;
    return r;
}

int hash1(int x, int size){
    return mod(x, size);
}

int hash2(int x){
    int a=7;
    int r=mod(x, a);
    int step=a-r;

    if(step==0) step=1;
    return step;
}

int insert(vector<int>& table, int x, int choice, int attempt){
    int size=table.size();
    int base=hash1(x, size);
    int step= (choice==3) ? hash2(x):1;

    for(int i=0; i<attempt; i++){
        int offset;

        if(choice==1)       offset=i;               //Linear Probing
        else if(choice==2)  offset=i*i;             //Quadratic Probing
        else                offset=i*step;          //Double Hashing

        int index=(base+((int)offset%size))%size;

        if(table[index]==-1){
            table[index]=x;
            return index;
        }
    }
    return -1;
}

int main(){
    int choice, n, q;
    cin>>choice>>n>>q;

    vector<int> table(n, -1);
    int inserted=0;
    int maxAttempt=6;

    for(int i=0; i<q; i++){
        int x;
        cin>>x;

        int base=hash1(x, n);
        int step= (choice==3) ? hash2(x):1;
        bool placed=false;

        for(int j=0; j<maxAttempt; j++){
            int offset;

            if(choice==1)       offset=j;               //Linear Probing
            else if(choice==2)  offset=j*j;             //Quadratic Probing
            else                offset=j*step;          //Double Hashing

            int index=(base+((int)offset%n))%n;

            if(table[index]==-1){
                table[index]=x;
                inserted++;
                double load=(double)inserted/n;
                cout<<"Inserted: Index- "<<index<<" (L.F = "<<load<<")"<<endl;
                placed=true;
                break;
            }
            else{
                cout<<"Collision: Index- "<<index<<endl;
            }
        }
        if(!placed){
            cout<<"Input Abandoned"<<x<<endl;
        }
    }
}