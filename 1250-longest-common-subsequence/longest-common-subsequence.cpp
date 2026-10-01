class Solution {
public: 
    int solve(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
        if(i==0 || j==0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(text1[i-1]==text2[j-1]){
            return dp[i][j]=1+solve(i-1,j-1,text1,text2,dp);
        }

        return dp[i][j]=max(solve(i-1,j,text1,text2,dp),solve(i,j-1,text1,text2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return solve(m,n,text1,text2,dp);

       
        
    }
};