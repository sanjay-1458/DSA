vector<int> Solution::nextSmaller(vector<int> &A) {
    vector<int> v;
    for(int i=0;i<A.size();++i){
        bool flag=true;
        for(int j=i+1;j<A.size();++j){
            if(A[i]>A[j]){
                v.push_back(A[j]);
                flag=false;
                break;
            }
        }
        if(flag){
            v.push_back(-1);
        }
    }
    return v;
}

vector<int> Solution::nextSmaller(vector<int> &A) {
    vector<int> v;
    stack<int> stk;
    for(int i=A.size()-1;i>=0;--i){
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
    reverse(v.begin(),v.end());
    return v;
}
