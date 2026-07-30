#include <bits/stdc++.h>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;

        int i = 0 ;
        vector<int> res;
        for(int j=0 ; j<nums.size() ; j++){
            pq.push({nums[j] , j});

            if(j >= k - 1){
                while(!pq.empty() && pq.top().second < i) pq.pop();
                res.push_back(pq.top().first);
                i++;
            }
        }

        return res;
    }

};
