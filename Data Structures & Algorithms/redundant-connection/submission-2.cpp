class Solution {
public:
    bool dfs(vector<vector<int>> &adj , vector<bool> &visited , int node ,  int parent){
        if(visited[node]) return true;

        visited[node] = 1;

        for(auto neigh : adj[node]){
            if(neigh == parent) continue;
            if(dfs(adj , visited , neigh , node)) return true;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            vector<bool> visited(n+1,0);
            if(dfs(adj,visited,edge[0],-1)) return {edge[0] , edge[1]};
        }
        return {};
    }
};
