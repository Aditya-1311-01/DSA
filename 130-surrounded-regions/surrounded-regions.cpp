class Solution {
public:

    int delrow[4] = {1, -1, 0, 0};
    int delcol[4] = {0, 0, 1, -1};

    void dfs(int row, int col,
             vector<vector<int>>& visited,
             vector<vector<char>>& board) {

        visited[row][col] = 1;

        int m = board.size();
        int n = board[0].size();

        for(int k = 0; k < 4; k++) {

            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               visited[nrow][ncol] == 0 &&
               board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, visited, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(
            m, vector<int>(n, 0)
        );

        // First and last row
        for(int j = 0; j < n; j++) {

            if(!visited[0][j] &&
               board[0][j] == 'O') {

                dfs(0, j, visited, board);
            }

            if(!visited[m-1][j] &&
               board[m-1][j] == 'O') {

                dfs(m-1, j, visited, board);
            }
        }

        // First and last column
        for(int i = 0; i < m; i++) {

            if(!visited[i][0] &&
               board[i][0] == 'O') {

                dfs(i, 0, visited, board);
            }

            if(!visited[i][n-1] &&
               board[i][n-1] == 'O') {

                dfs(i, n-1, visited, board);
            }
        }

        // Convert surrounded O to X
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(visited[i][j] == 0 &&
                   board[i][j] == 'O') {

                    board[i][j] = 'X';
                }
            }
        }
    }
};