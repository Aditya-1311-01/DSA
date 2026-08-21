class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<vector<double>>dp(n+1,vector<double>(m+1,0));

        for(int i=0;i<=n;i++)  // dp[0][0]=1 fill ho gya hai
        dp[i][0]=1;

        for(int j=1;j<=m;j++) // so ynha pe agr j=0 se start krenge tho dp[0][0]=0 kr dega
        dp[0][j]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][m];
        
    }
};