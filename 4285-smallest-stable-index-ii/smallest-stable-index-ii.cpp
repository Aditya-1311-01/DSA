class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minno(n,0);
        vector<int>maxno(n,0);
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max=nums[i];
            }
            maxno[i]=max;
        }
        int min=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<min){
                min=nums[i];
            }
            minno[i]=min;
        }
        int index=INT_MAX;
        for(int i=0;i<n;i++){
            if(maxno[i]-minno[i]<=k){
                return i;
            }
        }

        return -1;
        
    }
};