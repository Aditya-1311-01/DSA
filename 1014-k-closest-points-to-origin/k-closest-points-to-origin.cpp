class Solution {
public:
    struct comp{
        bool operator()(pair<double,int>&a, pair<double,int>&b){
            return a.first<b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,comp>pq;
        unordered_map<int,double>mp;

        int n=points.size();
        for(int i=0;i<n;i++){
            double dist=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            mp[i]=dist;
        }
        for(auto it:mp){
            double distance=it.second;
            int index=it.first;

            if(pq.size()<k){
                pq.push({distance,index});
                continue;
            }
            if(distance>pq.top().first)
            continue;

            pq.pop();
            pq.push({distance,index});
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            int a=points[pq.top().second][0];
            int b=points[pq.top().second][1];
            ans.push_back({a,b});
            pq.pop();
        }

        return ans;
        
    }
};