class Solution {
public:
    int f(int idx, vector<int>& days, vector<int>& costs ,vector<int>&dp) {

        
        if (idx == days.size())
            return 0;

        if(dp[idx]!=-1) return dp[idx];
        int onedaypass = costs[0] + 
                         f(idx + 1, days, costs,dp);

    
        int i = idx;

        while (i < days.size() && days[i] < days[idx] + 7) {
            i++;
        }

        int sevendaypass = costs[1] +
                           f(i, days, costs,dp);

        
        i = idx;

        while (i < days.size() && days[i] < days[idx] + 30) {
            i++;
        }

        int thirtydaypass = costs[2] +
                            f(i, days, costs,dp);

        return dp[idx]=min({
            onedaypass,
            sevendaypass,
            thirtydaypass
        });
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
        return f(0, days, costs,dp);
    }
};