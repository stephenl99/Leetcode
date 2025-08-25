class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates[1][0] - coordinates[0][0] == 0) {
            return vert(coordinates);
        }
        double slope = 1.0 * (coordinates[1][1] - coordinates[0][1]) / (1.0 * coordinates[1][0] - coordinates[0][0]);
        for (int i = 2; i < coordinates.size(); i++) {
            if ((coordinates[i][1] - coordinates[0][1]) != slope * (coordinates[i][0] - coordinates[0][0])) {
                return false;
            }
        }
        return true;
    }
    bool vert(vector<vector<int>>& coordinates) {
        for (vector<int> coord : coordinates) {
            if (coord[0] != coordinates[0][0]) {
                return false;
            }
        }
        return true;
    }
};