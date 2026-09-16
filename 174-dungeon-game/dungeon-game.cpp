class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dungeon,int m,int n,vector<vector<int>>&dp){
        if(i>=m || j>=n) 
        return INT_MAX;

       if(i==m-1 && j==n-1){
         if(dungeon[i][j]>0)
         return 1;
         else 
         return abs(dungeon[i][j])+1;
       }

       if(dp[i][j]!=-1)
       return dp[i][j];

        int right=solve(i,j+1,dungeon,m,n,dp);
        int left=solve(i+1,j,dungeon,m,n,dp);

        int result=min(right,left)-dungeon[i][j];

        return dp[i][j]=(result>0) ? result : 1;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solve(0,0,dungeon,m,n,dp);
        
        
    }
};