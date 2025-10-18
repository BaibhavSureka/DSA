class Solution{
public:
    int maxDistinctElements(vector<int> &nums, int k){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long s = 0;
        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i - 1]){
                s++;
            }
        }
        if(s <= k){
            return n; 
        }
        int res = 0;
        long long prev = nums[0] - k - 1;
        for (int i = 0; i < n; i++){
            long long curr = nums[i];
            long long min_v = curr - k;
            long long max_v = curr + k;
            if (prev + 1 <= max_v)
            {
                prev = max(prev + 1, min_v);
                res++;
            }
        }
        return res;
    }
};
