class Solution {
public:
    int latestDayToCross(int rows, int cols, vector<vector<int>>& cells) {
        if(cols == 1){
            return 0;
        }
        if(rows == 1){
            return cols-1;
        }
        int cnt = 0;
        vector<vector<pair<int,int>>> p(rows, vector<pair<int,int>> (cols));
        for(int i =0; i<rows; i++){
            for(int j =0; j<cols; j++){
                p[i][j] = {i,j};
            }
        }
        vector<vector<bool>> vis(rows, vector<bool> (cols));

        auto findp = [&](auto&& self, pair<int,int> a) -> pair<int,int> {
            if (p[a.first][a.second] == a)
                return a;
            return p[a.first][a.second] = self(self, p[a.first][a.second]);
        };

        vector<pair<int,int>> dir = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}}; 
        for(auto it: cells){
            int r = it[0]-1;
            int c = it[1]-1;
            for(int i = 0; i<8; i++){
                int nr = r + dir[i].first;
                int nc=  c + dir[i].second;
                if(nr >=0 && nc >=0 && nr < rows && nc < cols && vis[nr][nc]){
                    auto p1 = findp(findp,{r,c});
                    auto p2 = findp(findp,{nr,nc});
                    if(p1.second == 0 && p2.second == cols-1 || p1.second == cols-1 && p2.second == 0){
                        return cnt;
                    }
                    if(p1 != p2){
                        int wt1 = min(p1.second, cols-p1.second-1);
                        int wt2 = min(p2.second, cols-p2.second-1);
                        if(wt1 <= wt2){
                            p[p2.first][p2.second] = p1;
                        }
                        else{
                            p[p1.first][p1.second] = p2;
                        }
                    }
                }
            }
            // for(int i =0; i<rows; i++){
            //     for(int j =0; j<cols; j++){
            //         cout << p[i][j].first << " " << p[i][j].second << "    ";
            //     }
            //     cout << endl;
            // }
            // cout << endl << endl;
            vis[r][c] = true;
            cnt++;
        }
        return cnt;
    }
};