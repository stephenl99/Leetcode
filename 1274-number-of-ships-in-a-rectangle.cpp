/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int helper(Sea sea, vector<int> bottomLeft, vector<int> topRight) {
        if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1]) {
            return 0;
        }
        int has = sea.hasShips(topRight, bottomLeft);
        if (!has) {
            return 0;
        }
        int count = 0;
        int horizontal_dist = topRight[0] - bottomLeft[0];
        int vertical_dist = topRight[1] - bottomLeft[1];
        int h_mid = bottomLeft[0] + (horizontal_dist / 2);
        int v_mid = bottomLeft[1] + (vertical_dist / 2);

        if (horizontal_dist == 0 && vertical_dist == 0) {
            return 1;
        } else if (horizontal_dist == 0) {
            return helper(sea, {bottomLeft[0], v_mid + 1}, topRight) + 
            helper(sea, bottomLeft, {topRight[0], v_mid});
        } else if (vertical_dist == 0) {
            return helper(sea, {h_mid + 1, bottomLeft[1]}, topRight) + 
            helper(sea, bottomLeft, {h_mid, topRight[1]});
        } else {
            return helper(sea, {h_mid, v_mid + 1}, topRight) + 
            helper(sea, {bottomLeft[0], v_mid}, {h_mid - 1, topRight[1]}) + 
            helper(sea, bottomLeft, {h_mid, v_mid - 1}) + 
            helper(sea, {h_mid + 1, bottomLeft[1]}, {topRight[0], v_mid})
            + helper(sea, {h_mid, v_mid}, {h_mid, v_mid});
        }
    }
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return helper(sea, bottomLeft, topRight);
    }
};