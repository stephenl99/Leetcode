class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int userX = location[0];
        int userY = location[1];
        int finalCount = 0;
        vector<double> locs;
        locs.reserve(2 * points.size());
        for (vector<int>& point : points) {
            double x = point[0] - userX;
            double y = point[1] - userY;
            if (x == 0 && y == 0) {
                finalCount++;
                continue;
            }
            double rad = atan2(y, x);
            double deg = (180.0 / numbers::pi) * rad;
            if (deg < 0) {
                deg += 360.0;
            }
            locs.push_back(deg);

        }
        sort(locs.begin(), locs.end());
        int old = locs.size();
        for (int i = 0; i < old; i++) {
            locs.push_back(locs[i] + 360.0);
        }
        int left = 0;
        int right = 0;
        int maxx = 0;
        while (right < locs.size()) {
            while (right < locs.size() && locs[right] - locs[left] <= angle) {
                right++;
            }
            maxx = max(maxx, right - left);
            left++;
        }
        return maxx + finalCount;
    }
};