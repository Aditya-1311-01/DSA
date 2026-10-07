class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return true;

        return false;
    }
    int maxVowels(string s, int k) {
       int n=s.size();
       int i=0,j=0;
       int countvowel=0;
       int ans=0;

       while(j<n){
        if(isvowel(s[j])){
            countvowel++;
        }
        if(j-i+1==k){
            ans=max(countvowel,ans);

            if(isvowel(s[i]))
            countvowel--;

            i++;
            
        }
        j++;
       } 

       return ans;
        
    }
};