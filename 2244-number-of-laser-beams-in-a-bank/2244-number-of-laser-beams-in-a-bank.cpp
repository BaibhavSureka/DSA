class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> cnt;
        for (const string& row : bank) {
            int count = count_if(row.begin(), row.end(), [](char c) { return c == '1'; });
            if(count > 0){
                cnt.push_back(count);
            }
        }

        int ans = 0;
        for(int i = 1 ; i < cnt.size() ; ++i){
            ans += cnt[i-1] * cnt[i];
        }
        return ans;
    }
};