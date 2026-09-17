class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);

        // PREFIX
        // prefix[i] = minimum length of a valid
        // subarray ending at or before i

        unordered_map<int, int> mp;

        int sum = 0;
        int best = INT_MAX;

        for(int i = 0; i < n; i++) {

            sum += arr[i];

            if(sum == target) {
                best = min(best, i + 1);
            }

            int rem = sum - target;

            if(mp.find(rem) != mp.end()) {

                int j = mp[rem];

                best = min(best, i - j);
            }

            prefix[i] = (best == INT_MAX ? -1 : best);

            mp[sum] = i;
        }


        // SUFFIX
        // suffix[i] = minimum length of a valid
        // subarray starting at or after i

        mp.clear();

        sum = 0;
        best = INT_MAX;

        for(int i = n - 1; i >= 0; i--) {

            sum += arr[i];

            if(sum == target) {
                best = min(best, n - i);
            }

            int rem = sum - target;

            if(mp.find(rem) != mp.end()) {

                int j = mp[rem];

                best = min(best, j - i);
            }

            suffix[i] = (best == INT_MAX ? -1 : best);

            mp[sum] = i;
        }


        // Combine prefix and suffix
        int ans = INT_MAX;

        for(int i = 0; i < n - 1; i++) {

            if(prefix[i] != -1 && suffix[i + 1] != -1) {

                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};