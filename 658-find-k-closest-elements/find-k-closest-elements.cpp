class Solution {
public:

    struct comp {
        bool operator()(const pair<int,int>& a,
                        const pair<int,int>& b) {

            if(a.first != b.first)
                return a.first < b.first;

            return a.second < b.second;
        }
    };

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            comp
        > pq;

        for(int element : arr) {

            int diff = abs(element - x);

            if(pq.size() < k) {
                pq.push({diff, element});
            }
            else {

                if(diff < pq.top().first) {

                    pq.pop();
                    pq.push({diff, element});
                }
                else if(diff == pq.top().first &&
                        element < pq.top().second) {

                    pq.pop();
                    pq.push({diff, element});
                }
            }
        }

        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};