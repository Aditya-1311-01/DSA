class Solution {
public:
    int m,n;
    long long dfs(vector<vector<int>>& grid,int row,int col){
        if(row<0 || row>=m || col<0 || col>=n){
            return false;
        }

        if(grid[row][col]==0)
        return 0;

        long long sum=grid[row][col];

        grid[row][col]=0;

        sum+=dfs(grid,row,col-1);
        sum+=dfs(grid,row,col+1);
        sum+=dfs(grid,row-1,col);
        sum+=dfs(grid,row+1,col);

        return sum;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();

        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long sum=dfs(grid,i,j);

                    if(sum%k==0)
                    count++;
                }
            }
        }

        return count;
        
    }
};