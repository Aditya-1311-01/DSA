class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        vector<int> ans;
        int n = tasks.size();

        // Add original index
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }

        // Sort by enqueue time
        sort(tasks.begin(), tasks.end());

        long long timer = 0;
        int i = 0;

        // {processingTime, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        while (i < n || !pq.empty()) {

            // If CPU is idle, jump to next task's enqueue time
            if (pq.empty() && timer < tasks[i][0]) {
                timer = tasks[i][0];
            }

            // Add all available tasks
            while (i < n && tasks[i][0] <= timer) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // Execute task with minimum processing time
            ans.push_back(pq.top().second);

            timer += pq.top().first;

            pq.pop();
        }

        return ans;
    }
};