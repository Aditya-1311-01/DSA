class Solution {
public:

    int findmaximumcherry(int r1, int c1, int r2, int n,
                          vector<vector<int>>& grid,
                          vector<vector<vector<int>>>& dp) {

        // c2 can be calculated
        int c2 = r1 + c1 - r2;

        // Out of bounds
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n)
            return INT_MIN;

        // Obstacle
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        // Destination
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        // Already calculated
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = grid[r1][c1];

        // Same cell -> count only once
        if(r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        // Both Down
        int DD = findmaximumcherry(
            r1+1, c1, r2+1, n, grid, dp
        );

        // First Down, Second Right
        int DR = findmaximumcherry(
            r1+1, c1, r2, n, grid, dp
        );

        // First Right, Second Down
        int RD = findmaximumcherry(
            r1, c1+1, r2+1, n, grid, dp
        );

        // Both Right
        int RR = findmaximumcherry(
            r1, c1+1, r2, n, grid, dp
        );

        int pick = max({DD, DR, RD, RR});

        if(pick == INT_MIN)
            return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = cherries + pick;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        );

        int ans = findmaximumcherry(
            0, 0, 0, n, grid, dp
        );

        return max(0, ans);
    }
};