class Solution {
public:
    int solver(vector<vector<int>> &dp, int i, int j, string s, string t){
        if(j < 0){
            return 1;
        }
        if(i < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = solver(dp,i-1,j-1,s,t) + solver(dp,i-1,j,s,t);
        }
        else{
            return dp[i][j] = solver(dp,i-1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solver(dp,n-1,m-1,s,t);
    }
};
