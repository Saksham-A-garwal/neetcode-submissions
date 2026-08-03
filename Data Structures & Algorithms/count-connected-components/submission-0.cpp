class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,0);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int>q;
        int res = 0;
        for(int i = 0; i<n ;i++){
            if(!visited[i]){
                res++;
                q.push(i);
                visited[i] = 1;

                while(!q.empty()){
                    int node= q.front();
                    q.pop();

                    for(int it : adj[node]){
                        if(!visited[it]){
                            visited[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return res;
    }
};
