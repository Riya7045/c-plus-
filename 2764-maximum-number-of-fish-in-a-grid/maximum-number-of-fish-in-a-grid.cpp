class Solution {
public:
    int r;
    int c;
    int row[4]={1,-1,0,0};
    int col[4]={0,0,1,-1};

    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<int,int>>q;
        int maxfish = 0;
        for(int i =0; i<r; i++){
            for(int j =0; j<c; j++){
                if(grid[i][j]>0){
                   int fishcount = 0; 
                   q.push(make_pair(i,j));
                   fishcount+=grid[i][j];
                   grid[i][j]=0;

                   while(!q.empty()){
                    int new_i = q.front().first;
                    int new_j = q.front().second;

                    q.pop();
                    //For each of the 4 possible neighbors:

                    for(int k =0; k<4; k++){
                        if(valid(new_i+row[k],new_j+col[k])&&grid[new_i+row[k]][new_j+col[k]]>0){
                            fishcount+=grid[new_i+row[k]][new_j+col[k]];

                            grid[new_i+row[k]][new_j+col[k]]=0;
                            q.push(make_pair(new_i+row[k],new_j+col[k]));
                            
                        }
                    }
                   }
                   maxfish =max(fishcount,maxfish);
                }
            }
        }
        return maxfish;

    }
};