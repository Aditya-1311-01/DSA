class Solution {
public:

    void fun(vector<int>& nums, int n, vector<int>& diary,
             vector<vector<int>>& ans, vector<int>& vis){

        if(diary.size() == n){
            ans.push_back(diary);
            return;
        }

        for(int i = 0; i < n; i++){

            if(vis[i]) continue;

            vis[i] = 1;
            diary.push_back(nums[i]);

            fun(nums, n, diary, ans, vis);

            diary.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> diary;
        vector<int> vis(nums.size(), 0);

        fun(nums, nums.size(), diary, ans, vis);

        return ans;
    }
};