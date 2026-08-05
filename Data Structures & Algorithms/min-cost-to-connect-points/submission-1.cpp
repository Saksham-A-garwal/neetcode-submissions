class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> wt(n,vector<int>(n,0));

        for(int i=0;i<points.size() ;i++){
            for(int j=0;j<points.size();j++){
                wt[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }

        vector<bool> visited(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});

        int ans = 0;
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if (visited[node]) continue;

            ans += dist;
            visited[node] = 1;

            for (int i = 0; i < n; i++) {
                if(!visited[i])  pq.push({wt[node][i] , i});
            }
        }

        return ans;
    }
};
