class Solution {
public:
    
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n= heights[0].size();
        auto valid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>> pq;
               
        result[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();
            int x  = coord.first;
            int y = coord.second;

            if(x==m-1 && y==n-1)
            return diff;

            for(auto &dir: dirs){
                int newx = x+dir[0];
                int newy= y+dir[1];
                if (valid(newx, newy)) {
                    int absdiff =abs(heights[x][y] - heights[newx][newy]);
                    int maxdiff = max(diff,absdiff);
                    if(result[newx][newy]>maxdiff){
                        result[newx][newy]=maxdiff;
                        pq.push({maxdiff,{newx,newy}});
                    }
                }
            }
        }

        return result[m-1][n-1];
        
    }
};