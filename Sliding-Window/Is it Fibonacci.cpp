//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> num) {
        // code here
        long long sum=0,i=num.size()-k,j=num.size()-k;
        while(j<n){
            sum+=num[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                num.push_back(sum);
                sum-=num[i];
                i++;
                j++;
            }
        }
        return num[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
