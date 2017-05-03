#include <queue>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool push_from_input(bool last_insert_big,priority_queue<int> & small ,priority_queue<int, vector<int>, greater<int> > & big ){
    int tmp;
    cin>>tmp;
    if(last_insert_big){
        if( !big.empty() && big.top() < tmp){
            big.push(tmp);
            tmp = big.top();
            big.pop();
        }
        small.push(tmp);
    }else{
        if(!small.empty() && small.top() > tmp){
            small.push(tmp);
            tmp = small.top();
            small.pop();
        }
        big.push(tmp);
    }
    return !last_insert_big;
}

int main(){
    int test_count, init_size, ops_count;
    string command;
    cin>>test_count;
    for(int i = 0; i < test_count; ++i){
        bool last_insert_big = true;
        priority_queue<int, vector<int>, greater<int> > big;
        priority_queue<int> small;
        cin>>init_size;
        for(int j = 0; j < init_size; ++j){
            last_insert_big = push_from_input(last_insert_big,small,big);
        }
        cin>>ops_count;
        for(int j = 0; j < ops_count; ++j){
            cin>>command;
            if(command == "add"){
                last_insert_big = push_from_input(last_insert_big,small,big);
            }else if(command == "mid"){
                cout<<small.top()<<endl;
            }
        }
    }
}
