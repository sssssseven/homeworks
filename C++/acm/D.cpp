#include <queue>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main(){

    int op_index = 0,len,ops,tmp,index,to_get;
    cin>>len;
    cin>>ops;
    queue<int> inputs;
    priority_queue<int,vector<int>,greater<int> > big;
    priority_queue<int> small;
    small.push(-2000000001);
    for(int i = 0; i < len; ++i){
        cin>>tmp;
        inputs.push(tmp);
    }

    for(int i = 0; i < ops; ++i){
        cin>>index;
        while(op_index < index){
            int fron = inputs.front();
            if( fron < small.top()){
                small.push(fron);
                big.push(small.top());
                small.pop();
            }else{
                big.push(fron);
            }
            inputs.pop();
            ++op_index;
        }
        small.push(big.top());
        big.pop();
        cout<<small.top()<<endl;
    }


}
