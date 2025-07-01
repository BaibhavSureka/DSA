class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Two 2D vectors to store the current and next states
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        // Traverse days in reverse order
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 1) {
                        curr[buy][cap] = max(
                            -prices[ind] + ahead[0][cap],  // Buy stock
                            0 + ahead[1][cap]             // Skip buying
                        );
                    } else {
                        curr[buy][cap] = max(
                            prices[ind] + ahead[1][cap - 1],  // Sell stock
                            0 + ahead[0][cap]                // Skip selling
                        );
                    }
                }
            }
            // Move current state to "ahead" for the next iteration
            ahead = curr;
        }

        // The answer is in the initial state (day 0, buy = 1, cap = 2)
        return ahead[1][2];
    }
};
