#include <iostream>
#include <queue>

/*
* Structure a Huffman Tree
*/


int handle(){
    int n;
    std::cin>>n;
    if( n < 2){
        std::cout<<0<<std::endl;
        return 0;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int> > s;
    int input;
    for(int i = 0; i < n; ++i){
        std::cin>>input;
        s.push(input);
    }
    long long total = 0;
    int tmp;
    while(s.size() > 2){
        tmp = s.top();
        s.pop();
        tmp += s.top();
        total += tmp;
        s.push(tmp);
        s.pop();
    }
    total += s.top();
    s.pop();
    total += s.top();
    std::cout<<total<<std::endl;
}

int main(){

    int n;
    std::cin>>n;
    for(int i = 0; i < n; ++i){
        handle();
    }

}


