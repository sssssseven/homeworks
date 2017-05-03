#include<stack>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#define MAX_SIZE 10000000
using namespace std;

struct node{
    int size,left_size;
};

int main(){
    bool flag = true;
    stack<node> stk;
    node n{MAX_SIZE, MAX_SIZE};
    char c;
    stk.push(n);
    int tmp;
    while(cin>>tmp){
        if(flag){
            if(tmp < 0){
                n.size = -tmp;
                n.left_size = -tmp;
                stk.top().left_size += tmp;
                if(stk.top().left_size <= 0){
                    flag = false;
                }
                stk.push(n);
            }else{
                if(stk.top().size != tmp){
                    flag = false;
                }else{
                    stk.pop();
                }
            }
        }
        c = getchar();
        if(c == '\n'){
            if(flag && stk.size() == 1){
                cout<<":-) Matrioshka!"<<endl;
            }else{
                cout<<":-( Try again."<<endl;
            }
            flag = true;
            while(stk.size() > 1){
                stk.pop();
            }
            stk.top().left_size = MAX_SIZE;
        }
    }
}
