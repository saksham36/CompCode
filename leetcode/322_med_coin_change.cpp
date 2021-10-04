class Solution {
public:
    int solve(vector<int>& coins, int amount, unordered_map<int, int> &dp){
        // cout<<"In Solve, Amount: "<<amount<< " idx: " << idx<<" Used: "<<used<<endl;
        
        if(dp.find(amount) != dp.end()) return dp[amount];
        
        if(amount==0) return 0; // Valid permutation
        if(amount<0) return -1;
        int res = 0;
        int minimum = -1;
        for(int coin: coins){
            res = solve(coins, amount-coin, dp);
            if(res >= 0){ // if permutation is valid, then check for minimum
                if(minimum == -1 || res+1 < minimum)
                    minimum = res+1;
            }
        }
        dp[amount] = minimum;
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(coins.size() == 0) return -1;
        unordered_map<int, int> dp; // dp[i] represents the fewest number of coins to make up the amount i
        return solve(coins, amount, dp);
    }
};