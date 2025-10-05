class Solution {
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited, vector<int>& dirR, vector<int>& dirC) {
        int r = heights.size(), c = heights[0].size();
        visited[i][j] = true;
        for (int d = 0; d < 4; ++d) {
            int ni = i + dirR[d], nj = j + dirC[d];
            if (ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
            if (visited[ni][nj]) continue;
            if (heights[ni][nj] < heights[i][j]) continue;
            dfs(ni, nj, heights, visited, dirR, dirC);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> pacific(r, vector<bool>(c, false)), atlantic(r, vector<bool>(c, false));
        vector<int> dirR = {0, 0, 1, -1};
        vector<int> dirC = {1, -1, 0, 0};

        for(int i = 0; i < r; ++i) { dfs(i, 0, heights, pacific, dirR, dirC); dfs(i, c - 1, heights, atlantic, dirR, dirC); }
        for(int j = 0; j < c; ++j) { dfs(0, j, heights, pacific, dirR, dirC); dfs(r - 1, j, heights, atlantic, dirR, dirC); }

        vector<vector<int>> answer;
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                if(pacific[i][j] && atlantic[i][j])
                    answer.push_back({i, j});
        return answer;
    }
};