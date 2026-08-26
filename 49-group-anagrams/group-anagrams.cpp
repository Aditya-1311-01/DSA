class Solution {
public:
    
    string generate(string &word){
        vector<int>freq(26,0);
        for(auto &c:word){
            freq[c-'a']++;
        }
        string new_word="";
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                new_word+=string(freq[i],i+'a');
            } 
        }

        return new_word;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        vector<vector<string>>ans;

        int n=strs.size();
        for(int i=0;i<n;i++){
            string word=strs[i];

            string new_word=generate(word);
            mp[new_word].push_back(word);
        }

        for(auto &it:mp){
            ans.push_back(it.second);
        }

        return ans;

    
    }
};