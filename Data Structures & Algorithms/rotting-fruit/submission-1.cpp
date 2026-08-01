class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();

        int res = -1;
        queue<pair<int,int>> q;
        vector<vector<bool>>visited(m,vector<bool>(n,0));

        for(int i=0 ; i < m ;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2 && !visited[i][j]) {
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto[r , c] = q.front();
                q.pop();
                
                for(int k = 0 ;k<4;k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >=0 && nc >=0 && nr <m && nc < n){
                        if(grid[nr][nc] == 1 && !visited[nr][nc]){
                            visited[nr][nc] = 1;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            res++;
        }

        for(int i=0 ; i < m ;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return res == -1 ? 0 : res;
    }
};
