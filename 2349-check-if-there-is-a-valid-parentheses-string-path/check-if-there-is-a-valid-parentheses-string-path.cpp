class Solution {
public:
    bool solve(int i, int j, int count,
               vector<vector<char>>& grid, int m, int n,vector<vector<vector<int>>> &dp) {

        
        if (i >= m || j >= n)
        return false;

        
        if (grid[i][j] == '(')
        count++;
        else
        count--;

        
        if (count < 0)
        return false;

        
        if (i == m - 1 && j == n - 1)
        return count == 0;

        if(dp[i][j][count]!=-1)
        return dp[i][j][count];

        bool down = solve(i + 1, j, count, grid, m, n,dp);
        bool right = solve(i, j + 1, count, grid, m, n,dp);

        return dp[i][j][count]=down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m + n + 1, -1)));

        return solve(0, 0, 0, grid, m, n, dp);
    }
};