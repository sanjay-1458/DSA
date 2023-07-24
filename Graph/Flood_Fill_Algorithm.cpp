public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited=image;
        queue<pair<int,int>> Q;
        Q.push({sr,sc});
        visited[sr][sc]=newColor;
        int color=image[sr][sc];
        vector<int> delR={-1,0,1,0};
        vector<int> delC={0,1,0,-1};
        while(!Q.empty()){
            pair<int,int> source=Q.front();
            Q.pop();
            int row=source.first;
            int col=source.second;
            for(int l=-1;l<=1;l+=2){
                int newrow=row+l;
                if(newrow>=0 && newrow<n && image[newrow][col]==color && visited[newrow][col]!=newColor){
                    Q.push({newrow,col});
                    visited[newrow][col]=newColor;
                }
            }
            for(int l=-1;l<=1;l+=2){
                int newcol=col+l;
                if(newcol>=0 && newcol<m && image[row][newcol]==color && visited[row][newcol]!=newColor){
                    Q.push({row,newcol});
                    visited[row][newcol]=newColor;
                }
            }
            
        }
        
        return visited;
    }
