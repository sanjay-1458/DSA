#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1,right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void maxheap(int arr[],int n){
    for(int i=n/2-1;i>=0;--i){
        heapify(arr,n,i);
    }
}

void heapsort(int arr[],int n){
    maxheap(arr,n);
    for(int i=n-1;i>=0;--i){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={10,12,33,1,0,984,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    heapsort(arr,n);
    print(arr,n);
    return 0;
}


class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
          int largest=i;
          int left=2*i+1;
          int right=2*i+2;
          if(left<n && arr[left]>arr[largest]){
              largest=left;
          }
          if(right<n && arr[right]>arr[largest]){
              largest=right;
          }
          if(largest!=i){
              swap(arr[i],arr[largest]);
              heapify(arr,n,largest);
          }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=n/2-1;i>=0;--i){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i=n-1;i>=0;--i){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};
