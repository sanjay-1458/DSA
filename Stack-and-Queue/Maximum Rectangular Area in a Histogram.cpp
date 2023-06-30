long long getMaxArea(long long arr[], int n)
{
        vector<long long> left;
        stack<pair<int,int>> stk1;
        for(int i=0;i<n;++i){
            if(stk1.empty()){
                left.push_back(-1);
                stk1.push({arr[i],i});
            }
            else if(stk1.top().first<arr[i]){
                left.push_back(stk1.top().second);
                stk1.push({arr[i],i});
            }
            else{
                while(!stk1.empty() && stk1.top().first>=arr[i]){
                    stk1.pop();
                }
                if(stk1.empty()){
                    left.push_back(-1);
                    stk1.push({arr[i],i});
                }
                else {
                    left.push_back(stk1.top().second);
                    stk1.push({arr[i],i});
                }
            }
        }
        for(int i=0;i<left.size();++i){
            if(left[i]!=-1){
                left[i]+=1;
            }
        }
        vector<long long> right;
        stack<pair<int,int>> stk2;
        for(int i=n-1;i>=0;--i){
            if(stk2.empty()){
                right.push_back(-1);
                stk2.push({arr[i],i});
            }
            else if(stk2.top().first<arr[i]){
                right.push_back(stk2.top().second);
                stk2.push({arr[i],i});
            }
            else{
                while(!stk2.empty() && stk2.top().first>=arr[i]){
                    stk2.pop();
                }
                if(stk2.empty()){
                    right.push_back(-1);
                    stk2.push({arr[i],i});
                }
                else {
                    right.push_back(stk2.top().second);
                    stk2.push({arr[i],i});
                }
            }
        }
        reverse(right.begin(),right.end());
        vector<long long> vec(n);
        for(int i=0;i<right.size();++i){
            if(right[i]!=-1){
                right[i]-=1;
            }
        }
        long long sum=0;
        for(int i=0;i<n;++i){

            long long l1=0;
            if(right[i]!=-1)
                l1=arr[i]*(right[i]-i+1);
            else{
                l1=arr[i]*(n-i);
            }
            vec[i]=l1;
        }
        for(int i=0;i<n;++i){

            long long l1=0;
            if(left[i]!=-1)
                l1=arr[i]*(i-left[i]+1);
            else{
                l1=arr[i]*(i+1);
            }
            vec[i]+=l1;
        }
        for(int i=0;i<n;++i){
            vec[i]-=arr[i];
        }
        for(int i=0;i<n;++i){
            sum=max(sum,vec[i]);
        }
        return sum;
}
