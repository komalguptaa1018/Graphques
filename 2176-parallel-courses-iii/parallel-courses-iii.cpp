class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Create adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1); // 0-based indexing
        }

        // Compute in-degrees
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indeg[adj[i][j]]++;
            }
        }

        // Topological sort (Kahn's algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> CourseTime(n, 0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < adj[node].size(); i++) {
                int next = adj[node][i];
                indeg[next]--;
                if (indeg[next] == 0) {
                    q.push(next);
                }
                CourseTime[next] = max(CourseTime[next], CourseTime[node] + time[node]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, CourseTime[i] + time[i]);
        }

        return ans;
    }
};
