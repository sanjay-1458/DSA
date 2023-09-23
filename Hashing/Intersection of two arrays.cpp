class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        unordered_set<int> s,s1;
        for(int i=0;i<n;++i){
            int key=a[i];
            if(s.find(key)==s.end()){
                s.insert(key);
            }
        }
        for(int i=0;i<m;++i){
            int key=b[i];
            if(s.find(key)!=s.end()){
                s1.insert(key);
            }
        }
        return s1.size();
    }
};




class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        unordered_set<int> s;
        int cnt=0;
        for(int i=0;i<n;++i){
            int key=a[i];
            if(s.find(key)==s.end()){
                s.insert(key);
            }
        }
        for(int i=0;i<m;++i){
            int key=b[i];
            if(s.find(key)!=s.end()){
                cnt++;
                s.erase(key);
            }
        }
        return cnt;
    }
};
