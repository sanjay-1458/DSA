    private:
        bool check(vector<vector<int>>& vec){
            int n=vec.size();
            int m=vec[0].size();
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    if(vec[i][j]==1){
                        return true;
                    }
                }
            }
            return false;
        }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> copy = grid;
    
        int cnt = -1;
        vector<vector<int>> visited = grid;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (visited[i][j] != 2)
                {
                    visited[i][j] = 0;
                }
            }
        }
        bool flag=true;
        
        vector<int> dr = {-1, 0, +1, 0}, dc = {0, +1, 0, -1};
        vector<vector<int>> xvisited = visited;
        while (true)
        {   
            cnt++;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (copy[i][j] == 2)
                    {
                        int row = i, col = j;
                        for (int l = 0; l < 4; ++l)
                        {
                            int nr = row + dr[l];
                            int nc = col + dc[l];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && copy[nr][nc] == 1 && visited[nr][nc] != 2)
                            {
                                flag=false;
                                visited[nr][nc] = 2;
                            }
                        }
                    }
                }
            }
    
            if (xvisited == visited)
            {
                break;
            }
            else
            {
                xvisited = visited;
                copy = visited;
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (grid[i][j] == 1 && visited[i][j] == 0)
                        {
                            copy[i][j] = 1;
                        }
                    }
                }
            }
        }
        if(check(copy)){
            return -1;
        }
        else
            return cnt;
    }
