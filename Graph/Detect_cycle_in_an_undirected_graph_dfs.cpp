class Solution {
  private:
    bool dfs(vector<int> adj[],int root,int parent,vector<int> visited)      {
        visited[root]=1;
        for(auto e:adj[root]){
            if(visited[e]==0){
                if(dfs(adj,e,root,visited)==true){
                    return true;
                }
                
            }
            else if(e!=parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for(int i=0;i<V;++i){
            int root=i;
            int parent=-1;
            bool ans=dfs(adj,root,parent,visited);
            if(ans==true){
                return true;
            }
        }
        return false;
    }
};
