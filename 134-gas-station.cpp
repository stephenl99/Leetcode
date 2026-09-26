class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int candidate = -1;
        int previous_req = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            previous_req = max(0, previous_req + cost[i] - gas[i]);
        }
        for (int i = cost.size() - 1; i >= 0; i--) {
            previous_req = max(0, previous_req + cost[i] - gas[i]);
            if (previous_req == 0) {
                return i;
            }
        }
        return -1;
    }
};