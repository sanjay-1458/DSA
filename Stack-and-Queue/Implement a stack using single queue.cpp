#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

void rev(queue<int>&q){
    if(q.empty()){
        return;
    }
    int data=q.front();
    q.pop();
    rev(q);
    q.push(data);
}
class Stack{
    queue<int> q;
    public:
    void push(int data){
        q.push(data);
    }
    void pop(){
        if(q.empty()){
            cout<<"Empty"<<endl;
        }
        else{
            rev(q);
            cout<<q.front()<<endl;
            q.pop();
            rev(q);
        }
    }
};


class Stack2{
    queue<int> q;
    public:
    void push(int data){
        q.push(data);
    }
    void pop(){
        if(q.empty()){
            cout<<"Empty"<<endl;
            return;
        }
        int size=q.size()-1;
        for(int i=0;i<size;++i){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<endl;
        q.pop();
    }
};






int main()
{
    class Stack s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.pop();
    s.pop();
    s.pop();
    
}
