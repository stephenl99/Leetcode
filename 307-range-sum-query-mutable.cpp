class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size() - 1;
        tree.resize((n + 1) * 4 + 1);
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        process(1, index, val, 0, n);
    }

    void process(int node, int index, int val, int left, int right) {
        if (left == right) {
            tree[node] = val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (mid >= index) {
            process(node * 2, index, val, left, mid);
        } else {
            process(node * 2 + 1, index, val, mid + 1, right);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    
    int sumRange(int left, int right) {
        return summation(1, left, right, 0, n);
    }

    int summation(int node, int leftBound, int rightBound, int left, int right) {
        if (left >= leftBound && right <= rightBound) {
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        int sum = 0;
        if (leftBound <= mid) {
            sum += summation(node * 2, leftBound, rightBound, left, mid);
        }
        if (mid < rightBound) {
            sum += summation(node * 2 + 1, leftBound, rightBound, mid + 1, right);
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */