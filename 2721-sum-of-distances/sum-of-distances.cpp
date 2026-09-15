class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) {
        int n=nums.size();
        vector<ll>arr(n,0);
        unordered_map<int,ll> indexsum;
        unordered_map<int ,ll> indexcount;

        // left to right
        for(int i=0;i<n;i++){
            ll freq=indexcount[nums[i]];
            ll sum=indexsum[nums[i]];
            arr[i]+=freq*i-sum;

            indexcount[nums[i]]+=1;
            indexsum[nums[i]]+=i;
        }
        indexsum.clear();
        indexcount.clear();
        for(int i=n-1;i>=0;i--){
            ll freq=indexcount[nums[i]];
            ll sum=indexsum[nums[i]];
            arr[i]+=sum-freq*i;

            indexcount[nums[i]]+=1;
            indexsum[nums[i]]+=i;
        }


        return arr;



        
        
    }
};