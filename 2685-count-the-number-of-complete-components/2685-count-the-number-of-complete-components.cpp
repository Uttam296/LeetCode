class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            vector<int> component;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                component.push_back(node);

                for (int nei : adj[node]) {
                    if (!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            int sz = component.size();
            bool complete = true;

            for (int node : component) {
                if (adj[node].size() != sz - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete)
                ans++;
        }

        return ans;
    }
};