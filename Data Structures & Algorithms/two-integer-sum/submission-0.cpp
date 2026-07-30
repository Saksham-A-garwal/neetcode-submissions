class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ump;
        int i ;
        for( i=0;i<nums.size();i++){
            if(ump.find(target - nums[i]) != ump.end()) break;
            ump[nums[i]] = i;
        }

        return {min(i  ,ump[target - nums[i]]) , max(i  ,ump[target - nums[i]])};
    }
};
