class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&a , pair<int,int>&b){
            if(a.first!=b.first)
            return a.first>b.first;

            return a.second>b.second;
        }
    };
    

    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;

       int n=nums.size();
       unordered_map<int,int>freq;
       for(int i=0;i<n;i++){
        freq[nums[i]]++;
       }
        for(auto it:freq){
            int element=it.first;
            int frequency=it.second;

            pair<int,int>curr={frequency,element};

            if(pq.size()<k){
                pq.push(curr);
                continue;
            }

            if(curr.first<pq.top().first){
                continue;
            }

            pq.pop();
            pq.push(curr);
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};