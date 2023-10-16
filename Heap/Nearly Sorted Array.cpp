    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        int i=0,j=0;
        vector<int> ans(n,0);
        priority_queue<int,vector<int>,greater<int>> pq;
        while(j<n){
            pq.push(arr[j]);
            if(j-i<k){
                j++;
            }
            else if(j-i==k){
                ans[i]=pq.top();
                pq.pop();
                i++;
                j++;
            }
        }
        while(pq.size()>0){
            ans[i]=pq.top();
            i++;
            pq.pop();
        }
        return ans;
    }
