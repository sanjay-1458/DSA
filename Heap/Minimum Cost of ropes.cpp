    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code hereg
        priority_queue<long long,vector<long long>,greater<long long>> pq(arr,arr+n);
        long long ans=0,sum=0;
        while(pq.size()!=1){
            long long val1=pq.top();
            pq.pop();
            long long val2=pq.top();
            pq.pop();
            sum=val1+val2;
            ans+=sum;
            pq.push(sum);
        }
        return ans;
    }
