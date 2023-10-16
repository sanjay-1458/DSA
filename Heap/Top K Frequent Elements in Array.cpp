class Compare{
    public:
        bool operator()(pair<int,int>& below, pair<int,int>& above){
            if(below.first>above.first){
                return true;
            }
            else if(below.first == above.first && below.second>above.second){
                return true;
            }
            return false;
        }
};
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if(pq.size()==k && x.second<pq.top().first){
                continue;
            }
            pq.push(make_pair(x.second,x.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};
