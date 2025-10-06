class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {{-1, 0},  {0, -1}, {1, 0}, {0, 1}}; 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;

            // If we reach the bottom-right cell, return the time
            if (r == n - 1 && c == n - 1) return time;

            // Explore all 4 directions
            for (auto& dir : directions) {
                int newr = r + dir[0], newc = c + dir[1];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && !visited[newr][newc]) {
                    visited[newr][newc] = 1;
                    pq.push({max(time, grid[newr][newc]), {newr, newc}});
                }
            }
        }
        return -1;
    }
};
