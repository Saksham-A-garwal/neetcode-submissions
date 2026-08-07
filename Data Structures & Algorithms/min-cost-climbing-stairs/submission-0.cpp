class Solution {
public:
    int recur(int stair , vector<int>&cost , vector<int> &dp){
        if(stair == 0) return cost[0];
        if(stair == 1) return cost[1];
        if(dp[stair] != -1) return dp[stair];
        int onestep = 0 , twostep = 0;
        if(stair >=1 ) onestep = (stair == cost.size() ? 0 : cost[stair]) + recur(stair - 1,cost , dp);
        if(stair >=2) twostep = (stair == cost.size() ? 0 : cost[stair]) + recur(stair - 2,cost ,dp);

        return dp[stair] = min(onestep , twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        return recur(n,cost,dp);
    }
};
