class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int distance = 0;
        for ( i = 0; i < n; i++){
            if (colors[i] != colors[0])
                distance = max(distance, i);
            if (colors[i] != colors[n - 1])
                distance = max(distance, n - 1 - i);
        }
        return distance;
    }
};