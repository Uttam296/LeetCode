class Solution {
public:
    void dfs(string email,
             unordered_map<string, vector<string>>& graph,
             unordered_set<string>& vis,
             vector<string>& emails) {

        vis.insert(email);
        emails.push_back(email);

        for (string &next : graph[email]) {
            if (!vis.count(next))
                dfs(next, graph, vis, emails);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> owner;

        for (auto &account : accounts) {

            string name = account[0];

            for (int i = 1; i < account.size(); i++)
                owner[account[i]] = name;

            for (int i = 2; i < account.size(); i++) {

                graph[account[1]].push_back(account[i]);
                graph[account[i]].push_back(account[1]);
            }

            graph[account[1]];
        }

        unordered_set<string> vis;
        vector<vector<string>> ans;

        for (auto &it : owner) {

            string email = it.first;

            if (vis.count(email))
                continue;

            vector<string> component;

            dfs(email, graph, vis, component);

            sort(component.begin(), component.end());

            component.insert(component.begin(), owner[email]);

            ans.push_back(component);
        }

        return ans;
    }
};