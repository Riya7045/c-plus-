class Solution {
public:
    int r;
    int c;
    bool valid(int i,int j,vector<vector<int>>& grid){
        return i>=0 && i<r && j>=0 && j<c && grid[i][j]==0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        // If start or end is blocked, return -1
        if (grid[0][0] != 0 || grid[r-1][c-1] != 0) return -1;

        //8 poosible directions
        int row[8] = {-1,-1,-1,1,1,1,0, 0};
        int col[8] = {-1,0,1,-1,0,1,-1,1};
        queue<pair<int,int>>q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark as visited by setting to 1
        int count = 1; //start with step count 1
        
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                auto [x, y] = q.front();
                q.pop();

                // If we reach the bottom-right cell, return the steps taken
                if (x == r-1 && y == c-1) return count;

            
                //8 direcctions me check krna hai
                for(int k =0; k<8; k++){
                    int new_x = x+row[k];
                    int new_y = y+col[k];
                    if(valid(new_x,new_y,grid)){
                        grid[new_x][new_y]=1; //mark as visited
                        q.push({new_x, new_y});    
                        
                    }
                }
            }
            count++;
        }
        return -1; //no valid path
    }
    
};