bool comp(string&s1,string&s2){
        return s1.size()<s2.size();
    }

class Solution {
public:
    
    bool checkpossible(string s1,string s2){
        if(s1.size()!=1+s2.size())
        return false;

        int first=0,second=0;
        while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size())
        return true;
        else 
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkpossible(words[i],words[prev])&& dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                }
                
            }
            maxi=max(dp[i],maxi);
        }

        return maxi;

    }
};