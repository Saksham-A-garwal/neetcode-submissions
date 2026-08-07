class Solution {
public:
    int recur(vector<int> &nums , vector<int>&dp , int idx){
        if(idx >= nums.size()) return 0;

        if(dp[idx] != -1) return dp[idx];
        int skip = INT_MIN , take = INT_MIN;
        skip = recur(nums , dp , idx + 1);
        take = nums[idx] + recur(nums , dp , idx + 2);

        return dp[idx] = max(take , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        return recur(nums,dp,0);
    }
};
