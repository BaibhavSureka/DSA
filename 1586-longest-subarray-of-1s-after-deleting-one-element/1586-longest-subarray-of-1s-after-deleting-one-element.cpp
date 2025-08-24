class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0 , j = 0 , N = nums.size() , cnt = 0;
        for(; j < N ; j++){
            cnt += nums[j] == 0;
            if(cnt > 1){
                cnt -= nums[i++]==0;
            }
        }
        return j-i-1;
    }
};