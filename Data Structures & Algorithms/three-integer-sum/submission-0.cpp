class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> res;
    set<vector<int>> st;

    for(int i = 0; i < n - 2; i++) {
        unordered_map<int,int> ump;

        for(int j = i + 1; j < n; j++) {
            int target = -nums[i] - nums[j];

            if(ump.find(target) != ump.end()) {
                vector<int> temp = {nums[i], target, nums[j]};

                sort(temp.begin(), temp.end());

                if(st.find(temp) == st.end()) {
                    st.insert(temp);
                    res.push_back(temp);
                }
            }

            ump[nums[j]] = j;
        }
    }

    return res;
}
};
