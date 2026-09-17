class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        long long e = 0;
        long long s = 0;
        for (auto& t : tasks) {
            e = max(e, s + t[1]);
            s += t[0];
        }
        return (int)e;
    }
};