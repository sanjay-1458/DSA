    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for(int i=0;i<V;++i){
            if(visited[i]==0){
                int root=i;
                queue<pair<int,int>> q;
                q.push({root,-1});
                visited[root]=1;
                while(!q.empty()){
                    int frontNode=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    for(auto e:adj[frontNode]){
                        if(!visited[e]){
                            q.push({e,frontNode});
                            visited[e]=1;
                        }
                        else{
                            if(e!=parent){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
