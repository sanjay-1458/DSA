vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> v;
    for(int i=0;i<n;++i){
        bool flag=true;
        for(int j=i+1;j<n;++j){
            if(arr[i]<arr[j]){
                flag=false;
                v.push_back(arr[j]);
                break;
            }
        }
        if(flag){
            v.push_back(-1);
        }
    }
    return v
}

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> v;
    stack<long long> stk;
    for(int i=n-1;i>=0;--i){
        if(stk.empty()){
            v.push_back(-1);
            stk.push(arr[i]);
        }
        else if(arr[i]<stk.top()){
            v.push_back(stk.top());
            stk.push(arr[i]);
        }
        else{
            while(arr[i]>=stk.top()){
                stk.pop();
                if(stk.empty()){
                    break;
                }
            }
            if(stk.empty()){
                v.push_back(-1);
                stk.push(arr[i]);
            }
            else{
                v.push_back(stk.top());
                stk.push(arr[i]);
            }
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
