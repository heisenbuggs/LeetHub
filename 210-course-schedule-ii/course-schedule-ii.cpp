class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses, 0), ans;
        vector<vector<int>> list(numCourses);
        queue<int> q;

        for(int i=0; i<prerequisites.size(); i++) {
            list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ind[prerequisites[i][0]]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(ind[i]==0) q.push(i);
        }

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);

            for(auto it: list[x]) {
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};