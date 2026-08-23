class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adj(V);
        vector<int>Indegree(V,0);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                Indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(Indegree[i]==0)
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                Indegree[it]--;
                if(Indegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};