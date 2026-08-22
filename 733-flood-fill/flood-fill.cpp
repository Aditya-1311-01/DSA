class Solution {
public:
    void bfs(int row,int col,int initialcol,int color,vector<vector<int>>&image,vector<vector<int>>& ans){
        ans[row][col]=color;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delrow[4]={-1,1,0,0};
            int delcol[4]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==initialcol && ans[nrow][ncol]!=color){
                    ans[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initialcol=image[sr][sc];

        bfs(sr,sc,initialcol,color,image,ans);

        return ans;
    }
};