#include <bits/stdc++.h>
using namespace std;

class Compare{
    public:
        bool operator()(pair<int,int>& below, pair<int,int>& above){
            if(below.first<above.first){
                return true;
            }
            else if(below.first == above.first && below.second>above.second){
                return true;
            }
            return false;
        }
};

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    unordered_map<int,int> ump;
	    for(int i=0;i<n;++i){
	        int x;
	        cin>>x;
	        ump[x]++;
	    }
	    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> maxHeap;
	    for(auto x:ump){
	        maxHeap.push(make_pair(x.second,x.first));
	    }
	    while(!maxHeap.empty()){
	        int k=maxHeap.top().first;
	        int val=maxHeap.top().second;
	        maxHeap.pop();
	        while(k--){
	            cout<<val<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
