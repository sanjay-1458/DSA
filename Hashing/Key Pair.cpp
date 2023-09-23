class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    sort(arr,arr+n);
	    int low=0,high=n-1;
	    while(low<high){
	        int sum=arr[low]+arr[high];
	        if(sum==x){
	            return true;
	        }
	        else if(sum<x){
	            low++;
	        }
	        else{
	            high--;
	        }
	    }
	    return false;
	}
};


class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;++i){
	        mp[x-arr[i]]=i;
	    }
	    for(int i=0;i<n;++i){
	        if(mp.find(arr[i])!=mp.end()){
	            if(mp[arr[i]]!=i)
	                return true;
	        }
	    }
	    return false;
	}
};


class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;++i){
	        mp[arr[i]]++;
	    }
	    for(auto it:mp){
	        int a=it.first;
	        int b=x-a,c=it.second;
	        if(a==b){
	            if(c>1){
	                return true;
	            }
	        }
	        else if(mp.find(b)!=mp.end()){
	            return true;
	        }
	    }
	    return false;
	}
};
