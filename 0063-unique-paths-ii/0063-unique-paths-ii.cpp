class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(m, 0); // to store the number of paths for the previous row

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0); // temp vector for current row
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0; // obstacle present, no path here
                    continue;
                }
                if (i == 0 && j == 0) {
                    temp[j] = 1; // Starting point, 1 way to start
                    continue;
                }

                int up = 0, left = 0;

                if (i > 0) up = prev[j]; // from previous row
                if (j > 0) left = temp[j - 1]; // from the same row, previous column

                temp[j] = up + left; // sum of paths from above and left
            }
            prev = temp; // Update prev row with the current row
        }
        return prev[m - 1]; // Return the result from the last cell of the last row
    }
};
