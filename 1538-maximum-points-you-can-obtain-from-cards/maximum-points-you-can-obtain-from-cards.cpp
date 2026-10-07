class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalsum=0;

        for(auto it:cardPoints){
            totalsum+=it;
        }
        int n=cardPoints.size();

        if(k==n)
        return totalsum;

        int i=0,j=0;
        int ans=0;
        int sum=0;

        while(j<n){
            sum+=cardPoints[j];

            if(j-i+1==n-k){
                ans=max(ans,totalsum-sum);

                sum-=cardPoints[i];
                i++;
            }
            j++;
        }

        return ans;
        
    }
};