class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = 0;
        for(auto it: accounts){
            int sum = accumulate(it.begin(), it.end(), 0);
            mx = max(mx, sum);
        }
        return mx;
    }
};