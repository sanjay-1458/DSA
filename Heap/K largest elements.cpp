    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;++i){
            if(pq.size()==k && arr[i]<pq.top()){
                continue;
            }
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
