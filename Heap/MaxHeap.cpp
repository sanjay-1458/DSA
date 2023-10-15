#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    
private:    

    int *arr;
    int maxSize;
    int heapSize;

public:

    MaxHeap(int maxSize);
    void maxHeapify(int i);
    
    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i){
        return 2*i+1;
    }
    int rightChild(int i){
        return 2*i+2;
    }
    int getMax(){
        return arr[0];
    }
    int currSize(){
        return heapSize;
    }
    
    int removeMax();
    void increaseKey(int i,int val);
    void deleteKey(int i);
    void insertKey(int x);
};

MaxHeap::MaxHeap(int size){
    heapSize=0;
    maxSize=size;
    arr=new int[size];
}

void MaxHeap::insertKey(int x){
    if(heapSize==maxSize){
        cout<<"\nOverflow"<<endl;
        return;
    }
    heapSize++;
    int i=heapSize-1;
    arr[i]=x;
    while(i>0 && arr[parent(i)]<arr[i]){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}

void MaxHeap::increaseKey(int i,int val){
    arr[i]=val;
    while(i>0 && arr[parent(i)]<arr[i]){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}

int MaxHeap::removeMax(){
    if(heapSize<=0){
        return INT_MIN;
    }
    if(heapSize==1){
        heapSize--;
        return arr[0];
    }
    int root=arr[0];
    arr[0]=arr[heapSize-1];
    heapSize--;
    maxHeapify(0);
    return root;
}

void MaxHeap::deleteKey(int i){
    increaseKey(i,INT_MAX);
    removeMax();
}

void MaxHeap::maxHeapify(int i){
    int largest=i;
    int left=leftChild(i);
    int right=rightChild(i);
    if(left<heapSize && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<heapSize && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(largest);
    }
}


int main()
{
    MaxHeap h(15); 
  
    int k, i, n = 6, arr[10]; 
    cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14 \n"; 
    h.insertKey(3); 
    h.insertKey(10); 
    h.insertKey(12); 
    h.insertKey(8); 
    h.insertKey(2); 
    h.insertKey(14); 

    cout << "The current size of the heap is "
         << h.currSize() << "\n"; 
  

    cout << "The current maximum element is " << h.getMax() 
         << "\n"; 
   
    h.deleteKey(2); 
  
    cout << "The current size of the heap is "
         << h.currSize() << "\n"; 
   
    h.insertKey(15); 
    h.insertKey(5); 
    cout << "The current size of the heap is "
         << h.currSize() << "\n"; 
    cout << "The current maximum element is " << h.getMax() 
         << "\n"; 
    
    return 0;
}
