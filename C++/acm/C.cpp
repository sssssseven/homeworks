#include <set>
#include <iostream>
#include <string>
using std::set;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int handle(int n, string str){
    set<char> customers;
    int left = 0;
    char next;
    for(int i = 0; i < str.size(); ++i){
        next = str[i];
         if(customers.find(next) != customers.end()){
            customers.erase(next);
        }else{
            if(customers.size() >= n){
//                cout<<"customer "<<next<<" walked away"<<endl;
                left++;
            }else{
                customers.insert(next);
            }
        }
    }
    return left/2;
}

int main(){

    int n;
    int result;
    string str;
    cin>>n;
    while(n != 0){
        cin>>str;
        result = handle(n,str);
        if(result == 0){
            cout<<"All customers tanned successfully."<<endl;
        }else{
            cout<<result<<" customer(s) walked away."<<endl;
        }
        cin>>n;
    }
}
