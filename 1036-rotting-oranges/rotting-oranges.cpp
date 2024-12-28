class Solution {
public:
   int row[4] ={-1,1,0,0};
   int col[4] ={0,0,-1,1};
   int r;
   int c;
    bool valid(int i ,int j){
        return (i>=0 && i<r && j>=0 && j<c);}
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        queue<pair<int,int>>q;
        for(int i =0;i<r;i++){
            for(int j =0; j<c; j++){
                if(grid[i][j]==2)
                q.push(make_pair(i,j));
            }
        } 
        
        int timer =0;
        while (!q.empty()){
            
            int cur_patient = q.size();
            bool rotted = false;//track if new oranges are rotted
            while(cur_patient--){
                int i = q.front().first;
                int j =q.front().second;
                q.pop();
                for(int k =0; k<4;k++){
                    if(valid(i+row[k],j+col[k])&&grid[i+row[k]][j+col[k]]==1){
                        grid[i+row[k]][j+col[k]]=2;
                        q.push(make_pair(i+row[k],j+col[k]));
                        rotted = true;
                        
                    }

                }
            }
            if (rotted){
            timer++;}

           
        } 
        

        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                return -1;
                
            }
        }
        return timer;

        
    }
};