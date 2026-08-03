class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size() , n  = heights[0].size();

        vector<vector<bool>> paci(m,vector<bool>(n,0)) , atla(m,vector<bool>(n,0));
        queue<pair<int,int>> q1 , q2;

        int dx[4] = {0,-1,0,1};
        int dy[4] = {1,0,-1,0};

        for(int i=0 ; i<m ;i++){
            paci[i][0] = 1;
            q1.push({i,0});

            atla[i][n-1] = 1;
            q2.push({i,n-1});
        }
        for(int j = 0; j<n ; j++){
            paci[0][j] = 1;
            q1.push({0,j});

            atla[m-1][j] = 1;
            q2.push({m-1,j});
        }

        while(!q1.empty()){
            auto [x, y ] = q1.front();
            q1.pop();

            for(int k=0;k<4;k++){
                int nr = x + dx[k];
                int nc = y + dy[k];

                if(nr >= 0 && nc >=0 && nr < m && nc < n){
                    if(!paci[nr][nc] && heights[nr][nc] >= heights[x][y]){
                        paci[nr][nc] = 1;
                        q1.push({nr,nc});
                    }
                }
            }
        }

        while(!q2.empty()){
            auto [x, y ] = q2.front();
            q2.pop();

            for(int k=0;k<4;k++){
                int nr = x + dx[k];
                int nc = y + dy[k];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    if(!atla[nr][nc] && heights[nr][nc] >= heights[x][y]){
                        atla[nr][nc] = 1;
                        q2.push({nr,nc});
                    }
                }
            }
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(paci[i][j] && atla[i][j]) res.push_back({i,j});
            }
        }

        
        return res;
    }
};
