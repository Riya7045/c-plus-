class Solution {
public:
   void dfs(int row, int col, int drow[], int dcol[], vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[row][col]=1;
        int n = board.size();
        int m = board[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, drow, dcol,vis,board); 
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int drow[4]={-1,1,0,0};
        int dcol[4]={0,0,-1,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traverse first and last row
        for(int j =0;j<m;j++){
            // check for unvisited Os in the boundary rows first row 
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, drow, dcol, vis, board); 
            }
            
            // last row 
            if(!vis[n-1][j] &&board[n-1][j] == 'O') {
                dfs(n-1,j, drow, dcol,vis,board); 
            }
        
        }
        //traverse first column and last column
        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, drow, dcol, vis, board); 
            }
            
            // last column
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, drow, dcol, vis, board); 
            }
        }
        
        // if unvisited O then convert to X
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X'; 
            }
        }
        
    }
};
