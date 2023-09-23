vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
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
