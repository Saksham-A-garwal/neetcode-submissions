class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count_T , window;

        int i = 0 , j = 0;
        int anslength = INT_MAX;
        string ans = "";

        for(char c : t) count_T[c]++;

        int have = 0 , need = count_T.size();


        while(j < s.size()){
            window[s[j]]++;

            if(count_T.count(s[j]) && window[s[j]] == count_T[s[j]]){
                have++;
            }

            while(have == need){
                if(j - i + 1 < anslength){
                    ans = s.substr(i , j - i + 1);
                    anslength = j - i + 1;
                }

                window[s[i]]--;

                if(count_T.count(s[i]) && window[s[i]] < count_T[s[i]]) have--;

                i++;
            }
            //cout<<"INDEX: "<<j <<" ANS: "<<ans<<endl;
            j++;
        }

        return ans;

    }
};
