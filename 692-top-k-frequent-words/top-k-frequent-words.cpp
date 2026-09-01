class Solution {
public:

    struct compare {
        bool operator()(const pair<int,string>& a,
                        const pair<int,string>& b) {

            if(a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mpp;

        // 1. Count frequency
        for(string &word : words) {
            mpp[word]++;
        }

        // 2. Min heap of size k
        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            compare
        > p;

        // 3. Process each unique word
        for(auto &it : mpp) {

            pair<int,string> curr = {
                it.second,
                it.first
            };

            if(p.size() < k) {
                p.push(curr);
            }
            else {

                // curr is better than the worst element
                if(curr.first > p.top().first ||
                   (curr.first == p.top().first &&
                    curr.second < p.top().second)) {

                    p.pop();
                    p.push(curr);
                }
            }
        }

        // 4. Extract
        vector<string> ans;

        while(!p.empty()) {
            ans.push_back(p.top().second);
            p.pop();
        }

        // Heap gives worst -> best
        reverse(ans.begin(), ans.end());

        return ans;
    }
};