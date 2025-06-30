class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return isSubsetSum(n - 1, target, nums, dp);
    }
    
    bool isSubsetSum(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;              
        if (ind == 0) return nums[0] == target;    

        if (dp[ind][target] != -1) return dp[ind][target]; 
        
        bool notTake = isSubsetSum(ind - 1, target, nums, dp);
        bool take = false;
        if (nums[ind] <= target) {
            take = isSubsetSum(ind - 1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = take || notTake;
    }
};
