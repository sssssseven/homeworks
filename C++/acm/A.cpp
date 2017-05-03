#include <stack>
#include <queue>
#include <iostream>
using namespace std;

bool handle(int n){
    stack<int> stk;
    stk.push(0);
    int next;
    int now = 1;
    int i = 0;
    for(; i < n; ++i){
        cin>>next;
        if(next == 0){
            cout<<endl;
            return false;
        }
        while(next != now && next != stk.top() && now <= n){
            stk.push(now);
            ++now;
        }
        if(next == now){
            ++now;
        }else if(next == stk.top()){
            stk.pop();
        }else{
            break;
        }
    }
    while(++i < n){
        cin>>next;
    }
    if( stk.top() == 0 && now == (n+1) ){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    bool flag;
    while(n != 0){
        do{
            flag = handle(n);
        }while(flag);
        cin>>n;
    }
}
