vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> v;
    stack<int> stk;
    for(int i=0;i<A.size();++i){
        if(stk.empty()){
            v.push_back(-1);
            stk.push(A[i]);
        }
        else if(A[i]>stk.top()){
            v.push_back(stk.top());
            stk.push(A[i]);
        }
        else{
            while(!stk.empty() && A[i]<=stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                v.push_back(-1);
                stk.push(A[i]);
            }
            else{
                v.push_back(stk.top());
                stk.push(A[i]);
            }
        }
    }
    return v;
}

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> v;
    for(int i=0;i<A.size();++i){
        bool flag=true;
        for(int j=i-1;j>=0;--j){
            if(A[i]>A[j]){
                flag=false;
                v.push_back(A[j]);
                break;
            }
        }
        if(flag){
            v.push_back(-1);
        }
    }
    return v;
}
