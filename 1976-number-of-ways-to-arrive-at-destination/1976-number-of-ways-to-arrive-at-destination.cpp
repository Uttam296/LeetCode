class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, long long>>> adj(n);

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            long long wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node])
                continue;

            for (auto [nbr, wt] : adj[node]) {

                long long newDist = dis + wt;

                if (newDist < dist[nbr]) {

                    dist[nbr] = newDist;
                    ways[nbr] = ways[node];

                    pq.push({newDist, nbr});
                }

                else if (newDist == dist[nbr]) {

                    ways[nbr] =
                        (ways[nbr] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};