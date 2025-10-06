class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int elevation = current.first;
            int x = current.second.first;
            int y = current.second.second;
            
            if (x == n - 1 && y == n - 1) {
                return elevation;
            }
            
            for (auto& direction : directions) {
                int nx = x + direction[0];
                int ny = y + direction[1];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({max(elevation, grid[nx][ny]), {nx, ny}});
                }
            }
        }     
        return -1;
    }
};