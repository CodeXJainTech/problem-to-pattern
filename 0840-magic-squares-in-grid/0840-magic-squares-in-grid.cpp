class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(isgood(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
private:
    vector<int> dir = {-1,0,1};
    bool isgood(vector<vector<int>> &grid, int r, int c){
        unordered_map<int,bool> mp;
        vector<int> rs(3,0),cs(3,0);
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                int x = grid[r+dir[i]][c+dir[j]];
                if(x > 9 || x<=0){
                    return false;
                }
                if(mp[x]){
                    return false;
                }
                cs[j] += x;
                rs[i] += x;
                mp[x] = true;
            }
        }
        set<int> st;
        int mid = grid[r][c];
        for(int i =0; i<3; i++){
            st.insert(rs[i]-mid);
            st.insert(cs[i]-mid);
        }
        st.insert(grid[r-1][c-1] + grid[r+1][c+1]);
        st.insert(grid[r-1][c+1] + grid[r+1][c-1]);
        st.insert(grid[r+1][c] + grid[r-1][c]);
        st.insert(grid[r][c+1] + grid[r][c-1]);
        if(st.size() > 1){
            return false;
        }
        return true;
    }
};