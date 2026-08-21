class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0,mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>mini)
            profit+=prices[i]-mini;

            mini=prices[i];
        }

        return profit;
        
    }
};