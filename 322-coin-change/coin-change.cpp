class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n + 1, vector<int>(amount + 1, 0));


        //initialisation
         for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j == 0)
                    t[i][j] = 0;
                else if (i == 0)
                    t[i][j] = INT_MAX - 1;
            }
        }
        //first row initialisation
        for(int j =1; j<=amount;j++){
            if(j%coins[0]==0){
                t[1][j]=j/coins[0];
            }
            else{
                t[1][j]=INT_MAX-1;
            }
            
        }  
        // Step 3: DP transition
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        // Step 4: Return the result without ternary operator
        if (t[n][amount] == INT_MAX - 1) {
            return -1;
        } else {
            return t[n][amount];
        }
    

    }
};