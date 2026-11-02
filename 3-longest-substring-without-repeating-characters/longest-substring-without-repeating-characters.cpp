
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> f;
        int n = s.size();
        int ans = 0;

        while (j < n) {
            f[s[j]]++;

            while (f[s[j]] > 1) {
                f[s[i]]--;

                if (f[s[i]] == 0) {
                    f.erase(s[i]);
                }

                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
