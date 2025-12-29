class Solution {
public:
    unordered_map<string, string> mp;
    unordered_map<string, bool> dp;
    
    bool dfs(string cur) {
        if(cur.size() == 1){
            return true;
        }
        
        if(dp.count(cur)){
            return dp[cur];
        }
        
        set<string> nexts = {""};
        for(int i = 0; i < cur.size() - 1; i++) {
            string key = cur.substr(i, 2);
            if(mp.find(key) == mp.end()){
                return dp[cur] = false;
            }
            set<string> tmp;
            for(string s : nexts) {
                for(char c : mp[key]) {
                    tmp.insert(s + c);
                }
            }
            nexts = tmp;
        }
        
        for(string s : nexts) {
            if(dfs(s)){
                return dp[cur] = true;
            }
        }
        
        return dp[cur] = false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string s : allowed){
            mp[s.substr(0,2)] += s[2];
        }
        return dfs(bottom);
    }
};