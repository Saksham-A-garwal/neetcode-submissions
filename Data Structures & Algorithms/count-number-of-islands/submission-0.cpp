class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size();
        int res= 0 ;

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;

        vector<int> rows = {0,-1,0,1};
        vector<int> cols = {-1,0,1,0};

        for(int i=0 ; i<m ;i++){
            for(int j=0 ; j<n;j++){

                if(grid[i][j] == '1' && !visited[i][j]){
                    res++;
                    visited[i][j] = true;
                    q.push({i,j});

                    while(!q.empty()){
                        auto [cur_row , cur_col] = q.front();
                        q.pop();

                        for(int k = 0;k<4;k++){
                            int nrow = cur_row + rows[k];
                            int ncol = cur_col + cols[k];

                            if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n){
                                if(grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                                    visited[nrow][ncol] = 1;
                                    q.push({nrow,ncol});
                                }
                            }
                        }

                    }
                }
            }
        }

        return res;
    }
};
