class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            }
            else {
                if (s[i - 1] == '(') {
                    ans += pow(2, count - 1);
                }
                count--;
            }
        }

        return ans;
    }
};