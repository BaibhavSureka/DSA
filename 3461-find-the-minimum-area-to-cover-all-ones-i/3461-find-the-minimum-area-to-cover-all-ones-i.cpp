
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = grid.size(), maxRow = -1;
        int minCol = grid[0].size(), maxCol = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (i < minRow) minRow = i;
                    if (i > maxRow) maxRow = i;
                    if (j < minCol) minCol = j;
                    if (j > maxCol) maxCol = j;
                }
            }
        }
        if (maxRow == -1 || maxCol == -1) return 0;
        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;
        return height * width;
    }
};