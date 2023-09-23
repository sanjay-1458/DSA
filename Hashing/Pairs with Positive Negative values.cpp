vector<int> PosNegPair(int a[], int n) {
    vector<int> vis(n,0);
    vector<int> ans;
    vector<vector<int>> w;
    for(int i=0;i<n;++i){
        if(vis[i]==0){
            for(int j=0;j<n;++j){
                if(a[i]==-a[j] && vis[j]==0){
                    vis[j]=1;
                    w.push_back({min(a[i],a[j]),max(a[i],a[j])});
                    break;
                }
            }
            vis[i]=1;
        }
    }
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());
    for(int i=0;i<w.size();++i){
        ans.push_back(w[i][0]);
        ans.push_back(w[i][1]);
    }
    return ans;
}



vector<int> PosNegPair(int a[], int n) {
    vector<int> ans;
    unordered_map<int,int> mp;
    sort(a,a+n);
    for(int i=0;i<n;++i){
        mp[a[i]]++;
    }
    int val=INT_MIN;
    for(int i=0;i<n;++i){
        if(val!=a[i]){
            int key=a[i];
            if(key>0) break;
            if(mp.find(-key)!=mp.end()){
                int t=min(mp[key],mp[-key]);
                while(t--){
                    ans.push_back(-key);
                    ans.push_back(key);
                }
            }
        }
        val=a[i];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}A
