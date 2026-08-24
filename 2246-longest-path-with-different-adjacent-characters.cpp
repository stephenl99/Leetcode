class Solution {
public:
int best = 1;
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, vector<int>> childrenMap;
        vector<int> maxes(s.size(), 1);
        vector<int> remainingChild(s.size());
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] != -1) {
                childrenMap[parent[i]].push_back(i);
                remainingChild[parent[i]]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < parent.size(); i++) {
            if (childrenMap[i].size() == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            priority_queue<int> pq;
            maxes[i] = 1;
            for (int child : childrenMap[i]) {
                if (s[child] != s[i]) {
                    maxes[i] = max(maxes[i], maxes[child] + 1);
                    pq.push(maxes[child]);
                }
            }
            if (pq.size() >= 2) {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                best = max(best, a + b + 1);
            }
            if (parent[i] != -1) {
                remainingChild[parent[i]] -= 1;
                if (remainingChild[parent[i]] == 0) {
                    q.push(parent[i]);
                }
            }
            best = max(best, maxes[i]);
        }
        return best;
    }
};