class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums,
                                                int lower, int upper) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int x : nums) {

            
            if(x < lower || x > upper)
                continue;

            
            if(lower < x) {
                ans.push_back({lower, x - 1});
            }

        
            lower = x + 1;
        }

        
        if(lower <= upper) {
            ans.push_back({lower, upper});
        }

        return ans;
    }
};