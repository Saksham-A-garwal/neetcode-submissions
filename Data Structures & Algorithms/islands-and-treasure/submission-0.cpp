class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int,int,int>> q;

        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};

        for(int r = 0 ; r < m ; r++){
            for(int c = 0; c <n ;c++){

                if(grid[r][c] == 0){
                    vector<vector<bool>> visited(m,vector<bool>(n,0));
                    visited[r][c] = 1;
                    q.push({r,c,0});

                    while(!q.empty()){
                        auto [i , j, dist] = q.front();
                        q.pop();
                        if(grid[i][j] > dist) grid[i][j] = dist;
                        for(int k = 0 ; k<4 ;k++){
                            int nr = i + dr[k];
                            int nc = j + dc[k];
                            if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                                if(grid[nr][nc] != 0 && grid[nr][nc] != -1 && !visited[nr][nc]){
                                    visited[nr][nc] = 1;
                                    q.push({nr,nc,dist + 1});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};
