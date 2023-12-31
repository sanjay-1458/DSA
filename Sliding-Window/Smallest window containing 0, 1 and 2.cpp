//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int z=1,o=1,t=1;
        int ans=INT_MAX;
        int i=0,j=0;
        int c=3;
        while(j<s.size()){
            if(s[j]=='0'){
                z--;
                if(z==0) c--;
            }
            else if(s[j]=='1'){
                o--;
                if(o==0) c--;
            }
            else{
                t--;
                if(t==0) c--;
            }
            if(c>0){
                j++;
            }
            else if(c==0){
                ans=min(ans,j-i+1);
                while(c==0){
                    if(s[i]=='0'){
                        z++;
                        if(z==1) c++;
                    }
                    else if(s[i]=='1'){
                        o++;
                        if(o==1) c++;
                    }
                    else{
                        t++;
                        if(t==1) c++;
                    }
                    ans=min(ans,j-i+1);
                    i++;
                }
                j++;
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
