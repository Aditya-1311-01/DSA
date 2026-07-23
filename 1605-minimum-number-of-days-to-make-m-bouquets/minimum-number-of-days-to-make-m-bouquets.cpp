class Solution {
public:
    bool possible(vector<int>& bloomDay,int day,int m,int k){
        int count=0, noofbou=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)
            count++;
            else{
                noofbou+=count/k;
                count=0;
            }
        }
        noofbou+=(count/k);
        if(noofbou>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long value=m*1LL*k*1LL;
        if(value>n) return -1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int ans=-1;
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)==true){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }

        return ans;
        
    }
};