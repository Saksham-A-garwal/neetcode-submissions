class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;

       vector<vector<int>> bucket(n+1);
       for(auto &it : mp) bucket[it.second].push_back(it.first);

       vector<int> res;
       for(int i = n ; i>=0 ; i--){
            if(bucket[i].size() == 0) continue;

            while(bucket[i].size() != 0 && k != 0){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
       }

       return res;
    } 
};
