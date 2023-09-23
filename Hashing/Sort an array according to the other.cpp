vector<int> sortA1ByA2(vector<int> arr1, int N, vector<int> arr2, int M) 
    {
        vector<int> v;
        unordered_map<int,int> mp1;
        map<int,int> mp2;
        for(int i=0;i<arr1.size();++i){
            mp1[arr1[i]]++;
            mp2[arr1[i]]=0;
        }
        for(int i=0;i<arr2.size();++i){
            int cnt=mp1[arr2[i]];
            while(cnt--){
                v.push_back(arr2[i]);
            }
            mp2[arr2[i]]=1;
        }
        for(auto x:mp2){
            if(x.second==0){
                int cnt=mp1[x.first];
                while(cnt--){
                    v.push_back(x.first);
                }
            }
        }
        return v;
    } 

vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
{
    //Your code here
    vector<int> ans;
    map<int,int> mp;;
    for(int i=0;i<N;++i){
        mp[A1[i]]++;
    }
    for(int i=0;i<M;++i){
        int el=A2[i];
        int freq=mp[A2[i]];
        while(freq--){
            ans.push_back(el);
        }
        mp.erase(el);
    }
    for(auto x:mp){
        int el=x.first;
        int freq=x.second;
        while(freq--){
            ans.push_back(el);
        }
    }
    return ans;
} 
