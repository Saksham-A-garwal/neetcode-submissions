class Solution {
public:
    int diffchar(string s1 , string s2){
        int diff = 0;
        for(int i=0 ; i<s1.size() ;i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string , int>> q;
        vector<bool> visited(n,0);

        q.push({beginWord , 1});

        while(!q.empty()){
            auto [word , dist] = q.front();
            q.pop();

            if(word == endWord) return dist;

            for(int i=0 ;i<n ;i++){
                if(!visited[i] && diffchar(wordList[i] , word) == 1){
                    visited[i] = 1;
                    q.push({wordList[i] , dist + 1});
                }
            }
        }

        return 0;
    }
};
