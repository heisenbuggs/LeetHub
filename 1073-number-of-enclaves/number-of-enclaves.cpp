class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        // {r, c}
        queue<pair<int, int>> q;
        int dr[4] = {0, 1, -1, 0};
        int dc[4] = {1, 0, 0, -1};
        
        for(int i=0; i<n; i++) {
            if(grid[i][0]==1) {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if(grid[i][m-1]==1) {
                vis[i][m-1] = 1;
                q.push({i, m-1});
            }
        }

        for(int j=0; j<m; j++) {
            if(grid[0][j]==1) {
                vis[0][j] = 1;
                q.push({0, j});
            }
            if(grid[n-1][j]==1) {
                vis[n-1][j] = 1;
                q.push({n-1, j});
            }
        }

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1) {
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};