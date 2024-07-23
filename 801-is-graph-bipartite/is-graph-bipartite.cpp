class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, vector<int> &col, int color, int node) {
        vis[node] = 1;
        col[node] = color;

        for(auto i : graph[node]) {
            if(!vis[i]) {
                if(dfs(graph, vis, col, !color, i)==false) return false;
            }
            else if(col[i] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> col(n, -1);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(graph, vis, col, 0, i)==false) return false;
            }
        }
        return true;
    }
};