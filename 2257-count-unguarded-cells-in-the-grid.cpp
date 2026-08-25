struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (int x : v)
            h ^= hash<int>{}(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        return h;
    }
};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        unordered_set<vector<int>, VectorHash> wallSet(walls.begin(), walls.end());
        unordered_set<vector<int>, VectorHash> guardSet(guards.begin(), guards.end());
        int count = m * n - guards.size() - walls.size();
        unordered_set<vector<int>, VectorHash> visited;
        for (vector<int> guard : guards) {
            int x = guard[0];
            int y = guard[1];
            int index = x + 1;
            while (index < m && !guardSet.contains({index, y}) && !wallSet.contains({index, y})) {
                visited.insert({index, y});
                index++;
            }

            index = y + 1;
            while (index < n && !guardSet.contains({x, index}) && !wallSet.contains({x, index})) {
                visited.insert({x, index});
                index++;
            }

            index = x - 1;
            while (index >= 0 && !guardSet.contains({index, y}) && !wallSet.contains({index, y})) {
                visited.insert({index, y});
                index--;
            }

            index = y - 1;
            while (index >= 0 && !guardSet.contains({x, index}) && !wallSet.contains({x, index})) {
                visited.insert({x, index});
                index--;
            }
        }
        return count - visited.size();
    }
};