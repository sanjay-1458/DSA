class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int> s;
        for(int i=0;i<n;++i){
            int key=a[i];
            if(s.find(key)==s.end()){
                s.insert(key);
            }
        }
        for(int j=0;j<m;++j){
            s.insert(b[j]);
        }
        return s.size();
    }
};
