class Solution {
public:
    void find(int ind, int count, string &s, string &temp,
              vector<string> &ans, int &maxLen) {

        if (ind == s.size()) {
            if (count == 0) {

                if (temp.size() > maxLen) {
                    maxLen = temp.size();
                    ans.clear();
                    ans.push_back(temp);
                }
                else if (temp.size() == maxLen) {
                    ans.push_back(temp);
                }
            }
            return;
        }

        // Take
        if (s[ind] == '(') {
            temp += s[ind];

            find(ind + 1, count + 1, s, temp, ans, maxLen);

            temp.pop_back();
        }
        else if (s[ind] == ')') {

            if (count > 0) {
                temp += s[ind];

                find(ind + 1, count - 1, s, temp, ans, maxLen);

                temp.pop_back();
            }
        }
        else {
            temp += s[ind];

            find(ind + 1, count, s, temp, ans, maxLen);

            temp.pop_back();
        }

        // Not Take
        find(ind + 1, count, s, temp, ans, maxLen);
    }

    vector<string> removeInvalidParentheses(string s) {
        string temp = "";
        vector<string> ans;
        int maxLen = 0;

        find(0, 0, s, temp, ans, maxLen);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};