class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<priority_queue<int, vector<int>, greater<int>>> neighbors(vals.size());
        for (vector<int> edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (vals[a] > 0) {
                neighbors[b].push(vals[a]);
                while (neighbors[b].size() > k) {
                    neighbors[b].pop();
                }
            }
            if (vals[b] > 0) {
                neighbors[a].push(vals[b]);
                while (neighbors[a].size() > k) {
                    neighbors[a].pop();
                }
            }
        }
        int maxx = vals[0];
        for (int i = 0; i < vals.size(); i++) {
            int curr = vals[i];
            while (!neighbors[i].empty()) {
                curr += neighbors[i].top();
                neighbors[i].pop();
            }
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};