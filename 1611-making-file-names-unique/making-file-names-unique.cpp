class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> mp;
        vector<string> ans;

        for(string name : names) {

            if(mp.find(name) == mp.end()) {
                // First time
                ans.push_back(name);
                mp[name] = 1;
            }
            else {
                int k = mp[name];

                string newName = name + "(" + to_string(k) + ")";

                while(mp.find(newName) != mp.end()) {
                    k++;
                    newName = name + "(" + to_string(k) + ")";
                }

                ans.push_back(newName);

                mp[name] = k + 1;
                mp[newName] = 1;
            }
        }

        return ans;
    }
};