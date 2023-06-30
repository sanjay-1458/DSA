class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int third=INT_MIN;
        stack<int> stk;
        for(int i=n-1;i>=0;--i){
            if(nums[i]<third){
                return true;
            }
            if(stk.empty()){
                stk.push(nums[i]);
            }
            else if(stk.top()<nums[i]){
                while(!stk.empty() && stk.top()<nums[i]){
                    third=stk.top();
                    stk.pop();
                }
                stk.push(nums[i]);
            }
            else{
                stk.push(nums[i]);
            }
        }
        return false;
    }
};
