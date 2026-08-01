class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,0));
        queue<pair<int,int>> q;

        for(int j=0 ; j<n ; j++){
            if(board[0][j] == 'O'){
                visited[0][j] = 1;
                q.push({0,j});
            }

            if(board[m-1][j] == 'O'){
                visited[m-1][j] = 1;
                q.push({m-1,j});
            }
        }

        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                visited[i][0] = 1;
                q.push({i,0});
            }

            if(board[i][n-1] == 'O'){
                visited[i][n-1] = 1;
                q.push({i,n-1});
            }
        }

        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};

        while(!q.empty()){
            auto [r , c] = q.front();
            q.pop();

            for(int k = 0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >=0 && nc >=0 && nr < m && nc < n){
                    if(board[nr][nc] == 'O' && !visited[nr][nc]){
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};
