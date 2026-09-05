class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int remaining = income;
        double cost = 0;
        int prev = 0;
        for (vector<int> bracket : brackets) {
            int size = bracket[0] - prev;
            cost += min(size, remaining) * .01 * bracket[1];
            if (size >= remaining) {
                return cost;
            }
            remaining -= size;
            prev = bracket[0];
        }
        return cost;
    }
};