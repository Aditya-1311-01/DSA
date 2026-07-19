class Solution {
public:
    int numSub(string s) {

        const long long MOD = 1e9 + 7;
        long long ans = 0;

        for(int i = 0; i < s.size(); i++) {

            long long count = 0;

            if(s[i] == '1') {

                while(i < s.size() && s[i] == '1') {
                    count++;
                    i++;
                }

                ans = (ans + (count * (count + 1)) / 2) % MOD;
            }
        }

        return ans;
    }
};