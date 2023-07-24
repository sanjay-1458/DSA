public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid[0].size();
        int n=grid.size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int islands=0;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    islands++;
                    queue<pair<int,int>> Q;
                    pair<int,int> root={i,j};
                    Q.push(root);
                    visited[root.first][root.second]=1;
                    while(!Q.empty()){
                        int row=Q.front().first;
                        int col=Q.front().second;
                        Q.pop();
                        for( int k=-1 ;k<=1;++k){
                            for(int l=-1;l<=1;++l){
                                int newrow=row+k;
                                int newcol=col+l;
                                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]=='1' && !visited[newrow][newcol]){
                                    Q.push({newrow,newcol});
                                    visited[newrow][newcol]=1;
                                    
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        return islands;
