class Solution {
public:
    int operations(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0) return j+1; //insertions
        if(j<0) return i+1; //deletions

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j])
        return dp[i][j]=operations(i-1,j-1,s1,s2,dp);

        return dp[i][j]=1+min(operations(i,j-1,s1,s2,dp),min(operations(i-1,j,s1,s2,dp),operations(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return operations(n-1,m-1,word1,word2,dp);
        
    }
};