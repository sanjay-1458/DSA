long long trappingWater(int arr[], int n){
        vector<int> left,right,top(n);
        stack<int> stk;
        for(int i=0;i<n;++i){
            if(stk.empty()){
                stk.push(arr[i]);
                left.push_back(stk.top());
            }
            else if(stk.top()>=arr[i]){
                left.push_back(stk.top());
            }
            else{
                while(!stk.empty() && stk.top()<arr[i]){
                    stk.pop();
                }
                stk.push(arr[i]);
                left.push_back(stk.top());
            }
        }
        stk=stack<int>();
        for(int i=n-1;i>=0;--i){
            if(stk.empty()){
                stk.push(arr[i]);
                right.push_back(stk.top());
            }
            else if(stk.top()>=arr[i]){
                right.push_back(stk.top());
            }
            else{
                while(!stk.empty() && stk.top()<arr[i]){
                    stk.pop();
                }
                stk.push(arr[i]);
                right.push_back(stk.top());
            }
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<n;++i){
            top[i]=min(left[i],right[i])-arr[i];
            if(top[i]<0){
                top[i]=0;
            }
        }
        long long sum=0;
        for(int i=0;i<n;++i){
            sum+=top[i];
        }
        return sum;
}
