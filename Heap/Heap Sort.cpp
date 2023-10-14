#include <iostream>

using namespace std;

void swap1(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void heapify(int n,int i,int arr[]){
    int largest=i;
    int left=2*i+1,right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap1(&arr[largest],&arr[i]);
        heapify(n,largest,arr);
    }
}

void maxheap(int n,int arr[]){
    for(int i=n/2-1;i>=0;--i){
        heapify(n,i,arr);
    }
}

void heapsort(int n,int arr[]){
    maxheap(n,arr);
    for(int i=n-1;i>=0;--i){
        swap1(&arr[0],&arr[i]);
        heapify(i,0,arr);
    }
}

void print(int n,int arr[]){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={33,221,333,14,10,9,8,2,22,1000};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before heap sort"<<endl;
    print(n,arr);
    heapsort(n,arr);
    cout<<"After heap sort"<<endl;
    print(n,arr);
    return 0;
}
