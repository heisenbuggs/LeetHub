class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& vis, int sr, int sc, int color, int initCol, int dr[], int dc[], int m, int n) {
        image[sr][sc] = color;
        vis[sr][sc] = 1;

        for(int i=0; i<4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==initCol && !vis[nr][nc]) {
                dfs(image, vis, nr, nc, color, initCol, dr, dc, m, n);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initCol = image[sr][sc], m = image.size(), n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        dfs(image, vis, sr, sc, color, initCol, dr, dc, m, n);
        return image;
    }
};