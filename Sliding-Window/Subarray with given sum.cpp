//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long sum=0;
        int i=0,j=0;
        int start=-1,end=-1;
        while(j<n){
            sum+=arr[j];
            if(sum<s){
                j++;
            }
            else if(sum==s){
                start=i;
                end=j;
                break;
            }
            else if(sum>s){
                while(sum>s && i<=j){
                    sum-=arr[i];
                    i++;
                }
                if(sum==s){
                    start=i;
                    end=j;
                    break;
                }
                j++;
            }
        }
        if(start==-1 || start>end){
            return {-1};
        }
        else{
            return {start+1,end+1};
        }
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
