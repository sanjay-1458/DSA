bool subArrayExists(int arr[], int n)
{
    //Your code here
    vector<int> prefix(n);
    prefix[0]=arr[0];
    unordered_set<int> s;
    s.insert(arr[0]);
    for(int i=1;i<n;++i){
        prefix[i]=prefix[i-1]+arr[i];
        if(s.find(prefix[i])!=s.end() || prefix[i]==0){
            return true;
        }
        else{
            s.insert(prefix[i]);
        }
    }
    return false;
}
