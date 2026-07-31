class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> time;
        stack<float> st;
        map<float,float> mp;

        for(int i=0 ; i<position.size() ;i++) mp[position[i]] = speed[i];

        for(auto it: mp) time.push_back((target - it.first) / it.second);
        
        for(int i = time.size()-1 ;i>=0 ;i--){
            if(st.empty() ||  st.top() < time[i]) st.push(time[i]);
        }
        return st.size();
    }   
};
