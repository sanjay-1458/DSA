int firstNonRepeating(int arr[], int n) 
{ 
    // Complete the function
    unordered_map<int,int> mp;
    for(int i=0;i<n;++i){
        mp[arr[i]]++;
    }
    int val=0;
    for(int i=0;i<n;++i){
        auto it=mp.find(arr[i]);
        if((*it).second==1){
            val=arr[i];
            break;
        }
    }
    return val;
}
