class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int product=1;
        int i=0,j=0;
        int ans=2;
        while(j<n){
            int x=nums[j];

            while(gcd(product,x)>1){
                product/=nums[i++];
            }
            product*=x;
            ans=max(ans,j-i+1);
            j++;



        }

        return ans;
        
    }
};