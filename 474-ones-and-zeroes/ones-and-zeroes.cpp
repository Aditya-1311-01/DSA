class Solution {
public:
    int solve(vector<pair<int,int>>&count,int m,int n,int ind,vector<vector<vector<int>>>&dp){
        if(ind>=count.size() ||(m==0 && n==0))
        return 0;

        if(dp[ind][m][n]!=-1)
        return dp[ind][m][n];

        int take=0;
        if(count[ind].first<=m && count[ind].second<=n){
            take=1 + solve(count, m-count[ind].first, n-count[ind].second ,ind+1,dp);
        }

        int  nottake=solve(count,m,n,ind+1,dp);

        return dp[ind][m][n]=max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();

        vector<pair<int,int>>count(size);

        vector<vector<vector<int>>>dp(size+1, vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        for(int i=0;i<size;i++){
            int zeros=0;
            int ones=0;

            for(const char &ch:strs[i]){
                if(ch=='0')
                zeros++;
                else
                ones++;
            }
            count[i]={zeros,ones};
        }

        return solve(count,m,n,0,dp);
        
    }
};