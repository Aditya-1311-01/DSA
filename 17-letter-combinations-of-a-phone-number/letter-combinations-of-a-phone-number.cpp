class Solution {
public:

    unordered_map<char,string> f = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void fun(string &digits, int n, int idx, string &diary,
             vector<string> &ans){

        if(idx == n){
            ans.push_back(diary);
            return;
        }

        string choice = f[digits[idx]];

        for(int j = 0; j < choice.size(); j++){

            diary.push_back(choice[j]);

            fun(digits, n, idx + 1, diary, ans);

            diary.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        vector<string> ans;

        string diary = "";

        fun(digits, digits.size(), 0, diary, ans);

        return ans;
    }
};