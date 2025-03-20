class Solution {
public:
    int r;
    int c;
    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        queue<pair<int,int>>q;
        int count = 0;
        //check the char '1' in our grid
        for(int i =0;i<r;i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                    count++;
                    // convert all 1 to 0
                    q.push(make_pair(i,j));
                    grid[i][j]='0';
                    while(!q.empty()){
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        //8 direcctions me check krna hai
                        for(int k =0; k<4; k++){
                            if(valid(new_i+row[k],new_j+col[k])&&grid[new_i+row[k]][new_j+col[k]]=='1'){
                                grid[new_i+row[k]][new_j+col[k]]='0';
                                q.push(make_pair(new_i+row[k],new_j+col[k]));
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};