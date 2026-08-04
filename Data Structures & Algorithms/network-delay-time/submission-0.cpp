class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int weight = time[2];

            adj[u].push_back({v,weight});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n+1 , INT_MAX);

        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            auto [dis , node] = pq.top();
            pq.pop();

            for(auto &it : adj[node]){
                int neigh = it.first;
                int weight = it.second;

                if(dis + weight < dist[neigh]){
                    dist[neigh] = dis + weight;
                    pq.push({dist[neigh] , neigh});
                }
            }
        }
        
        int res = 0;
        for(int i=1 ; i<n+1;i++) res = max(res , dist[i]);

        return (res == INT_MAX ? -1 : res);

    }
};
