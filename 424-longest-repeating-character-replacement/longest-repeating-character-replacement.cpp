class Solution {
public:

    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>f(26,0);
        int left=0,right=0;
        int maxfreq=0;
        int ans=0;

        while(right<n){
            f[s[right]-'A']++;
            maxfreq=*max_element(f.begin(),f.end());
            int len=right-left+1;
            int diff=len-maxfreq;

            while(diff>k){
                f[s[left]-'A']--;
                left++;
                maxfreq=*max_element(f.begin(),f.end());
                len=right-left+1;
                diff=len-maxfreq;

            }

            ans=max(ans,right-left+1);
            right++;
            

            
        }

        return  ans;
    }
};