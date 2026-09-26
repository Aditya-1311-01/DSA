class Solution {
public:
    int solve(int ind,int sum,int target,vector<int>&arr){
        if(ind==arr.size()){
            if(sum==target)
            return 1;
            else
            return 0;
        }
        int pos=solve(ind+1,sum+arr[ind],target,arr);
        int neg=solve(ind+1,sum-arr[ind],target,arr);

        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        return solve(0,0,target,nums);

        
    }
};