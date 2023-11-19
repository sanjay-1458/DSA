#include <bits/stdc++.h>
using namespace std;

int arr[100005],seg[4*100005];

void build(int low,int high,int node){
    if(low==high){
        seg[node]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);
    seg[node]=max(seg[2*node+1],seg[2*node+2]);
}

int query(int low,int high,int node,int l,int r){
    if(low>=l && high<=r){
        return seg[node];
    }
    if(high<l || low>r){
        return INT_MIN;
    }
    int mid=(low+high)/2;
    int left=query(low,mid,2*node+1,l,r);
    int right=query(mid+1,high,2*node+2,l,r);
    return max(left,right);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    while(k--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,n-1,0,l,r);
    }
    return 0;
}
