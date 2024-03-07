#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;


class Stack{
    int top1;
    int top2;
    int *arr;
    int mid;
    int size;
    public:
    Stack(int size){
        this->size=size;
        arr=new int[size];
        mid=size/2;
        top1=-1;
        top2=mid-1;
    }
    ~Stack(){
        delete arr;
    }
    void push1(int data);
    void push2(int data);
    int pop1();
    int pop2();
};

void Stack::push1(int data){
    if(top1==mid-1){
        cout<<"Overflow"<<endl;
        return;
    }
    top1++;
    arr[top1]=data;
}

void Stack::push2(int data){
    if(top2==size-1){
        cout<<"Overflow"<<endl;
        return;
    }
    top2++;
    arr[top2]=data;
}

int Stack::pop1(){
    if(top1==-1){
        cout<<"Underflow: "<<endl;
        return -1;
    }
    int x=arr[top1];
    top1--;
    return x;
}

int Stack::pop2(){
    if(top2==(mid-1)){
        cout<<"Overflow ";
        return -1;
    }
    int x=arr[top2];
    top2--;
    return x;
}

int main()
{
    class Stack s(10);
    s.push1(3);
    s.push1(4);
    s.push2(33);
    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;
    s.push2(32);
    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
}
