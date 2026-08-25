class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = 5e4;
        vector<int> tree(4 * n);
        set<int> blocks;
        blocks.insert(0);
        blocks.insert(n);
        process(1, 0, n, n, n, tree, blocks);
        vector<bool> ans;
        for (vector<int> query : queries) {
            if (query[0] == 1) {
                auto ptr = blocks.upper_bound(query[1]);
                int next = *ptr;
                int pre = *prev(ptr);
                process(1, 0, n, query[1] - pre, query[1], tree, blocks);
                process(1, 0, n, next - query[1], next, tree, blocks);
                blocks.insert(query[1]);
            } else {
                auto ptr = blocks.upper_bound(query[1]);
                int pre = *prev(ptr);
                if (query[1] - pre >= query[2]) {
                    ans.push_back(true);
                } else {
                    int result = find(1, 0, n, 0, pre, tree, blocks);
                    ans.push_back(result >= query[2] ? true : false);
                }
            }
        }
        return ans;
    }
    int find(int node, int left, int right, int leftBound, int rightBound, vector<int>& tree, set<int>& blocks) {
        if (leftBound <= left && right <= rightBound) {
            return tree[node];
        }
        int mid = left + ((right - left) / 2);
        int res = 0;
        if (leftBound <= mid) {
            res = max(res, find(node * 2, left, mid, leftBound, rightBound, tree, blocks));
        }
        if (rightBound > mid) {
            res = max(res, find(node * 2 + 1, mid + 1, right, leftBound, rightBound, tree, blocks));
        }
        return res;
    }
    void process(int node, int left, int right, int val, int index, vector<int>& tree, set<int>& blocks) {
        if (right == left) {
            tree[node] = val;
            return;
        }
        int mid = left + ((right - left) / 2);
        if (index <= mid) {
            process(node * 2, left, mid, val, index, tree, blocks);
        } else {
            process(node * 2 + 1, mid + 1, right, val, index, tree, blocks);
        }
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
};