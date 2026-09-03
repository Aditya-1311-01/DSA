class Solution {
public:
    void generate(int n, string curr, vector<string>& ans) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        // We can always add '1'
        generate(n, curr + '1', ans);

        // Add '0' only if previous character is not '0'
        if (curr.empty() || curr.back() != '0') {
            generate(n, curr + '0', ans);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr = "";

        generate(n, curr, ans);

        return ans;
    }
};