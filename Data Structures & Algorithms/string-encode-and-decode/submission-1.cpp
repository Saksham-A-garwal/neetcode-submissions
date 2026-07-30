#include <iostream>
#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int i=0;i < n ;i++){
            int len = strs[i].size();
            ans += to_string(len) + '#' + strs[i];
        }
        cout<<ans;
        return ans;
    }

    vector<string> decode(string s) {
        int n = s.size();
        int i = 0 , j = 0;
        vector<string> res;
        while(i < n){
            if(s[j] == '#'){
                int len = stoi(s.substr(i , j - i));
                i = j;
                string str = s.substr(i+1 , len);
                res.push_back(str);
                i += len + 1;
                j = i;
            }else{
                j++;
            }
        }
        return res;
    }   
};
