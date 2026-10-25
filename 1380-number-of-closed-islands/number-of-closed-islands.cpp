class Solution {
public:

    int m,n;
    bool dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || r>=m || c<0 || c>=n)
        return false;

        if(grid[r][c]==1){ // water hai 
            return true;
        }

        grid[r][c]=1; // mark visit kr do

        bool left=dfs(grid,r,c-1);
        bool right=dfs(grid,r,c+1);
        bool down=dfs(grid,r+1,c);
        bool up=dfs(grid,r-1,c);

        return (left && right && down && up);
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)==true){
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
};