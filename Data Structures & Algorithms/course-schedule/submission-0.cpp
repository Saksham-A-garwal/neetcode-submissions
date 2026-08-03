class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0) ;
        vector<bool> visited(numCourses , 0);

        queue<int> q;
        for(int i=0; i<prerequisites.size() ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for(int i=0 ; i<numCourses ; i++) {
            if(!indegree[i]){
                q.push(i);
                visited[i] = 1;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int it: adj[node]){
                if(!visited[it]){
                    indegree[it]--;
                    if(indegree[it] == 0){
                        q.push(it);
                        visited[it] = 1;
                    } 
                }
            }
        }

        for(int i=0 ; i<numCourses ; i++) {
            if(!visited[i]) return false;
        }

        return true;
    }
};
