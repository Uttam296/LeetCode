class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, 1 + dfs(ni, nj, matrix));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, dfs(i, j, matrix));

        return ans;
    }
};