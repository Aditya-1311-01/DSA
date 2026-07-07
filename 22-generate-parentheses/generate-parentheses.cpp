class Solution {
public:
    void fun(int open,int close,int &n,vector<string>&ans,string &temp){
        
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
            temp.push_back('(');
            fun(open+1,close,n,ans,temp);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            fun(open,close+1,n,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        fun(0,0,n,ans,temp);
        return ans;
        
    }
};