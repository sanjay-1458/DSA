#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;


class Stack{
    int *arr;
    int top1;
    int top2;
    int size;
    public:
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }
    void push1(int data);
    void push2(int data);
    void pop1();
    void pop2();
};


void Stack::push1(int data){
    if(top1==top2-1){
        cout<<"Overflow"<<endl;
    }
    else{
        top1++;
        arr[top1]=data;
    }
}
void Stack::push2(int data){
    if(top2==top1+1){
        cout<<"Overflow"<<endl;
    }
    else{
        top2--;
        arr[top2]=data;
    }
}
void Stack::pop1(){
    if(top1==-1){
        cout<<"Underflow"<<endl;
    }
    else{
        cout<<arr[top1]<<endl;
        top1--;
    }
}
void Stack::pop2(){
    if(top2==size){
        cout<<"Underflow"<<endl;
    }
    else{
        cout<<arr[top2]<<endl;
        top2++;
    }
}

int main()
{
    class Stack s(5);
    s.push1(10);
    s.push1(100);
    s.push2(13);
    s.push2(31);
    s.push2(44);
    s.pop1();
    s.pop1();
    s.pop2();
    s.pop2();
    s.pop2();
}
