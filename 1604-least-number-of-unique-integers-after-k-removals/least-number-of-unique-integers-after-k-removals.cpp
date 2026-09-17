class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int x : nums)
            mp[x]++;

        vector<int> freq;

        for(auto it : mp)
            freq.push_back(it.second);

        sort(freq.begin(), freq.end());

        int ans = freq.size();

        for(int x : freq){
            if(k >= x){
                k -= x;
                ans--;
            }
            else
                break;
        }

        return ans;
    }
};