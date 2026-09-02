class Solution {
public:

    struct comp {
        bool operator()(const pair<int,char>& a,
                        const pair<int,char>& b) {

            if(a.first != b.first)
                return a.first < b.first;

            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {

        unordered_map<char,int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        // MAX HEAP
        priority_queue<
            pair<int,char>,
            vector<pair<int,char>>,
            comp
        > pq;

        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        string res = "";

        while(!pq.empty()) {

            pair<int,char> p = pq.top();
            pq.pop();

            // Current character is different
            // from previous character
            if(res.empty() || res.back() != p.second) {

                res += p.second;

                p.first--;

                if(p.first > 0)
                    pq.push(p);
            }

            else {

                // No other character available
                if(pq.empty())
                    return "";

                pair<int,char> p2 = pq.top();
                pq.pop();

                res += p2.second;

                p2.first--;

                if(p2.first > 0)
                    pq.push(p2);

                // Put first character back
                pq.push(p);
            }
        }

        return res;
    }
};