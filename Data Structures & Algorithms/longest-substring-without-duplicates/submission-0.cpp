class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ump;
        int ans = 0;
        int i = 0 , j = 0;
        while(j < s.size()){
            if(ump.find(s[j]) != ump.end()){
                int idx = ump[s[j]];
                while(i != idx + 1 ){
                    ump.erase(s[i]);
                    i++;
                }
            }
            ump[s[j]] = j;
            ans = max(ans,j - i + 1);
            j++;
        }

        return ans;
    }
};
