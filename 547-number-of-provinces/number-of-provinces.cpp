class Solution {
public:

    void DFS(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=1;

        for(int j=0;j<adj[node].size();j++){
            if(!vis[adj[node][j]])
            DFS(adj[node][j],adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V=isConnected.size();

        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>vis(V,0);
        int count=0;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                DFS(i,adj,vis);
            }
        }

        return count;
        
        
    }
};