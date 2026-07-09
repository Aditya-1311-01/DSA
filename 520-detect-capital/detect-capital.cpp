class Solution {
public:
    bool detectCapitalUse(string word) {
        int countcapitals=0;

        for(char &ch:word){
            if(isupper(ch))
            countcapitals++;
        }

        if(countcapitals==0)
        return true;

        if(countcapitals==word.size())
        return true;

        if(countcapitals==1 && isupper(word[0]))
        return true;

        return false;
        
    }
};