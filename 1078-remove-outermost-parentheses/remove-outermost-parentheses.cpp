class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count+=1;
                if(count>1)
                ans+=s[i];
            }
            else{
                count-=1;
                if(count>0)
                ans+=s[i];
            }

        }

        return ans;
        
    }
};