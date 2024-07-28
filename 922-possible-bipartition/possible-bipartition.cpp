class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& col, int color, int n, int src) {
        vis[src] = 1;
        col[src] = color;

        for(int i=0; i<adj[src].size(); i++) {
            int it = adj[src][i];
            if(!vis[it]) {
                if(dfs(adj, vis, col, !color, n, it)==false) return false;
            }
            else if(col[it] == color) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0; i<dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> vis(n+1, 0), col(n+1);
        int color = 0;

        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                if(dfs(adj, vis, col, color, n, i)==false) return false;
            }
        }
        return true;
    }
};