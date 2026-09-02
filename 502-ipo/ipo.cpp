class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>>projects;
        int n=profits.size();
        for(int i=0;i<n;i++){
            projects.push_back({capital[i],profits[i]});
        }

        sort(projects.begin(),projects.end());
        int idx=0;
        priority_queue<int>pq;

        while(k--){
            while(idx<n){
                if(projects[idx][0]>w)
                break;

                pq.push(projects[idx][1]);
                idx++;
            }
            if(pq.empty()) return w;

            w=w+pq.top();
            pq.pop();

        }

        return w;
        
    }
};