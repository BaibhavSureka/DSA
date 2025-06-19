class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        int mini = prices[0];
        for(int i = 1 ; i < prices.size() ; i++){
            int currprofit = prices[i] - mini;
            maxprof = max(currprofit,maxprof);
            mini = min(mini, prices[i]);
        }
        return maxprof;
    }
};
