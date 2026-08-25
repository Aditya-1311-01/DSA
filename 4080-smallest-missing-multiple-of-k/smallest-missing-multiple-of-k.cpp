class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int temp=k;
        unordered_set<int>st(nums.begin(),nums.end());
        while(st.contains(temp)){
            temp+=k;
        }

        return temp;
        
    }
};