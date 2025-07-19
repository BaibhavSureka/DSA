class Solution {
public:
    vector<int> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        priority_queue<pair<int, pair<int, int>>> maxHeap; // {sum, {i, j}}
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = a[i] + b[j];
                maxHeap.push({sum, {i, j}});
                if (maxHeap.size() > k) maxHeap.pop(); // keep k smallest only
            }
        }
        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> res = mat[0];
        for (int i = 1; i < mat.size(); ++i) {
            res = kSmallestPairs(res, mat[i], k);
        }
        return res[k-1];
    }
};
