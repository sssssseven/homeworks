#include <stack>
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::stack;
using std::cin;

stack<string> backward;
stack<string> forward;
string start = "http://www.acm.org/";
string url;
bool handle(){
    string command;
    cin>>command;
    if(command == "VISIT"){
        cin>>url;
        backward.push(url);
        while(!forward.empty()){
            forward.pop();
        }
        cout<<url<<endl;
        return true;
    }else if(command == "BACK"){
        url = backward.top();
        if(url == start){
            cout<<"Ignored"<<endl;
        }else{
            forward.push(url);
            backward.pop();
            cout<<backward.top()<<endl;
        }
        return true;
    }else if(command == "FORWARD"){
        if(forward.empty()){
            cout<<"Ignored"<<endl;
        }else{
            url = forward.top();
            backward.push(url);
            forward.pop();
            cout<<url<<endl;
        }
        return true;
    }else if(command == "QUIT"){
        return false;
    }
}


int main(){
    backward.push(start);
    while(handle());
}
