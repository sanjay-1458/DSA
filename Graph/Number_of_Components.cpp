class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int provinces=0,nodes=V;
        vector<int> adjacencyList[nodes+1];
        for(int i=0;i<adj.size();++i){
            for(int j=0;j<=i;++j){
                int u=i+1,v=j+1;
                if(u!=v && adj[i][j]==1){
                    adjacencyList[u].push_back(v);
                    adjacencyList[v].push_back(u);
                }
            }
        }
        queue<int> Q;
        vector<bool> visited(nodes+1,false);
        for(int i=1;i<=nodes;++i){
            if(!visited[i]){
                provinces++;
                int root=i;
                Q.push(root);
                visited[root]=true;
                while(!Q.empty()){
                    int frontNode=Q.front();
                    Q.pop();
                    for(auto e:adjacencyList[frontNode]){
                        if(!visited[e]){
                            Q.push(e);
                            visited[e]=true;
                        }
                    }
                }
            }
        }
        return provinces;
    }
};
