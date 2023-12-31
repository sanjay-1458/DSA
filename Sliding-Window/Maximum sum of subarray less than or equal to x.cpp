//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    int i=0,j=0;
	    long long s=0,ans=0;
	    while(j<n){
	        s+=arr[j];
	        if(s<sum){
	            ans=max(ans,s);
	            j++;
	        }
	        else if(s==sum){
	            ans=s;
	            break;
	        }
	        else{
	            while(s>sum){
	                s-=arr[i];
	                i++;
	            }
	            if(s<sum){
	                ans=max(ans,s);
	            }
	            else if(s==sum){
	                ans=s;
	                break;
	            }
	            j++;
	        }
	    }
	    return ans;
	}  

};
	  



//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
