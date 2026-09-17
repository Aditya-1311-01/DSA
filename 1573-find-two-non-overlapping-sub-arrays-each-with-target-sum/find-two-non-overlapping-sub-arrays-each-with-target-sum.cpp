class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);

        int sum=0;
        int best=INT_MAX;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum==target){
                best=min(best,i+1);
            }

            if(mp.find(sum-target)!=mp.end()){
                best=min(best,i-mp[sum-target]);
            }
            prefix[i]=(best==INT_MAX?-1:best);

            mp[sum]=i;
        }
        mp.clear();
        best=INT_MAX;
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];

            if(sum==target){
                best=min(best,n-i);
            }
            if(mp.find(sum-target)!=mp.end()){
                best=min(best,mp[sum-target]-i);
            }
            suffix[i]=(best==INT_MAX?-1:best);

            mp[sum]=i;
        }

        int ans=INT_MAX;

        for(int i=0;i<n-1;i++){
            if(prefix[i]!=-1 && suffix[i+1]!=-1){
                ans=min(ans,prefix[i]+suffix[i+1]);
            }
        }

        return ans==INT_MAX?-1:ans;

        
    }
};