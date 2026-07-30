class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> ump;
        int ans = 0;

        for(int num : nums){
            if(!ump[num]){
                ump[num] = ump[num - 1] + ump[num + 1] + 1;
                ump[num - ump[num - 1]] = ump[num];
                ump[num + ump[num + 1]] = ump[num];
                ans = max(ans , ump[num]);
            }
        }

        return ans;
    }
};
