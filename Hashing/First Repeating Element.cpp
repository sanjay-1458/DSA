class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;++i){
            int key=arr[i];
            mp[key]++;
        }
        int val=-1;
        for(int i=0;i<n;++i){
            int key=arr[i];
            unordered_map<int,int>::iterator it;
            it=mp.find(key);
            if((*it).second>1){
                val=i+1;
                break;
            }
        }
        return val;
    }
};
