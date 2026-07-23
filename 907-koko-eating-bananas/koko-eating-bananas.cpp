class Solution {
public:
    long long fun(vector<int>&piles,int n,int speed ){
        long long h=0;
        for(int i=0;i<n;i++){
            h=h+(piles[i]/speed);
            if(piles[i]%speed!=0) h++;
        }

        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high,mid,maxi=INT_MIN;
        int ans=-1;
        int n=piles.size();
        for(int i=0;i<piles.size();i++){
            maxi=max(piles[i],maxi);
        }
        high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hour=fun(piles,n,mid);
            if(hour>h){
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }

        return ans;
        
    }
};