vector <int> calculateSpan(int price[], int n)
{
      vector<int> v;
      for(int i=0;i<n;++i){
          int c=1;
          for(int j=i-1;j>=0;--j){
              if(price[i]>=price[j]){
                  c++;
              }
              else{
                  break;
              }
          }
          v.push_back(c);
      }
      return v;
}

vector <int> calculateSpan(int price[], int n)
{
    vector<int> v;
    stack<pair<int,int>> stk;
    for(int i=0;i<n;++i){
        if(stk.empty()){
            v.push_back(-1);
            stk.push({price[i],i});
        }
        else if(stk.top().first>price[i]){
            v.push_back(stk.top().second);
            stk.push({price[i],i});
        }
        else{
            while(!stk.empty() && stk.top().first<=price[i]){
                stk.pop();
            }
            if(stk.empty()){
                v.push_back(-1);
                stk.push({price[i],i});
            }
            else{
                v.push_back(stk.top().second);
                stk.push({price[i],i});
            }
        }
    }
    for(int i=0;i<n;++i){
        v[i]=i-v[i];
    }
    return v;
}
