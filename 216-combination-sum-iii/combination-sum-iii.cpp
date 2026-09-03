class Solution {
public:
    void find(int idx,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int count,int k){
        // base condition hai
        if(count>k) return;
        if(target==0&& count==k){
            ans.push_back(ds);
            return;
        }
        if (idx >= arr.size() || target < 0) {
            return;
        }


        if(arr[idx]<=target){
            ds.push_back(arr[idx]);
            find(idx+1,target-arr[idx],arr,ans,ds,count+1,k);
            ds.pop_back();

        }
        while(idx+1<arr.size()&&arr[idx]==arr[idx+1]){
            idx++;
        }
        find(idx+1,target,arr,ans,ds,count,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>candidates={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        int count=0;
        int target=n;
        find(0,target,candidates,ans,ds,count,k);
        return ans;
        
    }
};