vector<string> winner(string arr[],int n)
{
    unordered_map<string,int> mp;
    for(int i=0;i<n;++i){
        mp[arr[i]]++;
    }
    string ans="";
    int maxi=0;
    for(auto x:mp){
        if(maxi<x.second){
            maxi=x.second;
            ans=x.first;
        }
        else if(maxi==x.second){
            ans=min(ans,x.first);
        }
    }
    vector<string> v;
    v.push_back(ans);
    v.push_back(to_string(maxi));
    return v;
}
