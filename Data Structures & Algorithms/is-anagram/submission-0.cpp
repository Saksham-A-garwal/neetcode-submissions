class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ump;

        for(int ch : s) ump[ch]++;
        for(int ch : t){
            if(ump.find(ch) == ump.end()) return false;
            ump[ch]--;
            if(ump[ch] == 0) ump.erase(ch);
        }

        return ump.size() == 0;
    }
};
