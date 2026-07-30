class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;

        vector<pair<int,int>> temp;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
           temp.push_back({it->first,it->second});
        }

        sort(temp.begin(),temp.end(),[](pair<int,int> a , pair<int,int> b) {
            return a.second > b.second;
        });

        vector<int> res;

        for(int i=0;i<k;i++) res.push_back(temp[i].first);

        return res;
    }
};
