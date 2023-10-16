//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long int xint;
class Solution{
    public:
    xint sumBetweenTwoKth( xint arr[], xint n, xint k1, xint k2)
    {
        // Your code goes here
        priority_queue<xint> maxHeap;
        k2--;
        xint sum=0;
        for(xint i=0;i<n;++i){
            maxHeap.push(arr[i]);
            if(maxHeap.size()>k2){
                maxHeap.pop();
            }
        }
        while(maxHeap.size()!=k1){
            sum+=maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends
