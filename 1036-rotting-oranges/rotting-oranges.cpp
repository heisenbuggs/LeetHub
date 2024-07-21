class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), cnt=0, ans=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        // {{r, c}, t}
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                if(grid[i][j]==1) cnt++;
            }
        }

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max(ans, t);
            q.pop();

            for(int i=0; i<4; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    grid[nr][nc] = 2;
                    q.push({{nr, nc}, t+1});
                    cnt--;
                }
            }
        }

        return cnt==0 ? ans : -1;
    }
};