class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a' && i>0){
                if(s[i-1]=='b')
                return false;
            }
        }

        return true;

        
        
    }
};