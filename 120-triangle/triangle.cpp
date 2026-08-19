class Solution {
public:
    int f(int i, int j, int n,
          vector<vector<int>>& arr,
          vector<vector<int>>& dp) {

        // Last row
        if(i == n - 1)
            return arr[n - 1][j];

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        int down = arr[i][j] + f(i + 1, j, n, arr, dp);

        int diagonal = arr[i][j] +
                       f(i + 1, j + 1, n, arr, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        int dp[n][n];
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                int down=triangle[i][j]+dp[i+1][j];
                dp[i][j]=min(diagonal,down);
            }
        }

        return dp[0][0];
    }
};