class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>>adj(V);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];

            adj[b].push_back(a);
        }

        vector<int>Indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                Indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(Indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();

            for(auto it:adj[node]){
                Indegree[it]--;
                if(Indegree[it]==0)
                q.push(it);
            }
        }
        if(ans.size()!=V) return {};
        return ans;
    }
};