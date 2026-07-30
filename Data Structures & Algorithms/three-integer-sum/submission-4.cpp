class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i=0 ;i<n ;i++){
        unordered_map<int,int> ump;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                int val = - nums[i] - nums[j];
                if(ump.count(val)){
                    vector<int> temp({nums[i] , nums[j] , val});
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
                ump[nums[j]] = j;
            }
        }

        vector<vector<int>> ans(st.begin() , st.end());

        return ans;
    }
};
