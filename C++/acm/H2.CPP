
#include <cstdlib>
#include <iostream>

using namespace std;
class Node{
public:
    Node(){};
    Node(int value){
        this->value = value;
        this->capacity_left = value;
        this->status = false;
    }
    Node(int value,Node *parent){
        this->value = value;
        this->capacity_left = value;
        this->status = false;
        this->parent = parent;
    }
    int value;
    int capacity_left;
    bool status;
    Node * parent;
};

void failed(){
    cout<<":-( Try again."<<endl;
}

void succeed(){
    cout<<":-) Matrioshka!"<<endl;
}

int tmp;
int abs_tmp;
int main(){
    while(cin>>tmp){
//        cin>>tmp;
        if(tmp >= 0){
            failed();
            continue;
        }
        abs_tmp = abs(tmp);
        Node *root = new Node(abs_tmp);
        root->parent = root;
        Node *pointer = root;
        while(!root->status){
//            cin>>tmp;
            if(!(cin>>tmp)){
                return 0;
            }
            abs_tmp = abs(tmp);
            if(tmp == pointer->value){
//                cout<<"闭合节点 ："<<pointer->value<<endl;
                pointer->status = true;
                pointer->parent->capacity_left -= pointer->value;
                pointer = pointer->parent;
//                cout<<"节点回退 ："<<pointer->value<<endl;
                if(pointer->capacity_left <= 0){
                    break;
                }
            }else if(tmp >= 0){
                break;
            }else{
                pointer = new Node(abs_tmp, pointer);
//                cout<<"创建节点 ："<<pointer->value<<endl;
            }
        }
        while(tmp != root->value){
            if(!(cin>>tmp)){
                return 0;
            }
        }
        if(root->status){
            succeed();
        }else{
            failed();
        }
    }
}
