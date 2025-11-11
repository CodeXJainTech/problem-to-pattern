class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        dp[0][0] = 0;
        int k = strs.size();
        for(string s: strs){
            int a = 0; 
            int b = 0;
            for(char c: s){
                if(c == '0')a++;
                else b++;
            }

            for (int i = m; i >= a; i--) {
                for (int j = n; j >= b; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - a][j - b] + 1);
                }
            }
        }
        return dp[m][n];
    }
};