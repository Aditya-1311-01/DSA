class Solution {
public:
    int lcs(int idx1,int idx2,string&s1,string&s2,vector<vector<int>>&dp){
        if(idx1==0 || idx2==0)  return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(s1[idx1-1]==s2[idx2-1])
        return dp[idx1][idx2]=1+lcs(idx1-1,idx2-1,s1,s2,dp);

        return dp[idx1][idx2]=max(lcs(idx1-1,idx2,s1,s2,dp),lcs(idx1,idx2-1,s1,s2,dp));
    }
    int minInsertions(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int lcp=lcs(n,n,s1,s2,dp);

        return n-lcp;
        
    }
};