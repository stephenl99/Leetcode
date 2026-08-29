class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> parents(n);
        unordered_map<int, vector<int>> children;
        vector<int> timeToStart(n);
        for (vector<int> relation : relations) {
            parents[relation[1] - 1]++;
            children[relation[0] - 1].push_back(relation[1] - 1);
        }
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == 0) {
                q.push(pair(i, 0));
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int child : children[p.first]) {
                parents[child]--;
                timeToStart[child] = max(timeToStart[child], p.second + time[p.first]);
                if (parents[child] == 0) {
                    q.push(pair(child, timeToStart[child]));
                }
            }
            count = max(count, p.second + time[p.first]);
        }
        return count;
    }
};