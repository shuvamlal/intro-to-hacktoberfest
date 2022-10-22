class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!='1')
            return ;
        grid[i][j]='X';
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
