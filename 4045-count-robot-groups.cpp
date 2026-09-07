class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int res = 0, n = speed.size(), p2 = INT_MAX, s2 = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            int p = position[i], s = speed[i];
            if (p2 - p > distance && s <= s2) {
                res += 1;
                s2 = s;
            };
            p2 = p;
        }
        return res;
    }
};