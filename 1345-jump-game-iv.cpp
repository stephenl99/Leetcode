class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]].push_back(i);
        }
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int count = 0;
        visited.insert(0);
        while (!q.empty()) {
            pair curr = q.front();
            q.pop();
            if (curr.first == arr.size() - 1) {
                return curr.second;
            }
            vector<int>& next = map[arr[curr.first]];
            next.push_back(curr.first + 1);
            next.push_back(curr.first - 1);
            for (int n : next) {
                if (n >= 0 && n < arr.size() && !visited.contains(n)) {
                    q.push(make_pair(n, curr.second + 1));
                    visited.insert(n);
                }
            }
            next.clear();
        }
        return arr.size() - 1;
    }
};