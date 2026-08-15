class Solution {
public:
    bool f(string s,int idx,int count,vector<vector<int>>&dp){
        if(idx==s.size()){
            return count==0;
        }
        if(count<0) return false;

        if(dp[idx][count]!=-1)
        return dp[idx][count];

        if(s[idx]=='(') return dp[idx][count]=f(s,idx+1,count+1,dp);
        else if(s[idx]==')') return dp[idx][count]=f(s,idx+1,count-1,dp);

        return dp[idx][count]=(f(s,idx+1,count-1,dp)|| f(s,idx+1,count,dp) || f(s,idx+1,count+1,dp));

    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(s,0,0,dp);
    }
};