//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int n)
    {
        int ans=0,sum=0;
        map<int,int> mp;
        for(int i=0;i<n;++i){
            if(arr[i]==0){
                sum+=1;
            }
            else{
                sum+=-1;
            }
            if(sum==0){
                ans=max(ans,i+1);
            }
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};
// https://media.geeksforgeeks.org/img-practice/prod/courses/1/Web/Content/3-90-fab-v3_1703855049.svg

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
