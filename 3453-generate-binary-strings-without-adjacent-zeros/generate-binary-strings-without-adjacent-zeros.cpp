class Solution {
public:
   void generate(int n, string& curr, vector<string>& ans) {
    if (curr.size() == n) {
        ans.push_back(curr);
        return;
    }

    // Choose 1
    curr.push_back('1');
    generate(n, curr, ans);
    curr.pop_back();              // BACKTRACK

    // Choose 0
    if (curr.empty() || curr.back() != '0') {
        curr.push_back('0');
        generate(n, curr, ans);
        curr.pop_back();          // BACKTRACK
    }
 } 
    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr = "";

        generate(n, curr, ans);

        return ans;
    }
};