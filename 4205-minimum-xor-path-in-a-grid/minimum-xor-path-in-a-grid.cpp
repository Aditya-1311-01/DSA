class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int f(vector<vector<int>>& grid, int i, int j, int ans) {
        if (i >= m || j >= n)
            return 1024;

        ans ^= grid[i][j];

        if (i == m - 1 && j == n - 1)
            return ans;

        // This state is not enough: ans must be included in memoization.
        if (dp[i][j][ans] != -1)
            return dp[i][j][ans];

        int right = f(grid, i, j + 1, ans);
        int down = f(grid, i + 1, j, ans);

        return dp[i][j][ans] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        return f(grid, 0, 0, 0);
    }
};