#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;

    while(x--){
        stack<int> n;
        string inp;
        int total=0;

        cin>>inp;

        int length=inp.size();

        for(int i=0; i<length; i++){
            if(inp[i]>='0' && inp[i]<='9')  n.push(inp[i]-'0');
            
            else if(inp[i]=='+'){
                    int top1=n.top();
                    n.pop();
                    int top2=n.top();
                    n.pop();

                    total=top1+top2;
                    n.push(total);
            }

            else if(inp[i]=='-'){
                    int top1=n.top();
                    n.pop();
                    int top2=n.top();
                    n.pop();

                    total=top2-top1;
                    n.push(total);
            }

            else if(inp[i]=='*'){
                    int top1=n.top();
                    n.pop();
                    int top2=n.top();
                    n.pop();

                    total=top1*top2;
                    n.push(total);
            }

            else if(inp[i]=='+'){
                    int top1=n.top();
                    n.pop();
                    int top2=n.top();
                    n.pop();

                    total=top2/top1;
                    n.push(total);
            }
        }

        cout<<n.top()<<endl;
    }
}